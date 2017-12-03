/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line_words.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalyvod <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:56:56 by vpalyvod          #+#    #+#             */
/*   Updated: 2017/07/06 19:56:59 by vpalyvod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*words(char *line)
{
	int		i;
	char	*temp;
	int		k;
	char	**mass;
	char	*tmp;

	mass = ft_split(line);
	k = 1;
	i = count_words(line);
	tmp = ft_strjoin(mass[k++], " ");
	while (k < i)
		temp = ft_strjoin(tmp, mass[k++]);
	free(tmp);
	ft_strdel_mass(mass);
	return (temp);
}

char	*words_first(char *line)
{
	int		i;
	char	*temp;
	char	*sec_temp;
	int		k;
	char	**mass;

	mass = ft_split(line);
	k = 0;
	i = count_words(line);
	temp = ft_strdup(mass[k++]);
	while (k < i)
	{
		sec_temp = ft_strjoin(temp, " ");
		free(temp);
		temp = ft_strjoin(sec_temp, mass[k++]);
		free(sec_temp);
	}
	ft_strdel_mass(mass);
	return (temp);
}
