/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalyvod <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:55:39 by vpalyvod          #+#    #+#             */
/*   Updated: 2017/07/06 19:55:41 by vpalyvod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_echo_cycle(int check)
{
	if (check == 0)
		ft_putstr("Error");
}

void	print_echo_else_cycle(char **env)
{
	int		i;
	int		j;
	char	**splitted_mass;
	int		check;

	check = 0;
	i = 0;
	j = 0;
	while (env[i])
	{
		splitted_mass = ft_strsplit(env[i], '=');
		if (ft_strcmp(splitted_mass[0], set_env.tmp_var) == 0)
		{
			while (env[i][j] != '=')
				j++;
			while (env[i][++j])
				ft_putchar(env[i][j]);
			check = 1;
			ft_strdel_mass(splitted_mass);
			break ;
		}
		ft_strdel_mass(splitted_mass);
		i++;
	}
	check_echo_cycle(check);
}

void	print_echo_else(char *line, char **env)
{
	int		i;
	int		j;
	int		check;
	char	**mass;

	j = 0;
	i = 0;
	check = 0;
	mass = ft_split(line);
	if (env_strcmp(mass[1], set_env.tmp_var) == 0)
		print_echo_else_cycle(env);
	ft_strdel_mass(mass);
	if (set_env.tmp_var != NULL)
		free(set_env.tmp_var);
	set_env.tmp_var = NULL;
}

void	print_echo_cycle(char **first)
{
	int	i;
	int	b;

	i = 1;
	b = 1;
	while (first[i] != NULL)
	{
		if (b == 0)
			ft_putstr(" ");
		b = 0;
		ft_putstr(first[i]);
		i++;
	}
	ft_putstr("\n");
}
