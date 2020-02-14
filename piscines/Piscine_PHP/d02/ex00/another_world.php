#!/usr/bin/php
<?php
if ($argc != 2)
	return (false);
$book = trim($argv[1]);
$book = preg_replace('/[\s\t]+/', " ", $book);
echo $book."\n";
?>