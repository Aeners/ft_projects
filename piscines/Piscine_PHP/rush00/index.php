<?php
session_start();
include 'functions.php';
$link = connect_to_database();
if (isset($_GET['animation']) && !empty($_GET['animation']))
	echo '<div id="success">' . $_GET['animation'] . '</div>';
if (isset($_GET['err_animation']) && !empty($_GET['err_animation']))
	echo '<div id="error">' . $_GET['err_animation'] . '</div>';
if ($_SESSION['database'] !== "on")
	include_once 'install.php';
?>

<!DOCTYPE html>
<html>
<head>
	<title>42 SHOP: Boutique en Ligne</title>
	<link rel="stylesheet" type="text/css" href="style.css">
	<meta charset="utf-8">
</head>
<body>
	<?php
		include_once 'includes/header.php';
	?>
	<div id="slider">
		<img id="img_slider" src="http://content.asos-media.com/-/media/homepages/mw/2017/mar/20/deskto/jeanshero2003mwdrummer-new.jpg">
	</div>
	<!-- 
		Nouveautes 
	-->
	<?php
		$result = mysqli_query($link, "SELECT * FROM products WHERE inventory > 0 ORDER BY id_product DESC LIMIT 3");
	?>
	<div style="width: 1000px; height: auto; margin: 15px auto;text-align: center;">
		<h1>Nouveautés</h1>
		<?php
		while ($row = mysqli_fetch_array($result, MYSQLI_ASSOC))
		{
		?>
		<div style="display:inline-block;">
			<form method="post" action="products_page.php">
			<div><img width="290px" height="400px" src="<?= $row['img_url']; ?>"></div>
			<div><span><?= $row['title']; ?></span></div>
			<div><span><?= $row['price']; ?>€</span></div>
			<div><input type="hidden" name="id" value="<?= $row['id_product']; ?>"></div>
			<div><input type="hidden" name="price" value="<?= $row['price']; ?>"></div>
			<div><input class="button" type="submit" name="submit" value="En savoir +"></div>
			</form>
		</div>
	<?php
		}
	?>
	</div>
	<?php include_once 'includes/footer.php';?>
</body>
</html>