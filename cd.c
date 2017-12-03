/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalyvod <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:54:21 by vpalyvod          #+#    #+#             */
/*   Updated: 2017/07/06 19:57:47 by vpalyvod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_with_var_cycle2(int i, int j, char **env)
{
	int	len;
	int	p;

	while (env[i][j] != '=')
		j++;
	len = j;
	while (env[i][len])
		++len;
	if (set_env.tmp_val != NULL)
		free(set_env.tmp_val);
	set_env.tmp_val = (char*)malloc(sizeof(char) * (len + 1));
	p = 0;
	while (env[i][j])
	{
		set_env.tmp_val[p] = env[i][++j];
		p++;
	}
}

void	check_error_var(int check)
{
	if (check == 0)
	{
		ft_putstr("Error");
		ft_putstr("\n");
		;
	}
}

void	cd_with_var_cycle(char **env, int check)
{
	int		i;
	int		j;
	char	**spl_words;

	i = 0;
	j = 0;
	while (env[i])
	{
		spl_words = ft_strsplit(env[i], '=');
		if (ft_strcmp(spl_words[0], set_env.tmp_var) == 0)
		{
			cd_with_var_cycle2(i, j, env);
			check = 1;
			ft_strdel_mass(spl_words);
			break ;
		}
		ft_strdel_mass(spl_words);
		i++;
	}
	check_error_var(check);
}

void	cd_with_variable(char **env, char *line, char **mass)
{
	int	check;

	var_without_dol(line);
	if (env_strcmp(mass[1], set_env.tmp_var) == 0)
	{
		check = 0;
		cd_with_var_cycle(env, check);
		if (!chdir(set_env.tmp_val))
		{
			print_oldpwd(env);
			print_newpwd(env);
			;
		}
		else
			cd_errors(set_env.tmp_val);
	}
}

void	cd_command(char **env, char *line)
{
	char **mass;

	mass = ft_split(line);
	if (mass[1] == NULL)
		cd_if_mass_1_null(env);
	else if (mass[1][0] != '$' && mass[1][0] != '-' && mass[1][0] != '~')
		cd_simple_input(env, mass);
	else if (mass[1][0] == '~')
		cd_tilde_sign(env, mass);
	else if (mass[1][0] == '-')
		cd_minus_sign(env);
	else
		cd_with_variable(env, line, mass);
	ft_strdel_mass(mass);
}
