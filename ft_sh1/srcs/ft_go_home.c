/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_home.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleroy <tleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 11:57:35 by tleroy            #+#    #+#             */
/*   Updated: 2014/01/26 18:52:32 by tleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_go_home(t_ex *ex_info)
{
	int		ret;

	ret = chdir(ex_info->env[ft_search(ex_info, "HOME=")] + 5);
	if (ret == 0)
		ft_update_env(ex_info);
}
