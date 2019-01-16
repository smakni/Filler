/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:27:01 by smakni            #+#    #+#             */
/*   Updated: 2019/01/16 13:31:08 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static	void	fill_map(t_player *p, int y, int x, char c)
{
	int i;

	i = 0;
	while (i < 2)
	{
		if (x + i <= p->m_x && p->map[y][x + i] == '.')
			p->map[y][x + i] = c;
		if (x - i >= 0 && p->map[y][x - i] == '.')
			p->map[y][x - i] = c;
		if (y + i < p->m_y && p->map[y + i][x] == '.')
			p->map[y + i][x] = c;
		if (y - i >= 0 && p->map[y - i][x] == '.')
			p->map[y - i][x] = c;
		i++;
	}
}

void			analyse_map(int fd, t_player *p)
{
	int y;
	int x;
	char c;

	y = 0;
	x = 0;
	c = '!';
	while (y < p->m_y - 1)
	{
		x = 0;
		while (p->map[y][x])
		{
			if (p->map[y][x] == 'X')
				fill_map(p, y, x, c);
			x++;
		}
		y++;
	}
	while (c < '~')
	{
		c++;
		if (c == '.' || c == 'O')
			c += 2;
		y = 0;
		while (y < p->m_y - 1)
		{
			x = 0;
			while (p->map[y][x])
			{
				if (c == '0' && p->map[y][x] == c - 3)
					fill_map(p, y, x, c);
				else if (c == 'Q' && p->map[y][x] == c - 3)
					fill_map(p, y, x, c);
				else if (p->map[y][x] == c - 1)
					fill_map(p, y, x, c);
				x++;
			}
			y++;
		}
	}
}
