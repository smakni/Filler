/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:49:25 by smakni            #+#    #+#             */
/*   Updated: 2019/01/23 18:19:56 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static int		test_piece(int fd, int m_y, int m_x, t_player *p)
{
	int y;
	int x;
	int tmp_m_x;
	int check;

	(void)fd;
	y = 0;
	x = 0;
	tmp_m_x = m_x;
	check = 0;
	while (y < p->p_y)
	{
		x = 0;
		m_x = tmp_m_x;
		while (x < p->p_x)
		{
			if (p->piece[y][x] == '*')
			{
				if (((m_y < 0 || m_y >= p->m_y
					|| m_x < 0 || m_x >= p->m_x)
					|| (check == 1 && p->map[m_y][m_x] == p->my_c)
					|| p->map[m_y][m_x] == p->op_c))
					return (-1);
				else if (check == 0 && p->map[m_y][m_x] == p->my_c)
				{
					p->save += p->map[y][x];
					check++;
				}
				else if (p->map[m_y][m_x] != p->my_c)
					p->save += p->map[m_y][m_x];
			}
			x++;
			m_x++;
		}
		y++;
		m_y++;
	}
	if (check == 0)
		return (-1);
	return (0);
}

static	int		algo_0(int fd, t_player *p)
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
								if (test_piece(fd, tmp_y, tmp_x, p) == 0)
								{
									if (check == 0)
									{
										save_path = p->save;
										p->r_y = tmp_y;
										p->r_x = tmp_x;
										check++;
									}
									else if (check > 0 && p->save < save_path)
									{
										save_path = p->save;
										p->r_y = tmp_y;
										p->r_x = tmp_x;
									}
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

void		algo(int fd, t_player *p)
{
	(void)fd;
	if (algo_0(fd, p) == -1)
	{
		p->r_y = 0;
		p->r_x = 0;
	}
	ft_printf("%d %d\n", p->r_y, p->r_x);
	p->j = 0;
	p->i = 0;
}
