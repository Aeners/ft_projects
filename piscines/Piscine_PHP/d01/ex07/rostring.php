#!/usr/bin/php
<?php
$argv[1] = preg_replace('/\s+/', ' ', $argv[1]);
$tab = explode(' ', $argv[1]);
$i = 1;
while ($tab[$i])
{
	echo $tab[$i]." ";
	$i++;
}
echo $tab[0]."\n";
?>