/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalyvod <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:54:36 by vpalyvod          #+#    #+#             */
/*   Updated: 2017/07/06 21:25:06 by vpalyvod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_errors(char *temp)
{
	ft_putstr("cd: ");
	if (access(temp, F_OK) == -1)
		ft_putstr("No such file or directory: ");
	else if (access(temp, R_OK) == -1)
		ft_putstr("Permission denied: ");
	else
		ft_putstr("Not a directory: ");
	ft_putstr(temp);
	ft_putstr("\n");
}

void	cd_if_mass_1_null(char **env)
{
	int		i;
	char	*homepwd;
	char	**spl_words;

	homepwd = NULL;
	i = 0;
	while (env[i])
	{
		spl_words = ft_strsplit(env[i], '=');
		if (ft_strcmp(*spl_words, "HOME") == 0)
			homepwd = ft_strdup(spl_words[1]);
		i++;
		ft_strdel_mass(spl_words);
	}
	if (!chdir(homepwd))
	{
		print_oldpwd(env);
		print_newpwd(env);
		;
	}
	else
		cd_errors(homepwd);
	if (homepwd != NULL)
		free(homepwd);
}
