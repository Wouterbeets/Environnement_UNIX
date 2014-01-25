/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleroy <tleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 11:50:41 by tleroy            #+#    #+#             */
/*   Updated: 2014/01/25 18:37:38 by tleroy           ###   ########.fr       */
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
	ft_opening(&ex_info);
	while (42)
	{
		ft_putstr(ft_search(&ex_info, "USER=") + 5);
		ft_putstr("$>");
		if (ft_get_command(&ex_info, &input) == 0)
		{
			if (ft_strcmp(input, "exit") == 0)
				exit(0);
			if (ft_strcmp(input, "cd") == 0)
				ft_go_home(&ex_info);
			else if ((ft_strcmp(ex_info.argv[0], "cd") == 0)
					|| (ft_strcmp(ex_info.argv[0], "~") == 0))
				ft_change_dir(&ex_info);
			else
				ft_ex_command(&ex_info);
		}
	}
}
