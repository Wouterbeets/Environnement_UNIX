/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleroy <tleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 18:01:58 by tleroy            #+#    #+#             */
/*   Updated: 2014/01/26 18:58:40 by tleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_change_dir(t_ex *ex_info)
{
	char	*buf;
	int		ret;

	ret = 0;
	buf = NULL;
	buf = getcwd(buf, BUFF_SIZE);
	if (ex_info->argv[1][0] == '~')
		ret = ft_path_tilde(ex_info);
	else if (ft_strcmp(ex_info->argv[1], "-") == 0)
		ret = ft_go_previous(ex_info);
	else
		ret = ft_go_to(buf, ex_info->argv[1]);
	if (ret == 0)
		ft_update_env(ex_info);
}

int		ft_go_to(char *buf, char *dir)
{
	int		i;
	char	*path;
	int		ret;

	i = ft_strlen(buf) + ft_strlen(dir) + 2;
	path = (char *)malloc(i * sizeof(char));
	if (dir[0] != '/')
		path = ft_strjoin(buf, "/");
	path = ft_strjoin(path, dir);
	ret = chdir(path);
	if (ret == -1)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putstr(dir);
		ft_putstr("\n");
	}
	return (ret);
}

int		ft_go_previous(t_ex *ex_info)
{
	int		ret;

	ret = chdir(ex_info->env[ft_search(ex_info, "OLDPWD=")] + 7);
	ft_putendl(ex_info->env[ft_search(ex_info, "OLDPWD=")] + 7);
	return (ret);
}

int		ft_path_tilde(t_ex *ex_info)
{
	int		ret;
	int		i;
	char	*path;

	i = ft_strlen(ex_info->env[ft_search(ex_info, "HOME=")] + 5);
	i = i + ft_strlen(ex_info->argv[1] + 1);
	path = (char *)malloc(i * sizeof(char));
	path = ft_strjoin(ex_info->env[ft_search(ex_info, "HOME=")]
			+ 5, ex_info->argv[1] + 1);
	ret = chdir(path);
	if (ret == -1)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putstr(path);
		ft_putstr("\n");
	}
	return (ret);
}
