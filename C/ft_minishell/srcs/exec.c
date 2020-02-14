/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:01:42 by AL                #+#    #+#             */
/*   Updated: 2017/05/13 16:56:36 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		relativ_error(int err, char *cmd)
{
	if (err == -1)
	{
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": command not found", 2);
	}
	else if (err == 0)
	{
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": no such file or directory", 2);
	}
	else if (err == 1)
	{
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": is a directory", 2);
	}
	else if (err == 2)
	{
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": permission denied", 2);
	}
	else if (err == -42)
		ft_putendl_fd("Unknown error", 2);
}

static void		son_exec(char **cmd)
{
	struct stat		stats;

	if (stat(cmd[0], &stats) == 0)
	{
		if (S_IFDIR >> 9 == (stats.st_mode >> 9))
			relativ_error(1, cmd[0]);
		else if (!(stats.st_mode & S_IXUSR))
			relativ_error(2, cmd[0]);
	}
	else
		relativ_error(-42, NULL);
	exit(0);
}

static void		relativ_path(char **cmd, t_env *env)
{
	char			**envp;
	pid_t			pid;

	envp = fill_envp(env);
	if (access(cmd[0], F_OK) == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(cmd[0], cmd, envp) == -1)
				son_exec(cmd);
		}
		else if (pid > 0)
			wait(NULL);
	}
	else
		relativ_error(0, cmd[0]);
	ft_freetab(envp);
}

void			exec_present(char *path, char **cmd, t_env *env)
{
	pid_t			pid;
	char			**envp;

	envp = fill_envp(env);
	pid = fork();
	if (pid == 0)
	{
		execve(path, cmd, envp);
		ft_freetab(cmd);
		exit(0);
	}
	else if (pid > 0)
		wait(NULL);
	ft_freetab(cmd);
	free(path);
	ft_freetab(envp);
}

void			exec_absent(char *path, char **cmd, t_data *pvar, t_env *env)
{
	char		*tmp;

	tmp = NULL;
	if (!ft_strcmp(cmd[0], "cd"))
		ft_cd(cmd, pvar, env);
	else if (!ft_strcmp(cmd[0], "exit"))
		ft_exit(path, cmd, pvar, env);
	else if (!ft_strcmp(cmd[0], "echo"))
		ft_echo(cmd, env);
	else if (!ft_strcmp(cmd[0], "env"))
		ft_env(cmd, env, pvar);
	else if (!ft_strcmp(cmd[0], "setenv"))
		ft_setenv(cmd, env);
	else if (!ft_strcmp(cmd[0], "unsetenv"))
		ft_unsetenv(cmd, env, pvar);
	else if (cmd[0][0] == '/' || (!ft_strcmp("./",\
			(tmp = ft_strsub(cmd[0], 0, 2)))))
		relativ_path(cmd, env);
	else
		ft_error(-1, cmd[0], NULL);
	ft_memdel((void **)&tmp);
	ft_freetab(cmd);
	free(path);
}
