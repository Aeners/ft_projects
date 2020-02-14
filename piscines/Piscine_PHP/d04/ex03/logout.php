<?php
session_start();
if ($_SESSION['loggued_on_user'] !== false)
	$_SESSION['loggued_on_user'] = "";
?>