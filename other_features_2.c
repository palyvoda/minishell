/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_features_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalyvod <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:56:28 by vpalyvod          #+#    #+#             */
/*   Updated: 2017/07/06 19:56:31 by vpalyvod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_command(char *line, char *command)
{
	char	**word;

	word = ft_split(line);
	if ((ft_strcmp(word[0], command)) == 0)
	{
		ft_strdel_mass(word);
		return (1);
	}
	ft_strdel_mass(word);
	return (0);
}

void	var_without_dol(char *line)
{
	int		i;
	char	**mass;

	mass = ft_split(line);
	if (set_env.tmp_var != NULL)
		free(set_env.tmp_var);
	set_env.tmp_var = ft_strdup(mass[1]);
	i = 0;
	while (set_env.tmp_var[i])
	{
		if (set_env.tmp_var[i] != 0)
			set_env.tmp_var[i] = set_env.tmp_var[i + 1];
		i++;
	}
	set_env.tmp_var[--i] = 0;
	ft_strdel_mass(mass);
}

char	**get_env(char **env)
{
	char	**ptr;
	int		i;
	char	**envcop;
	int		len;
	char	**bpr;

	ptr = env;
	bpr = env;
	len = 0;
	while (*bpr != 0)
	{
		len += ft_strlen(*bpr);
		bpr++;
	}
	envcop = (char**)malloc(sizeof(char*) * (len + 1));
	i = 0;
	while (*ptr != 0)
	{
		envcop[i] = ft_strdup(*ptr);
		ptr++;
		i++;
	}
	return (envcop);
}

void	siginthandler(int k)
{
	(void)k;
	signal(SIGINT, siginthandler);
	ft_putstr("\n");
}

int		check_errors_cd(DIR **dp, char *dir)
{
	struct stat statv;

	lstat(dir, &statv);
	if ((*dp = opendir(dir)) == NULL)
	{
		if (!(statv.st_mode))
			fprintf(stderr, "%s: No such file or directory\n", dir);
		else
			printf("Permission denied: %s\n", dir);
		return (1);
	}
	return (0);
}
