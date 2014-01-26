/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleroy <tleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 12:43:07 by tleroy            #+#    #+#             */
/*   Updated: 2014/01/26 16:08:33 by tleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_execute(t_ex *ex_info)
{
	char	**paths;
	char	*tmp;
	int		i;

	i = 0;
	paths = ft_get_paths(ex_info);
	while (paths[i] != '\0')
	{
		tmp = ft_strjoin(paths[i], ex_info->argv[0]);
		execve(tmp, ex_info->argv, ex_info->env);
		free(tmp);
		i++;
	}
	execve(ex_info->argv[0], ex_info->argv, ex_info->env);
}
