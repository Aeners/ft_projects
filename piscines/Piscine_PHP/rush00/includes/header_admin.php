<!DOCTYPE html>
<html>
<body>
	<div id="header">
		<a href="index.php" title="Accueil"><img id="img_logo_header" title="Bob Shopping" alt="Bob Shopping" src="./resources/no_sense_logo.png"></a>
		<div id="account">
		<?php
			if ($_SESSION['loggued_on_user'] !== false && isset($_SESSION['loggued_on_user']) && !empty($_SESSION['loggued_on_user']))
			{
				$link = mysqli_connect("localhost", "root", "root", "db_rush", "8080");
				if (mysqli_connect_errno())
					echo "Failed to connect to MySQL : " . mysqli_connect_error();
				$login = $_SESSION['loggued_on_user'];
				if (mysqli_num_rows(mysqli_query($link, "SELECT login FROM users WHERE login = '$login' AND admin = 'yes'")) != 0)
				{
					?>
						<a href="admin.php"><span class="welcome">Admin |</span></a>
					<?php
				}
		?>
				<span class="welcome">Bienvenue <?php echo $_SESSION['loggued_on_user'];?> |</span>
				<a href="account.php" class="welcome">My account |</a>
				<a href="log_out.php" class="sign_in">Log out</a>
		<?php
			}
			else
			{
		?>
			<a href="sign_in.php" class="sign_in" title="Signin">Inscription / Connexion </a>
		<?php
			}
		?>
			<a href="shopping_bag.php" title="Shopping_bag">
				<img id="my_shopping_bag" title="Shopping_bag" alt="Shopping_bag" src="resources/shopping_bag.png">
			</a>
		</div>
		<div id="gender">
			<table id="gender_table">
				<tr>
					<td class="categories">
						<a href="admin_users.php">GESTION DES UTILISATEURS</a>
					</td>
					<td class="categories">
						<a href="admin_products.php">GESTION DES PRODUITS</a>
					</td><td class="categories">
						<a href="admin_orders.php">GESTION DES COMMANDES</a>
					</td>
				</tr>
			</table>
		</div>
	</div>
</body>
</html>