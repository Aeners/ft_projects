<?php
	session_start();
	include_once 'functions.php';
	$link = connect_to_database();
	if (mysqli_num_rows(mysqli_query($link, "SELECT login FROM users WHERE login = '" . $_SESSION['loggued_on_user'] . "' AND admin = 'yes'")) == 0)
		header('Location: index.php?err_animation=Vous n\'avez pas les droits d\'administrateur');
?>
<!-- 
		AJOUT DE PRODUITS - PHP
 -->
<?php
	if ($_POST['submit'] == "Ajouter un produit")
	{
		$query = "INSERT INTO products VALUES (null, '" . mysqli_real_escape_string($link, $_POST['title']) . "', '" . mysqli_real_escape_string($link, $_POST['url']) . "', '" . mysqli_real_escape_string($link, $_POST['price']) . "', 1,'" . mysqli_real_escape_string($link, $_POST['category']) . "', '" . mysqli_real_escape_string($link, $_POST['sub_category']) . "');";
		mysqli_query($link, $query);
	}
?>
<!-- 
		SUPPRESSION DE PRODUITS - PHP
 -->
<?php
	if ($_POST['delete'] == "delete")
	{
		mysqli_query($link, "DELETE FROM products WHERE id_product = '" . (int)$_POST['id'] . "'");
	}
?>

<!-- 
		GESTION DE L'INVENTAIRE
 -->
<?php
	if ($_POST['plus'] == "+")
		mysqli_query($link, "UPDATE products SET inventory = inventory + 1 WHERE id_product = '" . $_POST['id'] . "'");
	if ($_POST['minus'] == "-")
		mysqli_query($link, "UPDATE products SET inventory = inventory - 1 WHERE id_product = '" . $_POST['id'] . "'");
?>

<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<link rel="stylesheet" type="text/css" href="style.css">
	<title>Page administrateur - Gestion produits</title>
</head>
<body>
<?php
	include 'includes/header_admin.php';
	$result = mysqli_query($link, "SELECT * FROM products");
?>
	<div style="width: 1000px; height:auto; margin: 20px auto;display: flex;flex-direction: column; text-align: right;">
	<!-- 
			AJOUT DE PRODUITS
	 -->
	<div style="width: 100%; height: 300px;display:flex; align-content:center; align-items:center;background-color: #E8E7E8; justify-content: space-around;margin-bottom: 15px;">
	<h1 style="text-align: left;">Ajouter un produit</h1>
	<form method="post" action="admin_products.php">
			<span>Nom du produit :&nbsp;<input class="field" type="text" name="title" required="true"></span><br /><br />
			<span>URL de l'image :&nbsp;<input class="field" type="text" name="url" required="true"></span><br /><br />
			<span>Prix :&nbsp;<input class="field" type="number" step=0.01 name="price" required="true"></span><br /><br />
			<span>Categorie :&nbsp;
				<select name="category" style="width: 295px; height: 20px;">
					<option value="homme">homme</option>
					<option value="femme">femme</option>
				</select>
			</span><br /><br />
			<span>Sous-categorie :&nbsp;<input class="field" type="text" name="sub_category" required="true"></span><br /><br />
			<a class="button" href="manage_categories.php">Gestion des catégories</a>
			<input class="button" type="submit" name="submit" value="Ajouter un produit">
	</form>
	</div>
	<!-- 
			LISTING DES PRODUITS
	 -->
<?php
	while ($row = mysqli_fetch_array($result, MYSQLI_ASSOC))
	{
?>
	<form method="post" action="admin_products.php">
		<div style="width: 100%; height: 140px; display:flex; align-content:center; align-items:center;background-color: #E8E7E8; justify-content: space-around;margin-bottom: 15px;">
			<img width="80px" src="<?php echo $row['img_url']; ?>">
			<span><?= $row['title']; ?></span>
			<span>Prix<br /><?= $row['price']; ?>€</span>
			<span>Inventaire<br /><?= $row['inventory']; ?><br />
			<input type="submit" name="minus" value="-" /><input type="submit" name="plus" value="+" /></span>
			<span>Categorie<br /><?= $row['category']; ?></span>
			<span>Sous-categorie<br /><?= $row['sub_category']; ?></span>
			<div><input type="hidden" name="id" value="<?= $row['id_product'] ?>"></div>
			<input type="image" name="delete" value="delete" src="./resources/cross.png" width="15px" height="15px">
		</div>
	</form>
<?php
	}
?>
	</div>
</body>
</html>
<?php
	include 'includes/footer.php';
?>