/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleroy <tleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 12:44:52 by tleroy            #+#    #+#             */
/*   Updated: 2014/01/26 18:54:36 by tleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_update_env(t_ex *ex_info)
{
	char	*path;

	path = NULL;
	path = getcwd(path, BUFF_SIZE);
	ex_info->env[ft_search(ex_info, "OLDPWD=")] =
		ft_strjoin("OLDPWD=", ex_info->env[ft_search(ex_info, "PWD=")] + 4);
	ex_info->env[ft_search(ex_info, "PWD=")] = ft_strjoin("PWD=", path);
}
