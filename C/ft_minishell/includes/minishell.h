/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 15:30:51 by arlecomt          #+#    #+#             */
/*   Updated: 2017/04/29 17:55:46 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define BUILTIN "cd env unsetenv setenv exit echo"

# include "../libft/libft.h"
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdbool.h>

typedef struct		s_data
{
	int				nb_env;
	char			*home;
	char			**path;
	char			*oldpath;
}					t_data;

typedef struct		s_env
{
	char			*var;
	struct s_env	*next;
}					t_env;

void				ft_minishell(t_env *env, t_data pvar);

void				ft_error(int err, char *cmd, char *arg);

void				ft_freetab(char **tab);
void				ft_freelist(t_env *env);

void				get_info(t_data *pvar, t_env *env);
char				*find_cmd(t_data pvar, char *cmd);

void				executions(t_data *pvar, t_env *env, char **cmd);
void				exec_present(char *path, char **cmd, t_env *env);
void				exec_absent(char *path, char **cmd, t_data *pvar,\
					t_env *env);

void				ft_cd(char **cmd, t_data *pvar, t_env *env);
void				ft_exit(char *path, char **cmd, t_data *pvar, t_env *env);
void				ft_echo(char **cmd, t_env *env);
void				ft_env(char **cmd, t_env *env, t_data *pvar);
void				ft_setenv(char **cmd, t_env *env);
void				ft_unsetenv(char **cmd, t_env *env, t_data *pvar);

void				push_env(t_env **lst, char *var);
void				check_env(t_env **lst, char *var);
void				delone_env(t_env **lst, char *var);
char				**fill_envp(t_env *env);
void				print_env(t_env *env);

#endif
