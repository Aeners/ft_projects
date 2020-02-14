<?php
	session_start();
	if ($_SESSION['loggued_on_user'] !== false)
		$_SESSION['loggued_on_user'] = "";
	header('location: index.php?animation=Vous vous êtes bien déconnecté');
?>