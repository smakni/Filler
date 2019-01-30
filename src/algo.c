/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:49:25 by smakni            #+#    #+#             */
/*   Updated: 2019/01/30 16:22:58 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static int		check_path(int m_y, int m_x, t_player *p)
{
	if (((m_y < 0 || m_y >= p->m_y
		|| m_x < 0 || m_x >= p->m_x)
		|| (p->check_p == 1 && p->map[m_y][m_x] == p->my_c)
		|| p->map[m_y][m_x] == p->op_c))
		return (-1);
	else if (p->check_p == 0 && p->map[m_y][m_x] == p->my_c)
		p->check_p++;
	else if (p->map[m_y][m_x] != p->my_c)
		p->save += p->map[m_y][m_x];
	return (0);
}

static	int		test_piece(int m_y, int m_x, t_player *p)
{
	int y;
	int x;
	int tmp_m_x;

	y = 0;
	x = 0;
	tmp_m_x = m_x;
	p->check_p = 0;
	while (y < p->p_y)
	{
		x = 0;
		m_x = tmp_m_x;
		while (x < p->p_x)
		{
			if (p->piece[y][x] == '*' && check_path(m_y, m_x, p) == -1)
				return (-1);
			x++;
			m_x++;
		}
		y++;
		m_y++;
	}
	if (p->check_p == 0)
		return (-1);
	return (0);
}

static	int		save_x_y(t_player *p, int tmp_y, int tmp_x)
{
	p->r_y = tmp_y;
	p->r_x = tmp_x;
	return (p->save);
}

static	void	find_path(t_player *p, int y, int x)
{
	int tmp_y;
	int tmp_x;

	p->offset_x = 0;
	while (p->offset_x < p->p_x)
	{
		if (p->piece[p->offset_y][p->offset_x] == '*')
		{
			tmp_y = y - p->offset_y;
			tmp_x = x - p->offset_x;
			if (test_piece(tmp_y, tmp_x, p) == 0
				&& (p->check_path == 0
				|| (p->check_path > 0 && p->save < p->save_path)))
			{
				p->save_path = save_x_y(p, tmp_y, tmp_x);
				p->check_path++;
			}
		}
		p->save = 0;
		p->offset_x++;
	}
}

void			path(t_player *p, int y, int x)
{
	p->offset_y = 0;
	p->offset_x = 0;
	while (p->offset_y < p->p_y)
	{
		if (ft_strchr(p->piece[p->offset_y], '*') != 0)
			find_path(p, y, x);
		p->offset_y++;
	}
}
