/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:51:53 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/08 15:07:40 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static int	ft_allocate_piece(t_piece *p, char *line)
{
	int		cpt;

	cpt = 0;
	if (!(get_next_line(0, &line)))
		return (-1);
	while (!(ft_isdigit(line[cpt])))
		cpt++;
	p->height = ft_atoi(line + cpt);
	while (ft_isdigit(line[cpt]))
		cpt++;
	p->width = ft_atoi(line + (cpt + 1));
	ft_strdel(&line);
	if (!(p->piece = ft_memalloc(sizeof(char*) * (p->height + 1))))
		return (-1);
	return (1);
}

static void	ft_replace_value(t_piece *p, int i, int j)
{
	if (p->xmin == -1)
	{
		p->xmin = j;
		p->ymin = i;
		p->xmax = j;
		p->ymax = i;
	}
	if (p->xmin > j)
		p->xmin = j;
	if (p->xmax < j)
		p->xmax = j;
	if (p->ymin > i)
		p->ymin = i;
	if (p->ymax < i)
		p->ymax = i;
}

static int	ft_get_extreme(t_piece *p, char *line)
{
	int		i;
	int		j;

	p->xmin = -1;
	p->ymin = -1;
	p->xmax = 0;
	p->ymax = 0;
	i = -1;
	while (++i < p->height)
	{
		get_next_line(0, &line);
		if (!(p->piece[i] = ft_strdup(line)))
			return (-1);
		ft_strdel(&line);
		j = 0;
		while (j < p->width)
		{
			if (p->piece[i][j] != '.')
				ft_replace_value(p, i, j);
			j++;
		}
	}
	p->x = p->xmax - p->xmin + 1;
	p->y = p->ymax - p->ymin + 1;
	return (1);
}

static int	ft_fill_piece(int color, t_piece *p)
{
	int		i;
	int		j;

	if (!(p->spiece = ft_memalloc(sizeof(int*) * p->y)))
		return (-1);
	i = 0;
	while (i < p->y)
	{
		j = 0;
		if (!(p->spiece[i] = ft_memalloc(sizeof(int) * p->x)))
			return (-1);
		while (j < p->x)
		{
			if (p->piece[i + p->ymin][j + p->xmin] == '.')
				p->spiece[i][j] = 0;
			else if (p->piece[i + p->ymin][j + p->xmin] == '*')
				p->spiece[i][j] = color;
			j++;
		}
		i++;
	}
	return (1);
}

int			ft_get_current_piece(t_piece *p, char *line, int color)
{
	int		i;

	i = 0;
	p->piece = NULL;
	p->spiece = NULL;
	if (ft_allocate_piece(p, line) == -1)
		return (-1);
	if (ft_get_extreme(p, line) == -1)
		return (-1);
	if (ft_fill_piece(color, p) == -1)
		return (-1);
	while (i < p->height)
		ft_strdel(&p->piece[i++]);
	free(p->piece);
	return (1);
}
