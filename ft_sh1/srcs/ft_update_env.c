/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleroy <tleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 12:44:52 by tleroy            #+#    #+#             */
/*   Updated: 2014/01/25 13:39:23 by tleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_update_env(t_ex *ex_info)
{
	char	*path;
	char	*tmp;

	ft_putstr(ex_info->env[15]);
	ft_putstr("\n");
	path = NULL;
	path = getcwd(path, BUFF_SIZE);
	//free(ex_info->env[21]);
	tmp = ft_strdup(ex_info->env[15]);
	//free(ex_info->env[15]);
	ft_putstr(tmp);
	ft_putstr("\n");
	ft_putstr(path);
	ft_putstr("\n");
	ex_info->env[21] = path;
	ex_info->env[15] = tmp;
	free(tmp);
}
