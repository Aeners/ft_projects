#!/usr/bin/php
<?php
if ($argc == 1)
	return (false);
unset($argv[0]);
$str = implode(' ', $argv);
$str = explode(' ', $str);
foreach ($str as $elem)
{
	if (ctype_alpha($elem))
		$alpha[] = $elem;
	else if (is_numeric($elem))
		$num[] = $elem;
	else
		$other[] = $elem;
}
sort($alpha, SORT_FLAG_CASE | SORT_STRING);
sort($num, SORT_STRING);
sort($other);
$str = array_merge($alpha, $num, $other);
foreach ($str as $elem)
	echo $elem."\n";
?>