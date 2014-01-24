/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ex_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleroy <tleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 12:42:01 by tleroy            #+#    #+#             */
/*   Updated: 2014/01/24 12:53:02 by tleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_ex_command(t_ex *ex_info)
{
	pid_t	pid;
	int		ret;

	pid = fork();
	if (pid == 0)
	{
		ft_execute(ex_info);
		ft_error(ex_info);
		exit(0);
	}
	if (pid > 0)
		wait(&ret);
}

void	ft_error(t_ex *ex_info)
{
	if (ex_info->argv[0][0] == '.')
	{
		ft_putstr("no such file or directory: ");
		ft_putstr(ex_info->argv[0]);
		ft_putstr("\n");
	}
	else
	{
		ft_putstr("command not found: ");
		ft_putstr(ex_info->argv[0]);
		ft_putstr("\n");
	}
}
