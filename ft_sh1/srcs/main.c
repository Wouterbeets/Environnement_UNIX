/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleroy <tleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 11:50:41 by tleroy            #+#    #+#             */
/*   Updated: 2014/01/23 12:10:29 by tleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv, char **env)
{
	t_ex	ex_info;
	char	*input;

	argc = 0;
	argv = 0;
	ex_info.env = env;
	while (1)
	{
		ft_putstr("$>");
		ft_get_command(&ex_info, &input);
		if (ft_strcmp(input, "exit") == 0)
			exit(0);
		if (ft_strcmp(input, "cd") == 0)
			ft_go_home(&ex_info);
		else if (ft_strcmp(ex_info.argv[0], "cd") == 0)
			ft_change_dir(&ex_info);
		else
			ft_ex_command(&ex_info);
	}
}