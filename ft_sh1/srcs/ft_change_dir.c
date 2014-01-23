/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleroy <tleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 18:01:58 by tleroy            #+#    #+#             */
/*   Updated: 2014/01/23 15:01:22 by tleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_change_dir(t_ex *ex_info)
{
	char	*buf;

	buf = NULL;
	buf = getcwd(buf, BUFF_SIZE);
	if (ft_strcmp(ex_info->argv[1], "..") == 0)
		ft_go_back(buf);
	else
		ft_go_to(buf, ex_info->argv[1]);

}

void	ft_go_back(char *buf)
{
	int		i;
	char	*path;
	int		ret;

	i = ft_strlen(buf) + 1;
	path = malloc(i * sizeof(char));
	while (buf[i] != '/')
		i--;
	path = ft_strncpy(path, buf, i);
	ret = chdir(path);
}

void	ft_go_to(char *buf, char *dir)
{
	int		i;
	char	*path;
	int		ret;

	i = ft_strlen(buf) + ft_strlen(dir) + 2;
	path = malloc(i * sizeof(char));
	path = ft_strjoin(buf, "/");
	path = ft_strjoin(path, dir);
	ret = chdir(path);
}

