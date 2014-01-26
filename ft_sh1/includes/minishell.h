/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleroy <tleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 18:25:16 by tleroy            #+#    #+#             */
/*   Updated: 2014/01/26 18:43:56 by tleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft.h"

typedef struct		s_ex
{
	char	**argv;
	char	**env;
}			t_ex;

typedef struct		s_read
{
int					size;
int					index;
char				*read;
int					fd;
struct s_read		*next;
}					t_read;

int		get_next_line(int const fd, char **line);
int		ft_go_previous(t_ex *ex_info);
int		ft_path_tilde(t_ex *ex_info);
int		ft_get_command(t_ex *ex_info, char **input);
int		ft_go_to(char *buf, char *dir);
int		ft_count_c(char *str, char c);
void	ft_execute(t_ex *ex_info);
void	ft_ex_command(t_ex *ex_info);
void	ft_change_dir(t_ex *ex_info);
void	ft_go_home(t_ex *ex_info);
void	ft_executable(t_ex *ex_info);
void	ft_error(t_ex *ex_info);
void	ft_opening(t_ex *ex_info);
int		ft_search(t_ex *ex_info, char *str);
char	**ft_get_paths(t_ex *ex_info);
void	ft_update_env(t_ex *ex_info);

#endif /*MINISHELL_H*/
