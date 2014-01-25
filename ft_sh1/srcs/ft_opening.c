/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opening.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleroy <tleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 12:14:28 by tleroy            #+#    #+#             */
/*   Updated: 2014/01/25 14:18:19 by tleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_opening(t_ex ex_info)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open("opening", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_putstr(line);
		ft_putstr("\n");
		free(line);
	}
	close(fd);
	ft_putstr("Welcome ");
	ft_putstr(ex_info.env[4] + 5);
	ft_putstr("!\n");
}
