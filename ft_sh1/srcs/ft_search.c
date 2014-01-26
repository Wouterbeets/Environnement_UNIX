/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleroy <tleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 18:28:21 by tleroy            #+#    #+#             */
/*   Updated: 2014/01/26 16:50:48 by tleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_search(t_ex *ex_info, char *str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (ex_info->env[k] != '\0')
	{
		while (ex_info->env[k][i] != '\0')
		{
			if (str[j] == '\0')
				return (k);
			if (str[j] == ex_info->env[k][i])
				j++;
			else
				j = 0;
			i++;
		}
		i = 0;
		k++;
	}
	return (-1);
}
