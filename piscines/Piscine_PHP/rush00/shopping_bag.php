<?php
	session_start();
	include 'functions.php';
	$link = connect_to_database();

	/*
		1. S'IL EST CONNECTE & IL A UN COOKIE ==> ASSOCIE COOKIE + LOGIN
		2. VIDER LE PANIER
		3. VALIDER LA COMMANDE
	*/
	if (isset($_SESSION['loggued_on_user']) && isset($_COOKIE['cookie_id']))
		mysqli_query($link, "UPDATE cart SET login = '" . $_SESSION['loggued_on_user'] . "' WHERE id_cookie = '" . $_COOKIE['cookie_id'] . "';");
	if ($_POST['submit'] == 'VIDER LE PANIER' && isset($_COOKIE['cookie_id']))
		setcookie('cookie_id', "", time() - 5);
	if ($_POST['submit'] == "VALIDER MA COMMANDE")
	{
		if ($_SESSION['loggued_on_user'] !== false && isset($_SESSION['loggued_on_user']) && !empty($_SESSION['loggued_on_user']))
		{
			$count_available_product = mysqli_num_rows(mysqli_query($link, "SELECT title FROM products INNER JOIN cart ON products.id_product = cart.id_product WHERE products.inventory >= cart.quantity AND cart.id_cookie = '" . $_COOKIE['cookie_id'] . "'"));
			$count_products_in_cart = mysqli_num_rows(mysqli_query($link, "SELECT id FROM cart WHERE id_cookie = '" . $_COOKIE['cookie_id'] . "'"));
			if ($count_available_product != $count_products_in_cart)
			{
				$result = mysqli_query($link, "SELECT * FROM users WHERE login = '" . $_POST['login'] . "'");
				$list_produit = mysqli_query($link, "SELECT title FROM products INNER JOIN cart ON products.id_product = cart.id_product WHERE products.inventory < cart.quantity AND cart.id_cookie = '" . $_COOKIE['cookie_id'] . "'");
				while ($row = mysqli_fetch_array($list_produit, MYSQLI_ASSOC))
					$oos[] = $row[title];
				$oos = implode(" | ", $oos);
				?><div id="error">Les produits suivants sont indisponibles : <?= $oos ?></div><?php
			}
			else
			{
				date_default_timezone_set('UTC');
				$date = date("Y-m-d H:i:s");
				mysqli_query($link, "UPDATE cart SET order_confirmed = 'yes' WHERE id_cookie = '" . $_COOKIE['cookie_id'] . "' AND quantity > 0;");
				mysqli_query($link, "UPDATE cart SET order_date = '" . $date . "' WHERE id_cookie = '" . $_COOKIE['cookie_id'] . "' AND quantity > 0;");
				$result_sql = mysqli_query($link, "SELECT * FROM cart WHERE order_confirmed = 'yes' AND order_date = '" . $date . "' AND login = '" . $_SESSION['loggued_on_user'] . "'");
				while ($row = mysqli_fetch_array($result_sql, MYSQLI_ASSOC))
					mysqli_query($link, "UPDATE products SET inventory = inventory - '" . $row['quantity'] . "' WHERE id_product = '" . $row['id_product'] . "'");
				setcookie('cookie_id', "", time() - 42);
				header('Location: index.php?animation=Merci pour votre confiance');
			}
		}
		else
			echo '<div id="error">Connectez vous avant de procéder au paiement</div>';
	}

	/*
		GESTION DES QUANTITES
	*/
	if ($_POST['plus'] == '+' || $_POST['moins'] == '-')
	{
		if ($_POST['plus'] == '+')
		{
			if (mysqli_num_rows(mysqli_query($link, "SELECT * FROM cart WHERE id_product = '" . (int)$_POST['id'] . "' AND id_cookie = '" . $_COOKIE['cookie_id'] . "'")) != 0)
			{
				mysqli_query($link, "UPDATE cart SET quantity = quantity + 1 WHERE id_product = '" . (int)$_POST['id'] . "' AND id_cookie = '" . $_COOKIE['cookie_id'] . "'");
				mysqli_query($link, "UPDATE cart SET sub_total = quantity * product_price WHERE id_product = '" . (int)$_POST['id'] . "' AND id_cookie = '" . $_COOKIE['cookie_id'] . "'");
			}
		}
		else if ($_POST['moins'] == '-')
		{
			if (mysqli_num_rows(mysqli_query($link, "SELECT * FROM cart WHERE id_product = '" . (int)$_POST['id'] . "' AND id_cookie = '" . $_COOKIE['cookie_id'] . "'")) != 0)
			{
				mysqli_query($link, "UPDATE cart SET quantity = quantity - 1 WHERE id_product = '" . (int)$_POST['id'] . "' AND id_cookie = '" . $_COOKIE['cookie_id'] . "'");
				mysqli_query($link, "UPDATE cart SET sub_total = quantity * product_price WHERE id_product = '" . (int)$_POST['id'] . "' AND id_cookie = '" . $_COOKIE['cookie_id'] . "'");
			}
		}
	}
	if ($_POST['delete'] == 'delete')
	{
			if (mysqli_num_rows(mysqli_query($link, "SELECT * FROM cart WHERE id_product = '" . (int)$_POST['id'] . "' AND id_cookie = '" . $_COOKIE['cookie_id'] . "'")) != 0)
			{
				mysqli_query($link, "UPDATE cart SET quantity = 0 WHERE id_product = '" . (int)$_POST['id'] . "' AND id_cookie = '" . $_COOKIE['cookie_id'] . "'");
				mysqli_query($link, "UPDATE cart SET sub_total = quantity * product_price WHERE id_product = '" . (int)$_POST['id'] . "' AND id_cookie = '" . $_COOKIE['cookie_id'] . "'");
			}
	}
