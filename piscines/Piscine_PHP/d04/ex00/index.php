<?php
session_start();
if ($_GET['login'] && $_GET['passwd'] && $_GET['submit'] == "OK" && $_GET['submit'] !== false && $_GET['login'] !== false && $_GET['passwd'] !== false)
{
	$_SESSION['login'] = $_GET['login'];
	$_SESSION['passwd'] = $_GET['passwd'];
}
?>
<!DOCTYPE html>
<html>
<head><title>Formulaire d'identification</title></head>
<body>
<form action="index.php" method="get">
	Identifiant: <input type="text" name="login" value="<?php echo $_SESSION['login']; ?>">
	<br />
	Mot de passe: <input type="password" name="passwd" value="<?php echo $_SESSION['passwd']; ?>">
	<br />
	<input type="submit" name="submit" value="OK">
</form>
</body>
</html>