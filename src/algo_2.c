/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 20:39:43 by smakni            #+#    #+#             */
/*   Updated: 2018/12/14 19:27:10 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	find_offset(int fd, t_player *p)
{
	int y;
	int x;

	(void)fd;
	y = 0;
	while (y < p->p_y)
	{
		x = 0;
		while (p->piece[y][x] != '*' && p->piece[y][x])
		{
			p->offset_x++;
			x++;
		}
		if (p->piece[y][x] == '*')
			return ;
		p->offset_x = 0;
		p->offset_y++;
		y++;
	}
}


int		static	placement(int fd, t_player *p, int m_x, int m_y)
{
	int x;
	int y;
	int check;
	int save_1;
	int save_2;

	check = 0;
	save_2 = m_x;
	p->offset_x = 0;
	p->offset_y = 0;
	find_offset(fd, p);
	save_1 = p->offset_x;
	y = p->offset_y;
//	ft_dprintf(fd, "PLACEMENT_[%d][%d]\n", m_y, m_x);
//	ft_dprintf(fd, "off_y = %d | off_x = %d\n", p->offset_y, p->offset_x);
	while(y < p->p_y && m_y < p->m_y)
	{
		x = 0 + save_1;
		while (p->piece[y][x])
		{
	//		ft_dprintf(fd, "p[%d][%d] = %c | m[%d][%d] = %c\n"
	//				, y, x, p->piece[y][x], m_y, m_x, p->map[m_y][m_x]);
			if (check != 0 && p->piece[y][x] != '\0' &&
					p->piece[y][x] == '*' && p->map[m_y][m_x] != '.')	
				return (0);
			if (p->piece[y][x] == '*' 
					&& (m_x < 0 || m_y < 0))
				return (0);
			check++;
			m_x++;
			x++;
		}
		m_x = m_x - p->p_x;;
		save_1 = 0;
		m_y++;
		y++;
	}
	return (1);
}

int			find_placement_2(int fd, t_player *p)
{
	int x;
	int y;

	y = 0;
	p->wid = analyse_y_p(p);
	p->len = analyse_x_p(p);
	ft_dprintf(fd, "ALGO_2\n");
	while(y < p->m_y)
	{
		x = 0;
		while (p->map[y][x])
		{
			if (p->nb == 1 && p->map[y][x] == 'O'
					&& placement(fd, p, x, y) == 1
					&& analyse_placement(p, y, x) == 0)
			{
				p->r_y = y - p->offset_y;
				p->r_x = x - p->offset_x;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}	

int			find_placement_3(int fd, t_player *p)
{
	int x;
	int y;

	y = 0;
	p->wid = analyse_y_p(p);
	p->len = analyse_x_p(p);
	ft_dprintf(fd, "ALGO_2\n");
	while(y < p->m_y - 1)
	{
		x = 0;
		while (p->map[y][x])
		{
			if (p->nb == 1 && p->map[y][x] == 'O' && 
				(ft_strchr(p->map[y + 1], 'O') == 0)
					&& placement(fd, p, x, y) == 1
					&& analyse_placement(p, y, x) == 0)
			{
				p->r_y = y - p->offset_y;
				p->r_x = x - p->offset_x;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
