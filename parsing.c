/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalyvod <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:56:46 by vpalyvod          #+#    #+#             */
/*   Updated: 2017/07/06 19:56:49 by vpalyvod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	comms(char *line, char **env)
{
	comm.mass = ft_split(line);
	comm.i = 0;
	comm.count = 0;
	comm.not_found = 0;
	while (env[comm.i])
	{
		comm.spl_words = ft_strsplit(env[comm.i], '=');
		if (ft_strcmp(comm.spl_words[0], "PATH") == 0)
		{
			ft_strdel_mass(comm.spl_words);
			break ;
		}
		ft_strdel_mass(comm.spl_words);
		comm.i++;
	}
}

void	comms_2(void)
{
	while (comm.spl_words[comm.i])
	{
		if (comm.count > 0)
			comm.pars_str = comm.spl_words[comm.i];
		comm.tmp = ft_strjoin(comm.pars_str, "/");
		comm.p = ft_strjoin(comm.tmp, comm.mass[0]);
		free(comm.tmp);
		if (!access(comm.p, 0) && !access(comm.p, 1))
		{
			comm.not_found = 0;
			break ;
		}
		else
			comm.not_found = 1;
		comm.i++;
		comm.count++;
	}
	ft_strdel_mass(comm.spl_words);
}

void	comm_3(void)
{
	comm.i = 0;
	comm.spl_words = ft_strsplit(comm.path, ':');
	comm.pars_str = (comm.spl_words[0]);
	comm.copy = ft_strdup(comm.pars_str);
	comm.j = 0;
	if (comm.mass[0][0] != '/')
		comms_2();
	else
	{
		comm.p = ft_strdup(comm.mass[0]);
		if (!access(comm.p, 0) && !access(comm.p, 1))
			comm.not_found = 0;
		else
			comm.not_found = 1;
	}
}

void	just_parse_it(pid_t pid, char *line, char **env)
{
	char	**argv;
	char	*word;

	word = words(line);
	argv = malloc(sizeof(char*) * 3);
	comms(line, env);
	if (env[comm.i] != NULL)
		comm.path = ft_strdup(env[comm.i] + 5);
	else
		comm.path = comm.mass[0];
	comm_3();
	argv[0] = comm.p;
	argv[1] = count_words(line) == 1 ? NULL : ft_strdup(word);
	argv[2] = NULL;
	if (comm.not_found == 0)
		execve(argv[0], comm.mass, env);
	else
		printf("Command not found: %s\n", word);
	free(comm.path);
	ft_strdel_mass(argv);
	ft_strdel_mass(comm.mass);
	kill(pid, SIGTERM);
}
