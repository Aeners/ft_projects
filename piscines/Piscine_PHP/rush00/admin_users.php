<?php
	session_start();
	include_once 'functions.php';
	$link = connect_to_database();
	if (mysqli_num_rows(mysqli_query($link, "SELECT login FROM users WHERE login = '" . $_SESSION['loggued_on_user'] . "' AND admin = 'yes'")) == 0)
		header('Location: index.php?err_animation=Vous n\'avez pas les droits d\'administrateur');
	include_once 'includes/header_admin.php';
	if ($_POST['submit'] == "delete")
	{
		$id = $_POST['id'];
		mysqli_query($link, "DELETE FROM users WHERE id_user = '$id'");
		echo '<div id="success">Compte bien supprimé</div>';
	}
	if ($_POST['submit'] == "edit")
	{
		$password = hash('sha512', $_POST['password']);
		if (mysqli_query($link, "UPDATE users SET login = '" . mysqli_real_escape_string($link, $_POST['login']) . "' WHERE id_user = '" . mysqli_real_escape_string($link, $_POST['id']) . "'"))
		{
			mysqli_query($link, "UPDATE users SET email = '". mysqli_real_escape_string($link, $_POST['email']) . "' WHERE id_user = '" . mysqli_real_escape_string($link, $_POST['id']) . "'");
			mysqli_query($link, "UPDATE users SET password = '$password' WHERE id_user = '" . mysqli_real_escape_string($link, $_POST['id']) . "'");
			mysqli_query($link, "UPDATE users SET secret_answer = '" . mysqli_real_escape_string($link, $_POST['secret_answer']) . "' WHERE id_user = '" . mysqli_real_escape_string($link, $_POST['id']) . "'");
			mysqli_query($link, "UPDATE users SET admin = '" . mysqli_real_escape_string($link, $_POST['admin']) . "' WHERE id_user = '" . mysqli_real_escape_string($link, $_POST['id']) . "'");
			echo '<div id="success">Données mises a jour</div>';
		}
		else
			echo '<div id="error">Database issue</div>';
	}
		
?>
<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<link rel="stylesheet" type="text/css" href="style.css">
	<title></title>
</head>
<body>
	<h1 style="text-align: center;">
		GESTION UTILISATEUR
	</h1>
	<div id="user_list">
		<?php
			$result = mysqli_query($link, "SELECT id_user, login, email, password, secret_answer, admin FROM users");
			?>
			<table id="users_table">
				<th class="data">Modifications</th>
				<th class="data">Login</th>
				<th class="data">E_mail</th>
				<th class="data">Mot de passe</th>
				<th class="data">Réponse secrète</th>
				<th class="data">Administrateur</th>
			<?php
			while ($row = mysqli_fetch_array($result, MYSQLI_ASSOC))
			{
				$_SESSION['login'] = $row['login'];
				?>
				<tr>
					<td class="data">
						<form method="post" action="admin_users.php">
							<?php
							if ($row['admin'] == 'no')
							{
								?>
								<input style="margin-left: 5px; margin-top: 7px;" type="image" name="submit" value="delete" src="./resources/cross.png" width="15px" height="15px">
							<?php }?>
							<input style="margin-left: 25px; margin-bottom: 7px;" type="submit" name="submit" value="edit">
							</td>
							<input type="hidden" name="id" value="<?= $row['id_user'];?>">
							<td class="data"><input type="text" name="login" value="<?= $row['login'];?>"></td>
							<td class="data"><input type="text" name="email" value="<?= $row['email'];?>"></td>
							<td class="data"><input type="text" name="password" value="<?= $row['password'];?>"></td>
							<td class="data"><input type="text" name="secret_answer" value="<?= $row['secret_answer'];?>"></td>
							<td class="data"><input type="text" name="admin" value="<?= $row['admin'];?>"></td>
						</form>
					</tr>
				<br><?php
			}
		?>
		</table>
	</div>
</body>
</html>
<?=	include 'includes/footer.php';?>