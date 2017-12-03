/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalyvod <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:54:46 by vpalyvod          #+#    #+#             */
/*   Updated: 2017/07/06 20:01:07 by vpalyvod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_oldpwd(char **env)
{
	int		i;
	char	*pwd;
	char	*tmp;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PWD=", 4))
			pwd = ft_strdup(env[i] + 4);
		if (!ft_strncmp(env[i], "OLDPWD=", 7))
		{
			free(env[i]);
			tmp = ft_strdup("OLDPWD=");
			env[i] = ft_strjoin(tmp, pwd);
			free(tmp);
		}
		i++;
	}
	if (pwd)
		free(pwd);
}

void	print_newpwd(char **env)
{
	int		i;
	char	dir[1024];
	char	**spl_words;
	char	*tmp;

	i = 0;
	while (env[i])
	{
		spl_words = ft_strsplit(env[i], '=');
		if (ft_strcmp(*spl_words, "PWD") == 0)
		{
			free(env[i]);
			tmp = ft_strdup("PWD=");
			getcwd(dir, 1024);
			if (set_env.tmp_val != NULL)
				free(set_env.tmp_val);
			set_env.tmp_val = ft_strdup(dir);
			env[i] = ft_strjoin(tmp, set_env.tmp_val);
			free(tmp);
		}
		ft_strdel_mass(spl_words);
		i++;
	}
}
