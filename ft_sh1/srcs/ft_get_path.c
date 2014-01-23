/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleroy <tleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 13:27:10 by tleroy            #+#    #+#             */
/*   Updated: 2014/01/22 19:23:19 by tleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_get_paths(char **tab)
{
	char	**tmp;
	char	**paths;
	int		i;
	int		j;

	tmp = ft_strsplit(tab[0] + 5, ':');
	i = ft_count_c(tab[0], ':') + 1;
	paths = (char **)malloc(i *sizeof(*paths));
	paths[i] = '\0';
	j = 0;
	while (j < i)
	{
		paths[j] = ft_strjoin(tmp[j], "/");
		free(tmp[j]);
		j++;
	}
	free(tmp);
	return (paths);
}
