<?php
include 'functions.php';
$link = connect_to_database();
session_start();
if (isset($_GET['animation']) && !empty($_GET['animation']))
	echo '<div id="error">'.$_GET['animation'].'</div>';
if ($_POST['submit'] == "Valider l'inscription")
{
	if (sub_checker($_POST['login'], $_POST['email'], $_POST['passwd'], $_POST['confirm_passwd'], $_POST['g-recaptcha-response'], $link))
	{
		$login = htmlspecialchars($_POST['login']);
		$email = htmlspecialchars($_POST['email']);
		$password = hash('sha512', htmlspecialchars($_POST['passwd']));
		$answer = htmlspecialchars($_POST['secret_query']);
		if (mysqli_query($link, "INSERT INTO users VALUES (null, '$login', '$email', '$password', '$answer', 'no')") == true)
		{
			$_SESSION['loggued_on_user'] = $_POST['login'];
			header('Location: index.php?animation=Inscription réussie');
		}
		else
			echo '<div id="error">Database issue</div>';
	}
}
if ($_POST['submit'] == "Connexion")
{
	$login = htmlspecialchars($_POST['login']);
	$passwd = htmlspecialchars(hash('sha512', $_POST['passwd']));
	if (log_checker($login, $passwd, $link))
	{
		$_SESSION['loggued_on_user'] = $_POST['login'];
		header('Location: index.php?animation=Connexion réussie, bienvenue');
	}
	else
		echo '<div id="error">Compte introuvable</div>';
}
?>
<!DOCTYPE html>
<html>
<head>
	<title>Page d'inscription / Connexion</title>
	<meta charset="utf-8">
	<link rel="stylesheet" type="text/css" href="style.css">
	<script src='https://www.google.com/recaptcha/api.js'></script>
</head>
<body>
	<?php include 'includes/header.php';?>
	<div id="container">
		<div id="page_title">
			<h1 style="margin-left: 20px;">Inscription | Connexion</h1>
		</div>
		<div id="sign_up_page">
			<h3>&nbsp;&nbsp;Créer un compte</h3>
			<form id="border_right" method="post" action="./sign_in.php">
				<span>&nbsp;&nbsp;Login :</span><br />&nbsp;&nbsp;<input class="field" type="text" name="login" placeholder="username" required="true" /><br />
				<span style="font-size: 11px;">&nbsp;&nbsp;&nbsp;Votre login doit contenir au moins 4 caractères</span><br /><br />
				<span>&nbsp;&nbsp;Adresse email :</span><br/>&nbsp;&nbsp;<input class="field" type="email" name="email" placeholder="exemple@exemple.fr" required="true"><br /><br />
				<span>&nbsp;&nbsp;Mot de passe :</span><br />&nbsp;&nbsp;<input class="field" type="password" name="passwd" placeholder="password" required="true"><br />
				<span style="font-size: 11px;">&nbsp;&nbsp;&nbsp;Votre mot de passe doit contenir au moins 6 caractères et inclure un chiffre</span><br />
				<span>&nbsp;&nbsp;Confirmer mot de passe :</span><br />&nbsp;&nbsp;<input class="field" type="password" name="confirm_passwd" required="true"><br /><br />
				<span>&nbsp;&nbsp;Question secrète : <br /> &nbsp;&nbsp;&nbsp;&nbsp;Quelle est le nom de jeune fille de votre mère ?</span><br />&nbsp;&nbsp;<input class="field" type="text" name="secret_query" placeholder="Servira pour réinitialiser votre mot de passe" required="true"><br />
				<div style="margin: 15px 8px;" class="g-recaptcha" data-sitekey="6LeyKhwUAAAAALGNjPch_2C-g2-Yj3bJXXCXct9W"></div>
				&nbsp;&nbsp;<input class="button" type="submit" name="submit" value="Valider l'inscription">
			</form>
		</div>
		<div id="sign_in_page">
			<h3>&nbsp;&nbsp;Connexion</h3>
			<form method="post" action="#">
				<span>&nbsp;&nbsp;Login :<br />&nbsp;&nbsp;<input class="field" type="text" name="login" required="true" /></span><br /><br />
				<span>&nbsp;&nbsp;Mot de passe :<br />&nbsp;&nbsp;<input class="field" type="password" name="passwd" required="true"></span><br />
				
				<a href="reset_passwd.php" style"text-align: center";><span>&nbsp;&nbsp;Mot de passe oublié ?</span></a><br /><br />
				&nbsp;&nbsp;<input class="button" type="submit" name="submit" value="Connexion">
			</form>
		</div>
	</div>
</body>
</html>