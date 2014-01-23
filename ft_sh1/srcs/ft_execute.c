/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleroy <tleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 12:43:07 by tleroy            #+#    #+#             */
/*   Updated: 2014/01/23 14:59:49 by tleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_execute(t_ex *ex_info)
{
	char	**paths;
	char	*tmp;
	int		i;

	i = 0;
	paths = ft_get_paths(ex_info->env);
	while (paths[i] != '\0')
	{
		tmp = ft_strjoin(paths[i], ex_info->argv[0]);
		execve(tmp, ex_info->argv, ex_info->env);
		free(tmp);
		i++;
	}
	ft_putstr(ex_info->argv[0] + 2);
	ft_putstr("\n");
	ft_executable(ex_info);
}

void	ft_executable(t_ex *ex_info)
{
	char	*tmp;
	char	*path;
	int		i;

	tmp = NULL;
	tmp = getcwd(tmp, BUFF_SIZE);
	i = ft_strlen(tmp) + ft_strlen(ex_info->argv[0]) + 1;
	path = malloc(i * sizeof(char));
	path = ft_strjoin(tmp, "/");
	ft_putstr(path);
	ft_putstr("\n");
	ft_putstr(ex_info->argv[0] + 2);
	ft_putstr("\n");
	path = ft_strjoin(path, ex_info->argv[0] + 2);
	ft_putstr(ex_info->argv[0] + 2);
	ft_putstr("\n");
	ft_putstr(path);
	ft_putstr("\n");
	//execve(tmp, ex_info->argv, ex_info->env);
}
