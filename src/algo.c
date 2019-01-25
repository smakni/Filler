/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:49:25 by smakni            #+#    #+#             */
/*   Updated: 2019/01/25 14:56:00 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static int		check_piece(int m_y, int m_x, int y, int x, t_player *p)
{
	if (((m_y < 0 || m_y >= p->m_y
		|| m_x < 0 || m_x >= p->m_x)
		|| (p->check_p == 1 && p->map[m_y][m_x] == p->my_c)
		|| p->map[m_y][m_x] == p->op_c))
		return (-1);
	else if (p->check_p == 0 && p->map[m_y][m_x] == p->my_c)
	{
		p->save += p->map[y][x];
		p->check_p++;
	}
	else if (p->map[m_y][m_x] != p->my_c)
		p->save += p->map[m_y][m_x];
	return (0);
}

static int		test_piece(int m_y, int m_x, t_player *p)
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
			if (p->piece[y][x] == '*' && check_piece(m_y, m_x, y, x, p) == -1)
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

static	int		algo_0(t_player *p)
{
	int y;
	int x;
	int tmp_y;
	int tmp_x;
	int check;
	int save_path;

	y = 0;
	x = 0;
	check = 0;
	save_path = 0;
	while (y < p->m_y)
	{
		x = 0;
		while (x < p->m_x)
		{
			if (p->map[y][x] == p->my_c)
			{
				p->offset_y = 0;
				p->offset_x = 0;
				tmp_y = 0;
				tmp_y = 0;
				while (p->offset_y < p->p_y)
				{
					if (ft_strchr(p->piece[p->offset_y], '*') != 0)
					{
						p->offset_x = 0;
						while (p->offset_x < p->p_x)
						{
							if (p->piece[p->offset_y][p->offset_x] == '*')
							{
								tmp_y = y - p->offset_y;
								tmp_x = x - p->offset_x;
								if ( test_piece(tmp_y, tmp_x, p) == 0)
								{
									if (check == 0)
									{
										save_path = save_x_y(p, tmp_y, tmp_x);
										check++;
									}
									else if (check > 0 && p->save < save_path)
										save_path = save_x_y(p, tmp_y, tmp_x);
								}
							}
							p->save = 0;
							p->offset_x++;
						}
					}
					p->offset_y++;
				}
			}
			x++;
		}
		y++;
	}
	if (save_path == 0)
		return (-1);
	return (0);
}

int		algo(int fd, t_player *p)
{
	(void)fd;
	//usleep(50000);
	if (algo_0(p) == -1)
		return (-1);
	ft_printf("%d %d\n", p->r_y, p->r_x);
	p->j = 0;
	p->i = 0;
	return (0);
}
