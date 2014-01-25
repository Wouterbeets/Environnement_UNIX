/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleroy <tleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 12:44:52 by tleroy            #+#    #+#             */
/*   Updated: 2014/01/25 17:14:33 by tleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ex	*ft_update_env(t_ex *ex_info)
{
	char	*path;
	char	*tmp;
	int		i;

	i = ft_strlen(ex_info->env[15] + 4) + 8;
	tmp = (char *)malloc(i *sizeof(char *));
	ft_putstr(ex_info->env[15]);
	ft_putstr("\n");
	ft_putstr(ex_info->env[21]);
	ft_putstr("\n");
	path = NULL;
	path = getcwd(path, BUFF_SIZE);
	//free(ex_info->env[21]);
	tmp = (ex_info->env[15] + 4);
	ft_putstr(tmp);
	ft_putstr("\n");
	tmp = ft_strjoin("OLDPWD=", tmp);
	//free(ex_info->env[15]);
	//ft_putstr(tmp);
	//ft_putstr("\n");
	ex_info->env[21] = tmp;
	path = ft_strjoin("PWD=", path);
	ex_info->env[15] = path;
	ft_putstr(ex_info->env[15]);
	ft_putstr("\n");
	ft_putstr(ex_info->env[21]);
	ft_putstr("\n");
	free(tmp);
	return (ex_info);
}
