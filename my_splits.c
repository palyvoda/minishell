/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_splits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalyvod <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:56:10 by vpalyvod          #+#    #+#             */
/*   Updated: 2017/07/06 19:56:12 by vpalyvod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		count_words(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && (*str == ' ' || *str == '\n' || *str == '\t'))
			str++;
		if (*str && *str != ' ' && *str != '\n' && *str != '\t')
		{
			count++;
			while (*str && *str != ' ' && *str != '\n' && *str != '\t')
				str++;
		}
	}
	return (count);
}

char	*ft_strndup(const char *s, size_t n)
{
	size_t	slen;
	int		len;
	char	*copy;

	slen = ft_strlen(s);
	len = slen < n ? slen : n;
	copy = malloc(len + 1);
	if (copy)
	{
		ft_memcpy(copy, s, len);
		copy[len] = 0;
	}
	return (copy);
}

char	**ft_split(char *str)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(split = (char **)malloc(sizeof(char *) * (count_words(str) + 1))))
		return (split);
	while (str && str[i])
	{
		while (*str && (*str == ' ' || *str == '\t'))
			str++;
		if (*str)
		{
			while (str[i] && str[i] != ' ' && str[i] != '\t')
				i++;
			split[j] = ft_strndup(str, i);
			j++;
			str = str + i;
			i = 0;
		}
	}
	split[j] = NULL;
	return (split);
}

int		count_wor(char *str)
{
	int		count;

	count = 0;
	while (*str)
	{
		while (*str && (TAB(*str) || *str == '"'))
			str++;
		if (*str && TABA(*str) && *str != '"')
		{
			count++;
			while (*str && TABA(*str) && *str != '"')
				str++;
		}
	}
	return (count);
}

char	**ft_split_quotes(char *str)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(split = (char **)malloc(sizeof(char *) * (count_wor(str) + 1))))
		return (split);
	while (str && str[i])
	{
		while (*str && (*str == ' ' || *str == '\t' || *str == '"'))
			str++;
		if (*str)
		{
			while (str[i] && str[i] != '"')
				i++;
			split[j] = ft_strndup(str, i);
			j++;
			str = str + i;
			i = 0;
		}
	}
	split[j] = NULL;
	return (split);
}
