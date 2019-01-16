/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:20:12 by smakni            #+#    #+#             */
/*   Updated: 2019/01/16 19:39:37 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static int		test_piece(int fd, int m_y, int m_x, t_player *p)
{
	int y;
	int x;
	int tmp_m_x;
	int check;

	y = 0;
	x = 0;
	tmp_m_x = m_x;
	check = 0;
	//ft_dprintf(fd, "----------\nTEST_PIECE_Y(%d)_X(%d)\n", m_y, m_x);
	while(y < p->p_y && m_y < p->m_y && m_y >= 0)
	{
		x = 0;
		m_x = tmp_m_x;
		while (x < p->p_x) 
		{
	//		ft_dprintf(fd, "PIECE[%d][%d] = %c | MAP[%d][%d] = %c | CHECK = %d\n",
	//				y, x, p->piece[y][x], m_y, m_x, p->map[m_y][m_x], check);
			if (check == 0 && p->piece[y][x] != '\0' && 
					p->piece[y][x] == '*' && p->map[m_y][m_x] == 'O')
			{
				p->save += p->map[y][x];
				check++;
	//			ft_dprintf(fd, "SAVE++ = %d\n", p->save);
			}
			else if (check == 0 && p->piece[y][x] == '*' 
					&& p->map[m_y][m_x] == 'X')
					return (-1);
			else if (check == 1 && p->piece[y][x] == '*' 
					&& (p->map[m_y][m_x] == 'O' || p->map[m_y][m_x] == 'X'))
				return (-1);
			else if (p->piece[y][x] == '*' && (m_y < 0 || m_y > p->m_y 
					|| m_x < 0 || m_x > p->m_x))
				return (-1);
			else if (p->piece[y][x] == '*' && p->map[m_y][m_x] != 'O')
			{
				p->save += p->map[m_y][m_x];
	//			ft_dprintf(fd, "SAVE++ = %d\n", p->save);
			}
			x++;
			m_x++;
		}
		y++;
		m_y++;
	}
//	ft_dprintf(fd, "----------\n");
	if (check == 0)
		return (-1);
	return (0);
}

static int 	algo_0(int fd, t_player *p)
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
		while (x <= p->m_x)
		{
			if (p->map[y][x] == 'O')
			{
//				ft_dprintf(fd, "==============================\n");
//				ft_dprintf(fd, "MAP[%d][%d] = %c\n", y, x, p->map[y][x]);
//				ft_dprintf(fd, "==============================\n");
				p->offset_y = 0;
				p->offset_x = 0;
				tmp_y = 0;
				tmp_y = 0;
				while (p->offset_y <= p->p_y)
				{
					p->offset_x = 0;
					while (p->offset_x <= p->p_x)
					{
						tmp_y = y - p->offset_y;
						tmp_x = x - p->offset_x;
						if (test_piece(fd, tmp_y, tmp_x, p) == 0
								&& analyse_placement(p, tmp_y, tmp_x) == 0)
						{
//							ft_dprintf(fd, ">>>>SAVE<<<<\n");
//							ft_dprintf(fd, "SAVE_TMP = %d\n", p->save);
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
						p->save = 0;
//						ft_dprintf(fd, "SAVE = %d\n=========\n", save_path);
						p->offset_x++;
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
	//usleep(50000);
	if (algo_0(fd, p) == -1)
	{
		p->r_y = 0;
		p->r_x = 0;
	}
//	ft_dprintf(fd, ">>>>>>>>r_y = %d | r_x = %d<<<<<<<<<<\n", p->r_y, p->r_x);
	ft_printf("%d %d\n", p->r_y, p->r_x);
	p->j = 0;
	p->i = 0;
}
