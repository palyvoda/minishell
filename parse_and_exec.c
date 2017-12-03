/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalyvod <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:56:39 by vpalyvod          #+#    #+#             */
/*   Updated: 2017/07/06 19:56:41 by vpalyvod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	path_pars_exec(char *line, char **env)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		just_parse_it(pid, line, env);
	else
	{
		waitpid(pid, &status, 0);
	}
}

void	check_with_slash(char *line)
{
	int		not_found;
	char	*p;
	char	**mass;
	char	*word;

	mass = ft_split(line);
	p = ft_strdup(mass[0]);
	if (!access(p, 0) && !access(p, 1))
		not_found = 0;
	else
		not_found = 1;
	free(p);
	ft_strdel_mass(mass);
	word = words_first(line);
	if (not_found == 1)
		printf("Command not found: %s\n", word);
	free(word);
}

void	check_for_pars(char *line, char **env)
{
	if (check_correct_comm(line, env))
		return ;
	if (without_path.slash == 1)
		check_with_slash(line);
	path_pars_exec(line, env);
	without_path.slash = 0;
}
