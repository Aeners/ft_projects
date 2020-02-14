#!/usr/bin/php
<?php
function ft_add($p1, $p2)
{
	return $p1 + $p2;
}
$ft_var = 42;
$ft_str = "World";
//$ft_tab = array("zero", "un", "deux");
$ft_tab = explode(";", "zero;un;deux");
$ft_hash = array("key1" => "val1", "key2" => 1 + 41);
//echo "$ft_var\n$ft_str";
$ft_hash[key1] = "00";
/*$result = "21" + "21";
echo "$result\n";
echo $ft_hash["key1"]."\n";
echo "$ft_tab\n\n";*/
print_r($ft_tab);
//echo ft_add("36", "6");
if ($ft_tab[1] == un)
	echo "OK\n";
else
	echo "KO\n";
echo "$argc\n";
print_r ($argv);
foreach ($ft_tab as $elem)
{
	echo $elem."\n";
}
?>