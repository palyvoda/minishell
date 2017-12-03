/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalyvod <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:54:30 by vpalyvod          #+#    #+#             */
/*   Updated: 2017/07/06 19:57:42 by vpalyvod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_simple_input(char **env, char **mass)
{
	if (!chdir(mass[1]))
	{
		print_oldpwd(env);
		print_newpwd(env);
		;
	}
	else
		cd_errors(mass[1]);
}

void	cd_tilde_sign_cont(char *homepwd, char **env, char *tmp)
{
	if (!chdir(homepwd))
	{
		print_oldpwd(env);
		print_newpwd(env);
		;
	}
	else
		cd_errors(homepwd);
	free(homepwd);
	if (tmp != NULL)
		free(tmp);
}

void	cd_tilde_sign(char **env, char **mass)
{
	int		i;
	char	*homepwd;
	char	**spl_words;
	char	*tmp;

	tmp = NULL;
	i = 0;
	while (env[i])
	{
		spl_words = ft_strsplit(env[i], '=');
		if (ft_strcmp(*spl_words, "HOME") == 0)
		{
			tmp = ft_strdup(spl_words[1]);
			ft_strdel_mass(spl_words);
			break ;
		}
		ft_strdel_mass(spl_words);
		i++;
	}
	homepwd = ft_strjoin(tmp, mass[1] + 1);
	cd_tilde_sign_cont(homepwd, env, tmp);
}

void	cd_minus_sign(char **env)
{
	int		i;
	char	*oldpwd;
	char	**spl_words;

	i = 0;
	while (env[i])
	{
		spl_words = ft_strsplit(env[i], '=');
		if (ft_strcmp(*spl_words, "OLDPWD") == 0)
			oldpwd = ft_strdup(spl_words[1]);
		ft_strdel_mass(spl_words);
		i++;
	}
	if (!chdir(oldpwd))
	{
		print_oldpwd(env);
		print_newpwd(env);
		;
	}
	else
		cd_errors(oldpwd);
	free(oldpwd);
}
