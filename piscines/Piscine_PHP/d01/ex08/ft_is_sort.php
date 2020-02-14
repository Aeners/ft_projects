#!/usr/bin/php
<?php
function ft_is_sort($tab)
{
	$tmp = $tab;
	sort($tmp);
	$i = 0;
	while ($tab[$i])
	{
		if ($tab[$i] != $tmp[$i])
			return (false);
		$i++;
	}
	return (true);
}
?>