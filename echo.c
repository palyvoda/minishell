/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalyvod <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:55:32 by vpalyvod          #+#    #+#             */
/*   Updated: 2017/07/06 19:55:34 by vpalyvod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_echo_do(char **env, char *line)
{
	var_without_dol(line);
	print_echo_else(line, env);
	ft_putstr("\n");
}

int		print_echo_check_quote(char *line)
{
	char	*str;
	int		i;
	int		check;

	check = 0;
	i = 0;
	str = ft_strdup(line);
	while (str[i])
	{
		if (str[i] == '"')
			check++;
		i++;
	}
	free(str);
	if (check == 2)
		return (1);
	return (0);
}

void	print_echo_quote(char *line, char **first)
{
	char	*str;
	int		i;
	char	**mass;
	int		b;

	b = 0;
	str = ft_strdup(line);
	mass = ft_split_quotes(str);
	i = 1;
	while (mass[i])
	{
		if (b != 0)
			ft_putstr(" ");
		ft_putstr(mass[i++]);
		b++;
	}
	ft_strdel_mass(mass);
	write(1, "\n", 1);
	free(str);
	ft_strdel_mass(first);
}

void	print_echo(char *line, char **env)
{
	char	**first;

	first = ft_split(line);
	if (first[1] == NULL)
		ft_putstr("\n");
	else if (first[1][0] != '$')
	{
		if (print_echo_check_quote(line))
		{
			print_echo_quote(line, first);
			return ;
		}
		print_echo_cycle(first);
	}
	else
	{
		if (first[1][1] == 0)
		{
			ft_putstr("$\n");
			ft_strdel_mass(first);
			return ;
		}
		print_echo_do(env, line);
	}
	ft_strdel_mass(first);
}
