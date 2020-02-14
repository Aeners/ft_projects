<?php
	session_start();
	include_once 'functions.php';
	$link = connect_to_database();
	if (mysqli_num_rows(mysqli_query($link, "SELECT login FROM users WHERE login = '" . $_SESSION['loggued_on_user'] . "' AND admin = 'yes'")) == 0)
		header('Location: index.php?err_animation=Vous n\'avez pas les droits d\'administrateur');
?>

<?php
	if ($_POST['delete'] == 'delete')
		mysqli_query($link, "DELETE FROM cart WHERE order_confirmed = 'yes' AND login = '" . mysqli_real_escape_string($link, $_POST['login']) . "' AND order_date = '" . mysqli_real_escape_string($link, $_POST['order_date']) . "';");
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
?>
	<div style="width: 1000px; height:auto; margin: 20px auto;display: flex;flex-direction: column; text-align: left;">
		<h1>Vue d'ensemble des commandes</h1>
		<table>
			<tr>
				<th style="border:1px solid black; width: 200px; text-align: center;">Date</th>
				<th style="border:1px solid black; width: 200px; text-align: center;">Login</th>
				<th style="border:1px solid black; width: 200px; text-align: center;">Montant total</th>
				<th style="border:1px solid black; width: 200px; text-align: center;">Plus de détail</th>
				<th style="border:1px solid black; width: 100px; text-align: center;">Supp</th>
			</tr>
			<?php
				$result = mysqli_query($link, "SELECT order_date, login, SUM(sub_total) AS total, order_confirmed FROM cart GROUP BY order_date, login, order_confirmed;");
				while ($row = mysqli_fetch_array($result, MYSQLI_ASSOC))
				{
					if ($row[order_confirmed] == 'yes')
					{
			?>
			<tr>
			<form method="post" action="admin_detail_order.php">
				<td style="border:1px solid black; width: 200px; text-align: center;"><?= $row[order_date]; ?></th>
				<td style="border:1px solid black; width: 200px; text-align: center;"><?= $row[login]; ?></th>
				<td style="border:1px solid black; width: 200px; text-align: center;"><?= $row[total]; ?>€</th>
				<div><input type="hidden" name="order_date" value="<?= $row[order_date]; ?>"></div>
				<div><input type="hidden" name="login" value="<?= $row[login]; ?>"></div>
				<td style="border:1px solid black; width: 200px; text-align: center;"><input type="submit" name="submit" value="+ de détails"></th>
			</form>
			<form method="post" action="admin_orders.php">
				<div><input type="hidden" name="order_date" value="<?= $row[order_date]; ?>"></div>
				<div><input type="hidden" name="login" value="<?= $row[login]; ?>"></div>
				<td style="border:1px solid black; width: 50px; text-align: center; margin-top: 2px;"><input type="image" name="delete" value="delete" src="./resources/cross.png" width="15px" height="15px"></th>
			</form>
			</tr>
			<?php
					}
				}
			?>
			</form>
		</table>
	</div>
</body>
</html>