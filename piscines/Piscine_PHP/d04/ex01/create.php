<?php

function		checker($get_var, $str)
{
	$i = 0;
	while ($get_var[$i] != NULL)
	{
		if ($get_var[$i]['login'] == $str)
			return (false);
		$i++;
	}
	return (true);
}

if ($_POST['login'] && $_POST['passwd'] && $_POST['submit'] && $_POST['submit'] == "OK")
{
	if (!(file_exists("../private")))
		mkdir("../private", 0777);
	else
		$get_var = unserialize(file_get_contents("../private/passwd"));
	if (!(checker($get_var, $_POST['login'])))
		echo "ERROR\n";
	else
	{
		$get_var[] = ['login'=>$_POST['login'], 'passwd'=>hash('sha512', $_POST['passwd'])];
		file_put_contents("../private/passwd", serialize($get_var));
		echo "OK\n";
	}
}
else
	echo "ERROR\n";
?>