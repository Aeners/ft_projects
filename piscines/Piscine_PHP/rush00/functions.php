<?php

function		sub_checker($login, $email, $passwd, $confirm_passwd, $captcha, $link)
{
	if (empty($captcha))
	{
		echo '<div id="error">Captcha non validé</div>';
		return false;
	}
	if (strlen($login) >= 4)
	{
		$result = mysqli_query($link, "SELECT login FROM users WHERE login = '". mysqli_real_escape_string($link, $login) . "'");
		$row = mysqli_fetch_array($result, MYSQLI_ASSOC);
		if ($row['login'] != NULL)
		{
			echo '<div id="error">Login déjà existant</div>';
			return false;
		}
	}
	else
	{
		echo '<div id="error">Login entré trop court</div>';
		return false;
	}
	if (preg_match('/[a-z0-9]+@[a-z0-9]+[.][a-z]+/', $email))
	{
		$result = mysqli_query($link, "SELECT email FROM users WHERE email = '" . mysqli_real_escape_string($link, $email) . "'");
		$row = mysqli_fetch_array($result, MYSQLI_ASSOC);
		if ($row['email'] != NULL)
		{
			echo '<div id="error">Email déjà existant</div>';
			return false;
		}
	}
	else
	{
		echo '<div id="error">Adresse e_mail invalide</div>';
		return false;
	}
	if ($passwd == $confirm_passwd)
	{
		if (passwd_checker($passwd) == false)
		{
			echo '<div id="error">Mot de passe entré invalide</div>';
			return false;
		}
	}
	else
	{
		echo '<div id="error">Mots de passe entrés non-identiques</div>';
		return false;
	}
	return true;
}

function		log_checker($login, $passwd, $link)
{
	$result = mysqli_query($link, "SELECT login, password FROM users WHERE login = '". mysqli_real_escape_string($link, $login) . "'");
	$row = mysqli_fetch_array($result, MYSQLI_ASSOC);
	if ($row['login'] == $login && $row['password'] == $passwd)
		return true;
	else
		return false;
}

function		passwd_checker($passwd)
{
	if (preg_match('/.*[0-9].*/', $passwd))
		if (preg_match('/.{6,}/', $passwd))
			return true;
	return false;
}

function		reset_passwd_checker($login, $answer, $passwd, $link)
{
	$result = mysqli_query($link, "SELECT login, secret_answer FROM users WHERE login = '" . mysqli_real_escape_string($link, $login) . "'");
	$row = mysqli_fetch_array($result, MYSQLI_ASSOC);
	if ($row['login'] != NULL)
	{
		if ($row['secret_answer'] == $answer)
		{
			if (passwd_checker($passwd) == true)
				return true;
			else
			{
				echo '<div id="error">Mot de passe entré invalide</div>';
				return false;
			}
		}
		else
		{
			echo '<div id="error">Mauvaise réponse secrète</div>';
			return false;
		}
	}
	else
	{
		echo '<div od="error">Login introuvable</div>';
		return false;
	}
}

function		new_passwd_checker($login, $old_passwd, $new_passwd, $link)
{
	$result = mysqli_query($link, "SELECT password FROM users WHERE login = '" . mysqli_real_escape_string($link, $login) . "'");
	$row = mysqli_fetch_array($result, MYSQLI_ASSOC);
	if ($row['password'] == $old_passwd)
	{
		if (passwd_checker($new_passwd) == true)
			return true;
		else
		{
			echo '<div id="error">Nouveau mot de passe entré invalide</div>';
			return false;
		}
	}
	else
	{
		echo '<div="error">Ancien mot passe entré invalide</div>';
		return false;
	}
}

function		connect_to_database()
{
	$link = mysqli_connect("localhost", "root", "root", "db_rush", "8080");
	if (mysqli_connect_errno())
		echo "Failed to connect to MySQL : " . mysqli_connect_error();
	return ($link);
}

?>