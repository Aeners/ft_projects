#!/usr/bin/php
<?php
echo "Entrer un nombre: ";
while (1)
{
	if ($input = fgets(STDIN))
	{
			$input = rtrim($input);
		if (is_numeric($input))
		{
			if ($input % 2 == 0)
				echo "Le chiffre $input est Pair\n";
			else
				echo "Le chiffre $input est Impair\n";
		}
		else
			echo "'$input' n'est pas un chiffre\n";
		echo "Entrer un nombre: ";
	}
	else
	{
		echo "\n";
		return ;
	}
}
?>