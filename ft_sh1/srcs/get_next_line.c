/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharlat <tcharlat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 22:08:24 by tcharlat          #+#    #+#             */
/*   Updated: 2014/01/24 12:25:00 by tleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	t_read		*ft_freeread(t_read *red, t_read *prev, t_read **start)
{
	if (!prev)
		*start = red->next;
	else
		prev->next = red->next;
	free(red->read);
	free(red);
	if (!prev)
		return (*start);
	else
		return (prev->next);
}

static	t_read		*ft_newread(int fd)
{
	t_read			*red;
	void			*tmp;
	int				ret;

	if (!(red = (t_read *)malloc(sizeof(t_read))))
		return (NULL);
	if (!(tmp = malloc(sizeof(char) * BUFF_SIZE)))
	{
		free(red);
		return (NULL);
	}
	if ((ret = read(fd, tmp, BUFF_SIZE)) < 0)
	{
		free(red);
		free(tmp);
		return (NULL);
	}
	red->read = (char *)tmp;
	red->fd = fd;
	red->size = ret;
	red->next = NULL;
	red->index = 0;
	return (red);
}

static	int			ft_print(int n, t_read *r, t_read *p, t_read **s, char** l)
{
	char			*tmpstr;
	int				index;

	if (!r)
		return (-1);
	index = r->index;
	if (n == -1 || !(tmpstr = (char *)malloc(sizeof (char) * (n + 1))))
		return (-1);
	*l = tmpstr;
	while (n--)
	{
		*tmpstr++ = r->read[index++];
		if (index == r->size)
		{
			r = ft_freeread(r, p, s);
			index = 0;
		}
	}
	*tmpstr = 0;
	if (!r || (index == r->size && r->size < BUFF_SIZE))
		return (0);
	r->index = index + 1;
	if (r->index == r->size)
		r = ft_freeread(r, p, s);
	return (1);
}

static	int			ft_findendl(int fd, t_read *red)
{
	int				index;
	int				size;
	t_read			*tmplst;

	size = 0;
	index = red->index;
	while (red->read[index] != '\n' && index < red->size)
	{
		index++;
		size++;
		if (index == red->size && red->size == BUFF_SIZE)
		{
			if (!(tmplst = ft_newread(fd)))
				return (-1);
			tmplst->next = red->next;
			red->next = tmplst;
			red = tmplst;
			index = 0;
		}
	}
	return (size);
}

int					get_next_line(int fd, char **line)
{
	static t_read	*start = NULL;
	t_read			*red;
	t_read			*prevtmp;

	if (fd < 0)
		return (-1);
	prevtmp = NULL;
	if (!start)
		start = ft_newread(fd);
	if (!start)
		return (- 1);
	red = start;
	while (red->fd != fd)
	{
		if (!(red->next))
			red->next = ft_newread(fd);
		prevtmp = red;
		red = red->next;
	}
	if (!red || !start)
		return (-1);
	return (ft_print(ft_findendl(fd, red), red, prevtmp, &start, line));
}