?>
<!DOCTYPE html>
<html>
<head>
	<title>Shopping_bag</title>
	<link rel="stylesheet" type="text/css" href="style.css">
	<meta charset="utf-8">
	<?php
		if ($_POST['submit'] == 'VIDER LE PANIER')
		{
			?><meta http-equiv="refresh" content="0" ><?php 
		}
	?>
</head>
<body>
	<?php
		include 'includes/header.php';
	?>
	<div id="block_list">
		<div id="shopping_list">
			<div style="width: 1000px; height:auto; margin: 20px auto;display: flex;flex-direction: column; text-align: right;">
			<?php
				$result = mysqli_query($link, "SELECT * FROM cart WHERE id_cookie = '" . $_COOKIE['cookie_id'] . "' AND quantity > 0 AND order_confirmed = 'no';");
				if (mysqli_num_rows($result) != 0)
				{
			?>
				<div style="margin-bottom: 20px;">
					<form method="post" action="shopping_bag.php">
						<input class="button" type="submit" name="submit" value="VIDER LE PANIER">
					</form>
				</div>
				<?php
				/*OUVERTURE DU WHILE*/
				while ($row = mysqli_fetch_array($result, MYSQLI_ASSOC))
				{
					$result_product = mysqli_query($link, "SELECT * FROM products WHERE id_product = '" . $row['id_product'] . "';");
					/*Mettre une condition si le produit n'a pas ete supprime du catalogue*/
					$row_product = mysqli_fetch_array($result_product, MYSQLI_ASSOC);
					?>
					<form method="post" action="shopping_bag.php">
						<div style="width: 100%; height: 140px;display:flex; align-content:center; align-items:center;background-color: #E8E7E8; justify-content: space-around;margin-bottom: 15px;">
							<img width="80px" src="<?php echo $row_product['img_url']; ?>">
							<span><?= $row_product['title']; ?></span>
							<span>Quantité<br /><?= $row['quantity']; ?><br />
								<div><input type="hidden" name="id" value="<?= $row['id_product']; ?>"></div>
								<input type="submit" name="moins" value="-"><input type="submit" name="plus" value="+"></span>
							<span>Prix unitaire<br /><?= $row['product_price']; ?>€</span>
							<span style="margin-left: 20px;" id="total">Total <br /><br /><b><?= $row['sub_total']; ?>€</b></span>
							<input type="image" name="delete" value="delete" src="./resources/cross.png" width="15px" height="15px">
						</div>
					</form>
					<?php
				}
				?>
			<?php
				$total_panier = mysqli_query($link, "SELECT SUM(sub_total) FROM cart WHERE id_cookie = '" . $_COOKIE['cookie_id'] . "';");
				$total = mysqli_fetch_array($total_panier, MYSQLI_ASSOC);
			?>
				<div style="margin-bottom: 20px;"><span style="font-size: 15px;"><b>TOTAL PANIER :</b><br /><span style="font-size: 20px"><?= $total['SUM(sub_total)'] ?>€</span></span></div>
				<form method="post" action="">
					<div><input class="button" type="submit" name="submit" value="VALIDER MA COMMANDE"></div>
				</form>
			<?php
				}
				else
				{
					?>
					<div style="width=100%;text-align:center;">
					<span style="font-size:15px;">Votre panier est vide.</span>
					</div>
					<?php
				}
			?>
			</div>
		</div>
	</div>
	<?php include 'includes/footer.php'; ?>
</body>
</html>