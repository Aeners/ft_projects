<?php
function		auth($login, $passwd)
{
	$i = 0;
	$bd = unserialize(file_get_contents("../private/passwd"));
	while ($bd[$i] != NULL)
	{
		if ($bd[$i]['login'] == $login && $bd[$i]['passwd'] == hash('sha512', $passwd))
			return (true);
		$i++;
	}
	return (false);
}
?>