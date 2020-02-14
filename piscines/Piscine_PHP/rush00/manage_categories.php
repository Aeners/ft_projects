<?php
	include_once 'functions.php';
	$link = connect_to_database();
	if ($_POST['submit'] == 'Supprimer une catégorie')
	{
		mysqli_query($link, "DELETE FROM products WHERE sub_category = '" . $_POST['sub_category'] . "'");
		echo '<div id=success>Catégorie supprimée</div>';
	}
	$result = mysqli_query($link, "SELECT sub_category FROM products GROUP BY sub_category");
?>
<!DOCTYPE html>
<html>
<head>
	<link rel="stylesheet" type="text/css" href="style.css">
	<meta charset="utf-8">
	<title>Gestion des catégories</title>
</head>
<body>
	<?php
		include_once 'includes/header_admin.php';
	?>
	<div style="width: 1000px; height:auto; margin: 20px auto;display: flex;flex-direction: column; text-align: right;">
	<!-- 
			AJOUT DE PRODUITS
	 -->
	<div style="width: 100%; height: 300px;display:flex; align-content:center; align-items:center;background-color: #E8E7E8; justify-content: space-around;margin-bottom: 15px;">
	<h1 style="text-align: left;">Gestion des catégories</h1>
	<form method="post" action="#">
			<span>Sous-categorie :&nbsp;
				<select name="sub_category" style="width: 295px; height: 20px;">
				<?php
				while ($row = mysqli_fetch_array($result, MYSQLI_ASSOC))
				{
				?>
					<option value="<?= $row['sub_category'];?>"><?= $row['sub_category'];?></option>
				<?php
				}?>
				</select>
			</span><br /><br />
			<input class="button" type="submit" name="submit" value="Supprimer une catégorie">
	</form>
	</div>
</body>
</html>