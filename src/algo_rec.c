/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 20:39:43 by smakni            #+#    #+#             */
/*   Updated: 2018/12/13 19:25:43 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>				

int		static	placement_p1(int fd, t_player *p, int m_x, int m_y)
{
	int x;
	int y;
	int save;
	int	position;

	(void)fd;
	save = m_x;
	y = 0;
	position = 0;
	p->offset_x = 0;
	p->offset_y = 0;
	while(y < p->p_y && m_y < p->m_y)
	{
		x = 0;
		m_x = save - p->offset_x; 
		while (p->piece[y][x])
		{
			if (position == 0 && p->piece[y][x] == '*' 
				&& (p->map[m_y][m_x] == 'O'))
				position++;
			else if (position == 1 && p->piece[y][x] != '\0'
					&& p->piece[y][x] == '*' && p->map[m_y][m_x] != '.') 
				return (0);
			else if (position == 0)
				p->offset_x++;
			if (position == 1)
				m_x++;
			x++;
		}
		if (position == 0)
		{
			p->offset_x = 0;
			p->offset_y++;
		}
		else
			m_y++;
		y++;
	}
	return (1);
}

static	void	find_placement(int fd, t_player *p)
{
	int x;
	int y;

	y = 0;
	p->wid = analyse_y_p(p);
	p->len = analyse_x_p(p);
	while(y < p->m_y)
	{
		x = 0;
		while (p->map[y][x])
		{
			if (p->nb == 1 && p->map[y][x] == 'O' 
					&& placement_p1(fd, p, x, y) == 1)
			{
				if (analyse_placement(p, y, x) == 0)
				{
					p->r_y = y - p->offset_y;
					p->r_x = x - p->offset_x;
					return ;
				}
			}
			x++;
		}
		y++;
	}
	p->r_y = 0;
	p->r_x = 0;
}
				
void		algo(int fd, t_player *p)
{
	find_opponent(p);
	find_placement(fd, p);	
	ft_printf("%d %d\n", p->r_y, p->r_x);
	ft_dprintf(fd, "return = %d | %d\n", p->r_y, p->r_x);
	p->j = 0;
	p->i = 0;
}
