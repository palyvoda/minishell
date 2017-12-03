/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalyvod <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:57:04 by vpalyvod          #+#    #+#             */
/*   Updated: 2017/07/06 21:28:06 by vpalyvod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		count_setenv(char **mass)
{
	int	i;

	i = 0;
	while (mass[i])
		i++;
	return (i);
}

int		ft_setenv(char *line)
{
    char	**mass;
    
    mass = ft_split(line);
    if (mass[1] != NULL && mass[2] != NULL && count_setenv(mass) == 3)
    {
        if (set_env.tmp_val != NULL)
            free(set_env.tmp_val);
        if (set_env.tmp_var != NULL)
            free(set_env.tmp_var);
        set_env.tmp_var = ft_strdup(mass[1]);
        set_env.tmp_val = ft_strdup(mass[2]);
    }
    else
    {
        if (count_setenv(mass) > 3)
            ft_putstr("Too much arguments\n");
        else if (count_setenv(mass) < 3)
            ft_putstr("Too few arguments\n");
        ft_strdel_mass(mass);
        return (1);
    }
    ft_strdel_mass(mass);
    return (0);
}

void	my_set_env_contin(int check_in, char **env, char *tmp, int i)
{
	if (check_in == 0)
	{
		free(env[i]);
		tmp = ft_strjoin(set_env.tmp_var, "=");
		env[i] = ft_strjoin(tmp, set_env.tmp_val);
	}
	free(tmp);
}

void	my_set_env(char **env)
{
	int		i;
	int		check_in;
	char	*tmp;
	char	**spl_words;

	i = -1;
	check_in = 0;
	while (env[++i])
	{
		spl_words = ft_strsplit(env[i], '=');
		if (ft_strcmp(*spl_words, set_env.tmp_var) == 0)
		{
			free(env[i]);
			tmp = ft_strjoin(set_env.tmp_var, "=");
			env[i] = ft_strjoin(tmp, set_env.tmp_val);
			check_in = 1;
		}
		ft_strdel_mass(spl_words);
	}
	my_set_env_contin(check_in, env, tmp, i);
}
