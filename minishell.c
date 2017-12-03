/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalyvod <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:55:59 by vpalyvod          #+#    #+#             */
/*   Updated: 2017/07/06 21:28:49 by vpalyvod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		if (env[i] == NULL)
			break ;
		ft_putstr(env[i++]);
		ft_putstr("\n");
	}
}

int		check_space_tabs(char *line)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			check++;
		i++;
	}
	if (check == 0)
		return (1);
	return (0);
}

void	checking_commands(char **env, char *line)
{
	if (ft_strcmp(line, "") == 0)
		;
	else if (check_command(line, "exit"))
		exit(1);
	else if (check_command(line, "echo"))
		print_echo(line, env);
	else if (check_command(line, "cd"))
		cd_command(env, line);
	else if (check_command(line, "env"))
		print_env(env);
	else if (check_command(line, "setenv"))
	{
		if (ft_setenv(line))
			return ;
		my_set_env(env);
	}
	else if (check_command(line, "unsetenv"))
	{
		if (ft_unsetenv(env, line))
			return ;
	}
	else
		check_for_pars(line, env);
}

int		main(int argc, char **argv, char **environ)
{
	char	*line;
	char	**env;

	(void)argc;
	(void)argv;
	set_env.tmp_var = NULL;
	set_env.tmp_val = NULL;
	env = get_env(environ);
	while (1)
	{
		ft_putstr("$> ");
		get_next_line(0, &line);
		signal(SIGINT, siginthandler);
		if (check_space_tabs(line))
		{
			ft_strdel(&line);
			continue;
		}
		checking_commands(env, line);
		ft_strdel(&line);
	}
}
