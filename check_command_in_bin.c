/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command_in_bin.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalyvod <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:55:14 by vpalyvod          #+#    #+#             */
/*   Updated: 2017/07/06 20:04:31 by vpalyvod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_correct_comm_2(char **env)
{
	ft_strdel(&comm.word);
	comm.path = ft_strdup(env[comm.i] + 5);
	comm.spl_words = ft_strsplit(comm.path, ':');
	comm.pars_str = ft_strdup(comm.spl_words[0]);
	comm.copy = ft_strdup(comm.pars_str);
	comm.i = 0;
	comm.j = 0;
	if (comm.mass[0][0] != '/')
	{
		while (comm.spl_words[comm.i])
		{
			if (comm_if())
				break ;
		}
	}
	else
		check_comm_cycle_else();
	comm_free();
}

void	check_correct_comm_cont(char **env)
{
	comm.correct = 0;
	comm.count = 0;
	comm.i = 0;
	while (env[comm.i])
	{
		comm.spl_words = ft_strsplit(env[comm.i], '=');
		if (ft_strcmp(comm.spl_words[0], "PATH") == 0)
		{
			comm.correct = 1;
			ft_strdel_mass(comm.spl_words);
			break ;
		}
		ft_strdel_mass(comm.spl_words);
		comm.i++;
	}
}

void	continue1(void)
{
	without_path.slash = 1;
	ft_strdel_mass(comm.mass);
}

void	correct_delete_mass(void)
{
	ft_strdel(&comm.word);
	ft_strdel_mass(comm.mass);
}

int		check_correct_comm(char *line, char **env)
{
	check_correct_comm_cont(env);
	comm.mass = ft_split(line);
	if (comm.mass[0][0] == '/')
	{
		continue1();
		return (0);
	}
	comm.word = words_first(line);
	if (comm.correct == 0)
	{
		printf("Command not found: %s\n", comm.word);
		correct_delete_mass();
		return (1);
	}
	check_correct_comm_2(env);
	if (comm.not_found == 1)
	{
		comm.word = words_first(line);
		printf("Command not found: %s\n", comm.word);
		free(comm.word);
		return (1);
	}
	free(comm.word);
	return (0);
}
