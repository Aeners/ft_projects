#!/usr/bin/php
<?php
unset($argv[0]);
$str = implode(' ', $argv);
$str = explode(' ', $str);
sort($str);
foreach ($str as $elem)
	echo $elem."\n";
?>