#!/usr/bin/php
<?php
if ($argc != 2)
	return (false);
$text = file($argv[1]);
foreach ($text as $elem) 
{
	if (preg_match('/title="([a-zA-Zäáàâëéèê ]+)/', $elem, $tmp))
	{
		$elem = str_replace("title=\"" . $tmp[1], "title=\"" . strtoupper($tmp[1]), $elem);
	}
	if (preg_match('/<a href=.+?>([a-zA-Zäáàâëéèê ]+)/', $elem, $tmp_2))
	{
		$elem = str_replace(">" . $tmp_2[1] . "<", ">" . strtoupper($tmp_2[1]) . "<", $elem);
	}
	echo $elem;
}
?>