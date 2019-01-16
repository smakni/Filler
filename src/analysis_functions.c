/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:21:14 by smakni            #+#    #+#             */
/*   Updated: 2019/01/14 18:39:43 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		analyse_placement(t_player *p, int y, int x)
{
	if (y + p->wid < p->m_y
		&& x + p->len < p->m_x)
		return (0);
	else
		return (-1);
}

int		analyse_y_p(t_player *p)
{
	int count;
	int y;

	count = 0;
	y = 0;
	while (y < p->p_y)
	{
		if (ft_strchr(p->piece[y], '*') != 0)
			count++;
		y++;
	}
	return (count - 1);
}

int		analyse_x_p(t_player *p)
{
	int y;
	int x;
	int max;
	int min;
	int check;

	check = 0;
	max = 0;
	min = 0;
	y = 0;
	while (y < p->p_y)
	{
		x = 0;
		while (p->piece[y][x])
		{
			if (check == 0 && p->piece[y][x] == '*' && min == 0 && max == 0)
			{
				min = x;
				max = x;
				check++;
			}
			if (p->piece[y][x] == '*' && x < min)
				min = x;
			else if (p->piece[y][x] == '*' && x > max)
				max = x;
			x++;
		}
		y++;
	}
	return (max - min);
}
