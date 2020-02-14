<?php
	session_start();
	include_once 'functions.php';
	$link = connect_to_database();
	if (mysqli_num_rows(mysqli_query($link, "SELECT login FROM users WHERE login = '" . $_SESSION['loggued_on_user'] . "' AND admin = 'yes'")) == 0)
		header('Location: index.php?err_animation=Vous n\'avez pas les droits d\'administrateur');
?>
<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<link rel="stylesheet" type="text/css" href="style.css">
	<title>Page administrateur</title>
</head>
<body>
<?php
	include 'includes/header_admin.php';
?>
</body>
</html>
<?php
	include 'includes/footer.php';
?>