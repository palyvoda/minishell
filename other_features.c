/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_features.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalyvod <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:56:22 by vpalyvod          #+#    #+#             */
/*   Updated: 2017/07/06 19:56:24 by vpalyvod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_strdel_mass(char **mass)
{
	int	i;

	i = 0;
	if (mass)
	{
		while (mass[i])
		{
			ft_strdel(&mass[i]);
			i++;
		}
		free(mass);
		mass = NULL;
	}
}

char	*my_strndup(char *str, int len)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char*)malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
		return (NULL);
	while (i < len)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int		env_strcmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (s1[j] != '\0' && s2[i] != '\0' && s1[j] == s2[i])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[j] - (unsigned char)s2[i]);
}
