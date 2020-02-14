#!/usr/bin/php
<?php
if ($argc != 2)
{
	echo "Incorrect Parameters\n";
	return (false);
}
$calcul = preg_replace('/[*]/', " * ", $argv[1]);
$calcul = preg_replace('/[-]/', " - ", $calcul);
$calcul = preg_replace('/[+]/', " + ", $calcul);
$calcul = preg_replace('/[\/]/', " / ", $calcul);
$calcul = preg_replace('/[%]/', " % ", $calcul);
$calcul = trim(preg_replace('/\s+/', ' ', $calcul));
$tab = explode(" ", $calcul);
if ((!is_numeric($tab[0]) || !is_numeric($tab[2])) && !preg_match('/[\/+-*%]/', $tab[1]))
{
	echo "Syntax Error\n";
	return (false);
}
$operand_1 = trim($tab[0]);
$operator = trim($tab[1]);
$operand_2 = trim($tab[2]);
if ($operator == "+")
	echo $operand_1 + $operand_2;
else if ($operator == "-")
	echo $operand_1 - $operand_2;
else if ($operator == "*")
	echo $operand_1 * $operand_2;
else if ($operator == "/")
	echo $operand_1 / $operand_2;
else if ($operator == "%")
	echo $operand_1 % $operand_2;
?>