#!/usr/bin/php
<?php
$str = preg_replace('/\s+/', ' ', $argv[1]);
$str = trim($str);
echo "$str\n";
?>