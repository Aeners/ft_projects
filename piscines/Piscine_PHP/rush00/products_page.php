<?php
	session_start();	
	include 'functions.php';
	$link = connect_to_database();
?>
<?php
	if (isset($_POST['id']) && !isset($_COOKIE['cookie_id']) && $_POST['submit'] == "Ajouter au panier")
	{
		$tmp = uniqid();
		setcookie("cookie_id", $tmp, time() + 84000);
		$_COOKIE['cookie_id'] = $tmp;
	}
	if (isset($_COOKIE['cookie_id']) && isset($_POST['id']) && $_POST['submit'] == "Ajouter au panier") 
	{
		if (mysqli_num_rows(mysqli_query($link, "SELECT * FROM cart WHERE id_product = '" . (int)$_POST['id'] . "' AND id_cookie = '" . $_COOKIE['cookie_id'] . "'")) != 0)
		{
			mysqli_query($link, "UPDATE cart SET quantity = quantity + 1 WHERE id_product = '" . (int)$_POST['id'] . "' AND id_cookie = '" . $_COOKIE['cookie_id'] . "'");
			mysqli_query($link, "UPDATE cart SET sub_total = quantity * product_price WHERE id_product = '" . (int)$_POST['id'] . "' AND id_cookie = '" . $_COOKIE['cookie_id'] . "'");
		}
		else
		{
			$query = "INSERT INTO cart VALUES (null, '" . $_COOKIE['cookie_id'] . "', null, '" . (int)$_POST['id'] . "', '" . (float)$_POST['price'] . "', 1, '" . (float)$_POST['price'] . "', 'no', null);";
			mysqli_query($link, $query);
		}
		$result = mysqli_query($link, "SELECT title FROM products WHERE id_product = '" . (int)$_POST['id'] . "'");
		$title = mysqli_fetch_array($result, MYSQLI_ASSOC);
		?><div id="success">Produit <?= $title['title'] ?> a été ajouté</div><?php
	}
	include 'includes/header.php';
?>
<!DOCTYPE html>
<html>
<head>
	<title>Produits</title>
	<meta charset="utf-8">
	<link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
	<?php
		$get_url = strstr($_SERVER['REQUEST_URI'], '?');
		$new_url_get = "products_page.php" . $get_url;
	?>
	<div id="container_list" style="text-align: right;">
		<form method="get" action="products_page.php">
			<span>Type:</span>
			<select name="filtre" style="margin: 10px;">
			    <option value="tous les produits" <?php if($_GET['filtre'] == "tous les produits" || !isset($_GET['filtre'])) { ?> selected <?php } ?>>Tous les produits</option>
			    <option value="femme" <?php if($_GET['filtre'] == "femme") { ?> selected <?php } ?>>Femme</option>
			    <option value="homme" <?php if($_GET['filtre'] == "homme") { ?> selected <?php } ?>>Homme</option>
			</select>
			<select name="filtre2" style="margin: 10px;">
			<!-- 
				Gestion des sous categories
			 -->
			    <option value="tous les produits" <?php if($_GET['filtre2'] == "tous les produits" || !isset($_GET['filtre2'])) { ?> selected <?php } ?>>Tous les produits</option>
			<?php
			 	$result = mysqli_query($link, "SELECT sub_category FROM products GROUP BY sub_category;");
			 	while ($row = mysqli_fetch_array($result, MYSQLI_ASSOC))
			 	{
			?>
			    	<option value="<?= $row['sub_category'] ?>" <?php if($_GET['filtre2'] == $row['sub_category']) { ?> selected <?php } ?>><?= $row['sub_category'] ?></option>
			<?php
				}
			?>
			</select>
			<input type="submit" name="filtre_ok" value="OK">
		</form>
		<div style="text-align: left;">
		<ul>
			<?php
				if ($_POST['submit'] == "En savoir +")
					$result = mysqli_query($link, "SELECT * FROM products WHERE id_product='" . $_POST['id'] . "' AND inventory > 0");
				else if (($_GET['filtre'] == "tous les produits" || $_GET['filtre'] == null) && ($_GET['filtre2'] == "tous les produits" || $_GET['filtre2'] == null))
					$result = mysqli_query($link, "SELECT * FROM products WHERE inventory > 0");
				else if (($_GET['filtre'] == "tous les produits" || $_GET['filtre'] == null))
					$result = mysqli_query($link, "SELECT * FROM products WHERE sub_category='" . mysqli_real_escape_string($link, $_GET['filtre2']) . "' AND inventory > 0");
				else if (($_GET['filtre2'] == "tous les produits" || $_GET['filtre2'] == null))
					$result = mysqli_query($link, "SELECT * FROM products WHERE category='" . mysqli_real_escape_string($link, $_GET['filtre']) . "' AND inventory > 0");
				else
					$result = mysqli_query($link, "SELECT * FROM products WHERE sub_category='" . mysqli_real_escape_string($link, $_GET['filtre2']) . "' AND category='". mysqli_real_escape_string($link, $_GET['filtre']) ."' AND inventory > 0");
				while ($row = mysqli_fetch_array($result, MYSQLI_ASSOC))
				{
			?>
					<form method="post" action="<?= $new_url_get ?>">
					<li>
						<div style="display:inline-block;">
							<div><img width="290px" height="400px" src="<?= $row['img_url']; ?>"></div>
							<div><span><?= $row['title']; ?></span></div>
							<div><span><?= $row['price']; ?>€</span></div>
							<div><input type="hidden" name="id" value="<?= $row['id_product']; ?>"></div>
							<div><input type="hidden" name="price" value="<?= $row['price']; ?>"></div>
							<div><input class="button" type="submit" name="submit" value="Ajouter au panier"></div>
						</div>
					</li>
					</form>
			<?php 
				}
			?>
		</ul>
		</div>
	</div>
</body>
</html>