/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleroy <tleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 12:40:43 by tleroy            #+#    #+#             */
/*   Updated: 2014/01/24 18:07:56 by tleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_get_command(t_ex *ex_info, char **input)
{
	int		ret;
	char	**tab;

	ret = get_next_line(0, input);
	*input = ft_strtrim(*input);
	if (ft_strcmp(*input, "") == 0)
		return (1);
	tab = ft_strsplit(*input, ' ');
	ex_info->argv = tab;
	return (0);
}
