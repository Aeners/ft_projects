#!/usr/bin/php
<?php
function	ft_split($str)
{
	$str = rtrim($str);
	$str = preg_replace('/\s+/', ' ', $str);
	$str = explode(" ", $str);
	sort($str);
	return ($str);
}
?>