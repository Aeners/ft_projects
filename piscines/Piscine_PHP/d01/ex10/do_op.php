#!/usr/bin/php
<?php
if ($argc != 4)
{
	echo "Incorrect Parameters\n";
	return (false);
}
$operand_1 = trim($argv[1]);
$operator = trim($argv[2]);
$operand_2 = trim($argv[3]);
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