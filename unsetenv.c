/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalyvod <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:57:12 by vpalyvod          #+#    #+#             */
/*   Updated: 2017/07/06 19:57:15 by vpalyvod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unsetenv_cycle(char **env)
{
	char	**spl_words;
	int		i;

	i = 0;
	while (env[i])
	{
		spl_words = ft_strsplit(env[i], '=');
		if (ft_strcmp(*spl_words, set_env.tmp_var) == 0)
		{
			while (env[i])
			{
				free(env[i]);
				if (env[i + 1] != NULL)
					env[i] = ft_strdup(env[i + 1]);
				else
					env[i] = NULL;
				i++;
			}
			i--;
			env[i] = NULL;
		}
		ft_strdel_mass(spl_words);
		i++;
	}
}

int		ft_unsetenv(char **env, char *line)
{
	char	**mass;

	mass = ft_split(line);
	if (set_env.tmp_var != NULL)
		free(set_env.tmp_var);
	if (count_setenv(mass) != 2)
	{
		set_env.tmp_var = NULL;
		if (count_setenv(mass) > 2)
			ft_putstr("Too much arguments\n");
		else if (count_setenv(mass) < 2)
			ft_putstr("Too few arguments\n");
		ft_strdel_mass(mass);
		return (1);
	}
	set_env.tmp_var = ft_strdup(mass[1]);
	ft_unsetenv_cycle(env);
	if (set_env.tmp_var != NULL)
		free(set_env.tmp_var);
	set_env.tmp_var = NULL;
	ft_strdel_mass(mass);
	return (0);
}
