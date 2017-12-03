/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command_in_bin_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalyvod <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:55:22 by vpalyvod          #+#    #+#             */
/*   Updated: 2017/07/06 19:55:25 by vpalyvod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	comm_free(void)
{
	free(comm.path);
	ft_strdel_mass(comm.spl_words);
	ft_strdel_mass(comm.mass);
	free(comm.copy);
	free(comm.pars_str);
}

int		comm_if(void)
{
	if (comm.count > 0)
	{
		free(comm.pars_str);
		comm.pars_str = ft_strdup(comm.spl_words[comm.i]);
	}
	comm.tmp = ft_strjoin(comm.pars_str, "/");
	comm.p = ft_strjoin(comm.tmp, comm.mass[0]);
	free(comm.tmp);
	if (!access(comm.p, 0) && !access(comm.p, 1))
	{
		free(comm.p);
		comm.not_found = 0;
		return (1);
	}
	else
	{
		comm.not_found = 1;
		free(comm.p);
	}
	comm.i++;
	comm.count++;
	return (0);
}

void	check_comm_cycle_else(void)
{
	comm.p = ft_strdup(comm.mass[0]);
	if (!access(comm.p, 0) && !access(comm.p, 1))
		comm.not_found = 0;
	else
		comm.not_found = 1;
	free(comm.p);
}
