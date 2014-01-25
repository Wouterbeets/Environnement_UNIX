/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_home.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleroy <tleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 11:57:35 by tleroy            #+#    #+#             */
/*   Updated: 2014/01/25 18:01:40 by tleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_go_home(t_ex *ex_info)
{
	int		ret;

	ret = chdir(ft_search(ex_info, "HOME=") + 5);
	//ex_info = ft_update_env(ex_info);
}
