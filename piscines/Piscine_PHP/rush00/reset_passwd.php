<?php
	session_start();
	include 'functions.php';
	$link = connect_to_database();
	if ($_POST['submit'] == "Réinitialiser le mot de passe")
	{
		$login = htmlspecialchars($_POST['login']);
		$answer = htmlspecialchars($_POST['secret_query']);
		$passwd = htmlspecialchars($_POST['new_passwd']);
		if (reset_passwd_checker($login, $answer, $passwd, $link) == true)
		{
			$passwd = hash('sha512', $passwd);
			if (mysqli_query($link, "UPDATE users SET password = '" . $passwd . "' WHERE login = '" . $login . "'"))
			{
				$_SESSION['loggued_on_user'] = $_POST['login'];
				header('Location: index.php?animation=Mot de passe réinitialisé');
			}
			else
				echo '<div id="error">Database issue</div>';
		}
	}
?>
<?php include 'includes/header.php';?>
<!DOCTYPE html>
<html>
<head>
	<title>Réinitialisation du mot de passe</title>
	<meta charset="utf-8">
	<link rel="stylesheet" type="text/css" href="style.css"></head>
<body>
	<div class="modif_passwd">
		<form method="post" action="#">
			<span style="font-size: 20px";>Réinitialiser votre mot de passe</span><br /><br />
			<span>Login :</span><br />
			<input class="field" type="text" name="login" required="true";><br /><br />
			<span>Question secrète :</span><br />
			<input class="field" type="text" name="secret_query" placeholder="Nom de jeune fille de votre mère" required="true"><br /><br />
			<span>Nouveau mot de passe :</span><br /><input class="field" type="password" name="new_passwd" required="true"><br />
			<span style="font-size: 11px;">Votre mot de passe doit contenir au moins 6 caractères et inclure un chiffre</span><br />
			<input class="button" type="submit" name="submit" value="Réinitialiser le mot de passe">
		</form>
	</div>
</body>
</html>
<?php include 'includes/footer.php';?>