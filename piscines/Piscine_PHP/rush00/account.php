<?php
	include 'functions.php';
	session_start();
	$link = connect_to_database();
	if ($_POST['submit'] == "Mettre à jour le mot de passe")
	{
		$old_passwd = hash('sha512', htmlspecialchars($_POST['old_passwd']));
		$new_passwd = htmlspecialchars($_POST['new_passwd']);
		if (new_passwd_checker($_SESSION['loggued_on_user'], $old_passwd, $new_passwd, $link) == true)
		{
			$new_passwd = hash('sha512', $new_passwd);
			if (mysqli_query($link, "UPDATE users SET password = '" . mysqli_real_escape_string($link, $new_passwd) . "' WHERE login = '" . $_SESSION['loggued_on_user'] . "'"))
				header('Location: index.php?animation=Mot de passe actualisé');
			else
				echo '<div id="error">Database issue</div>';
		}
	}
	if ($_POST['submit'] == "SUPPRIMER VOTRE COMPTE")
	{
		mysqli_query($link, "DELETE FROM users WHERE login = '" . $_SESSION['loggued_on_user'] . "'");
		$_SESSION['loggued_on_user'] = "";
		header('Location: index.php?animation=Votre compte a bien été supprimé');
	}
?>
<?php include 'includes/header.php';?>
<!DOCTYPE html>
<html>
<head>
	<title>Account managing</title>
	<meta charset="utf-8">
	<link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
	<h1 style="text-align: center; font-size: 40px;">Gestion de votre compte</h1>
	<div class="modif_passwd">
		<form method="post" action="#">
			<span style="font-size: 20px;">Changer votre mot de passe</span><br /><br />
			<span >Ancien mot de passe:</span><br />
			<input class="field" type="password" name="old_passwd" required="true"><br /><br />
			<span>Nouveau mot de passe:</span><br />
			<input class="field" type="password" name="new_passwd" required="true"><br />
			<span style="font-size: 11px;">Votre mot de passe doit contenir au moins 6 caractères et inclure un chiffre</span><br /><br />
			<input class="button" type="submit" name="submit" value="Mettre à jour le mot de passe">
		</form>
	</div>
	<div class="modif_passwd">
		<form method="post" action="#">
			<input id="erase_account_button" type="submit" name="submit" value="SUPPRIMER VOTRE COMPTE">
		</form>
	</div>
</body>
</html>
<?php include 'includes/footer.php';?>