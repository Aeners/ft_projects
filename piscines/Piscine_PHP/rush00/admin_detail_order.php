<?php
	session_start();
	include_once 'functions.php';
	$link = connect_to_database();
	if (mysqli_num_rows(mysqli_query($link, "SELECT login FROM users WHERE login = '" . $_SESSION['loggued_on_user'] . "' AND admin = 'yes'")) == 0)
		header('Location: index.php?err_animation=Vous n\'avez pas les droits d\'administrateur');
?>

<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<link rel="stylesheet" type="text/css" href="style.css">
	<title>Page administrateur - Gestion Commandes</title>
</head>
<body>
<?php
	include 'includes/header_admin.php';
	$result = mysqli_query($link, "SELECT * FROM cart WHERE order_confirmed = 'yes' AND login = '" . mysqli_real_escape_string($link, $_POST['login']) . "' AND order_date = '" . mysqli_real_escape_string($link, $_POST['order_date']) . "';");
?>
	<div style="width: 1000px; height:auto; margin: 20px auto;display: flex;flex-direction: column; text-align: left;">
	<h1>Detail de la commande de <?= $_POST['login'] ?> le <?= $_POST['order_date'] ?></h1>
<?php
	while ($row = mysqli_fetch_array($result, MYSQLI_ASSOC))
	{
		$result_product = mysqli_query($link, "SELECT * FROM products WHERE id_product = '" . $row['id_product'] . "';");
		$row_product = mysqli_fetch_array($result_product, MYSQLI_ASSOC);
?>
		<div style="width: 100%; height: 140px;display:flex; align-content:center; align-items:center;background-color: #E8E7E8; justify-content: space-around;margin-bottom: 15px;">
			<img width="80px" src="<?= $row_product['img_url']; ?>">
			<span><?= $row_product['title']; ?></span>
			<span>Quantité<br /><?= $row['quantity']; ?><br /></span>
			<span>Prix unitaire<br /><?= $row['product_price']; ?>€</span>
			<span style="margin-left: 20px;" id="total">Total <br /><br /><b><?= $row['sub_total']; ?>€</b></span>
		</div>
<?php
	}
?>
<?php
	$total_panier = mysqli_query($link, "SELECT SUM(sub_total) FROM cart WHERE order_confirmed = 'yes' AND login = '" . mysqli_real_escape_string($link, $_POST['login']) . "' AND order_date = '" . mysqli_real_escape_string($link, $_POST['order_date']) . "';");
	$total = mysqli_fetch_array($total_panier, MYSQLI_ASSOC);
?>
	<div style="margin-bottom: 20px;"><span style="font-size: 15px;"><b>TOTAL PANIER :</b><br /><span style="font-size: 20px"><?= $total['SUM(sub_total)'] ?>€</span></span></div>
		<div style="text-align: right;">
		<button class="button" style="width: 200px;margin-right: 50px;" onclick="myFunction()">Print this page</button>
		<script>
		function myFunction() {
		    window.print();
		}
		</script>
	</div>
	</div>

</body>
</html>