/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleroy <tleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 11:56:10 by tleroy            #+#    #+#             */
/*   Updated: 2014/01/23 14:35:47 by tleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "libft.h"

typedef struct		s_ex
{
	char	**argv;
	char	**env;
}			t_ex;

char	**ft_get_paths(char **tab);
int		ft_count_c(char *str, char c);
void	ft_execute(t_ex *ex_info);
void	ft_ex_command(t_ex *ex_info);
void	ft_get_command(t_ex *ex_info, char **input);
void	ft_change_dir(t_ex *ex_info);
void	ft_go_back(char *buf);
void	ft_go_to(char *buf, char *dir);
void	ft_go_home();
void	ft_executable(t_ex *ex_info);
#endif