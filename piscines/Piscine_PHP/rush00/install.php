<?php
session_start();
$_SESSION['database'] = "on";
$link = mysqli_connect("localhost", "root", "root", "", "8080");
if (mysqli_connect_errno())
	echo "Failed to connect to MySQL : " . mysqli_connect_error();
mysqli_query($link, "CREATE DATABASE IF NOT EXISTS db_rush;");

mysqli_query($link, "use db_rush");

mysqli_query($link, "CREATE TABLE IF NOT EXISTS users
(
	id_user INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
	login VARCHAR(32) NOT NULL,
	email VARCHAR(64) NOT NULL,
	password VARCHAR(128) NOT NULL,
	secret_answer VARCHAR(64) NOT NULL,
	admin ENUM('yes','no') DEFAULT 'no' NOT NULL
);");

mysqli_query($link, "CREATE TABLE IF NOT EXISTS cart
(
	id INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
	id_cookie VARCHAR(64) NOT NULL,
	login VARCHAR(32),
	id_product INT NOT NULL,
	product_price DECIMAL(10, 2) NOT NULL,
	quantity INT DEFAULT 0,
	sub_total DECIMAL(10, 2),
	order_confirmed ENUM('yes', 'no') DEFAULT 'no' NOT NULL,
	order_date DATETIME
);");

mysqli_query($link, "CREATE TABLE IF NOT EXISTS products
(
	id_product INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
	title VARCHAR(64) NOT NULL,
	img_url VARCHAR(512) NOT NULL,
	price DECIMAL(10, 2) NOT NULL,
	inventory INT,
	category VARCHAR(128) NOT NULL,
	sub_category VARCHAR(128)
);");

if (mysqli_num_rows(mysqli_query($link, "SELECT * FROM products")) == 0)
{
	mysqli_query($link, "INSERT INTO products
	VALUES(null,'Nike - Cortez 749','https://images.asos-media.com/products/nike-cortez-749571-100-baskets-en-cuir-blanc/5824376-1-white?$XL$','84.99','10','homme','chaussures'),
(null,'adidas Originals','https://images.asos-media.com/products/adidas-originals-superstar-c77124-baskets-blanc/4600530-1-white?$XL$','94.99','10','homme','chaussures'),
(null,'Nike SB - Stefan Janoski','https://images.asos-media.com/products/nike-sb-stefan-janoski-max-631303-100-baskets-blanc/6418443-1-white?$XL$','109.99','10','homme','chaussures'),
(null,'adidas Originals - Gazelle','https://images.asos-media.com/products/adidas-originals-gazelle-baskets-gris-et-rose-pastel/7287700-1-chalkwhite?$XL$','109.99','10','femme','chaussures'),
(null,'New Balance - 373','https://images.asos-media.com/products/new-balance-373-baskets-noir/7350844-1-black?$XL$','79.99','10','femme','chaussures'),
(null,'Trench-coat classique','https://images.asos-media.com/products/asos-trench-coat-classique/7111019-1-stone?$XL$','73.99','10','femme','manteaux'),
(null,'Bomber à fleurs','https://images.asos-media.com/products/river-island-bomber-a-fleurs/7800744-1-red?$XL$','69.99','10','femme','manteaux'),
(null,'Trench évasé','https://images.asos-media.com/products/asos-trench-evase/7111021-1-black?$XL$','73.99','10','femme','manteaux'),
(null,'Hollister - Coupe-vent à capuche - Noir','https://images.asos-media.com/products/hollister-coupe-vent-a-capuche-noir/7808031-1-black?$XL$','64.99','10','homme','manteaux'),
(null,'Veste à capuche zippée','https://images.asos-media.com/products/pullbear-veste-a-capuche-zippee-noir/8061738-1-black?$XL$','23.99','10','homme','manteaux'),
(null,' MA1 - Bomber','https://images.asos-media.com/products/pullbear-ma1-bomber-bleu-marine/7049285-1-navy?$XL$','25.99','10','homme','manteaux'),
(null,'Jean super skinny','https://images.asos-media.com/products/asos-jean-super-skinny-a-delavage-moyen/3422401-1-blue?$XL$','37.99','10','homme','jeans'),
(null,'Skinny délavé clair','https://images.asos-media.com/products/asos-jean-super-skinny-delave-clair/5240244-1-lightblue?$XL$','45.99','10','homme','jeans'),
(null,'Jean super skinny - Bleu foncé','https://images.asos-media.com/products/pullbear-jean-super-skinny-bleu-fonce-delave/8025911-1-darkblue?$XL$','19.99','10','homme','jeans'),
(null,'RIDLEY - Jean skinny ','https://images.asos-media.com/products/asos-ridley-jean-skinny-noir-delave/7753457-1-black?$XL$','33.99','10','femme','jeans'),
(null,'Lisbon - Jean skinny','https://images.asos-media.com/products/asos-lisbon-jean-skinny-taille-mi-haute-noir-delave/5989205-1-washedblack?$XL$','10.99','10','femme','jeans'),
(null,'Ridley - Jean skinny','https://images.asos-media.com/products/asos-ridley-jean-skinny-a-taille-haute-noir-pur/5915265-1-black?$XL$','33.99','10','femme','jeans');");
}

if (mysqli_num_rows(mysqli_query($link, "SELECT * FROM users")) == 0)
{
	mysqli_query($link, "INSERT INTO users
	VALUES (null, 'arlecomt', 'arlecomt@student.42.fr', 'fc922396dd7baa77aae45a177dae12deb56345d84f0e17b31eb99485d5555e378d0828ba84a8ef928b30bc8b56a10d7acad46af46d4b57faf7527f5df93c6f2a', 'girard', 'yes'),
	(null, 'apemjean', 'apemjean@student.42.fr', 'ba3253876aed6bc22d4a6ff53d8406c6ad864195ed144ab5c87621b6c233b548baeae6956df346ec8c17f5ea10f35ee3cbc514797ed7ddd3145464e2a0bab413', 'void', 'yes')
	;");
}
?>