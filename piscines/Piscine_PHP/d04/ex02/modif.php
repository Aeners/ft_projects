<?php
function		checker($get_var, $login, $oldpw)
{
	$i = 0;

	while ($get_var[$i] != NULL)
	{
		if ($get_var[$i]['login'] == $login && $get_var[$i]['passwd'] == $oldpw)
			return (true);
		$i++;
	}
	return (false);
}
if ($_POST['submit'] == "OK" && $_POST['login'] && $_POST['oldpw'] && $_POST['newpw'])
{
	$get_var = unserialize(file_get_contents("../private/passwd"));
	$oldpw = hash('sha512', $_POST['oldpw']);
	if (!(checker($get_var, $_POST['login'], $oldpw)))
		echo "ERROR\n";
	else
	{
		$i = 0;
		while ($get_var[$i] != NULL)
		{
			if ($get_var[$i]['login'] == $_POST['login'])
			{
				$get_var[$i]['passwd'] = hash('sha512', $_POST['newpw']);
				break ;
			}
			$i++;
		}
		file_put_contents("../private/passwd", serialize($get_var));
		echo "OK\n";
	}
}
else
	echo "ERROR\n";
?>