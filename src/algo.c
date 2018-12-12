/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 20:39:43 by smakni            #+#    #+#             */
/*   Updated: 2018/12/12 17:14:51 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static	void	find_opponent(t_player *p)
{
	int x;
	int y;

	y = 0;
	while(y < p->m_y)
	{
		x = 0;
		while (p->map[y][x])
		{
			if (p->nb == 1 && (p->map[y][x] == 'X' || p->map[y][x] == 'x'))
			{
				p->op_y = y;
				p->op_x = x;
				break ;
			}
			else if (p->nb == 2 && (p->map[y][x] == 'O' || p->map[y][x] == 'o'))
			{
				p->op_y = y;
				p->op_x = x;
				break ;
			}
			x++;
		}
		y++;
	}
}				

int		static	try_placement_p1(int fd, t_player *p, int m_x, int m_y)
{
	int x;
	int y;
	int save;
	int	position;

	save = m_x;
	y = 0;
	position = 0;
	p->offset_x = 0;
	p->offset_y = 0;
	while(y < p->p_y)
	{
		x = 0;
		m_x = save - p->offset_x; 
		//ft_dprintf(fd, "test_placement\n");
		while (p->piece[y][x])
		{
			if (position == 0 && p->piece[y][x] == '*' 
				&& (p->map[m_y][m_x] == 'O' || p->map[m_y][m_x] == 'o'))
				position++;
			else if (position == 1 && p->piece[y][x] != '\0'
					&& p->piece[y][x] == '*' && p->map[m_y][m_x] != '.') 
				return (0);
			else if (position == 0)
				p->offset_x++;
			if (position == 1)
				m_x++;
			//ft_dprintf(fd, "piece = %c | position = %d\n", p->piece[y][x], position);
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
	ft_dprintf(fd, "debug_1\n");
	ft_dprintf(fd, "offset_y = %d | offset_x = %d\n",p->offset_y, p->offset_x);
	return (1);
}

int		static	try_placement_p2(int fd, t_player *p, int m_x, int m_y)
{
	int x;
	int y;
	int save;
	int	position;

	save = m_x;
	y = 0;
	position = 0;
	p->offset_x = 0;
	p->offset_y = 0;
	while(y < p->p_y)
	{
		x = 0;
		m_x = save - p->offset_x; 
		//ft_dprintf(fd, "test_placement\n");
		while (p->piece[y][x])
		{
			if (position == 0 && p->piece[y][x] == '*' 
				&& (p->map[m_y][m_x] == 'X' || p->map[m_y][m_x] == 'x'))
				position++;
			else if (position == 1 && p->piece[y][x] != '\0'
					&& p->piece[y][x] == '*' && p->map[m_y][m_x] != '.') 
				return (0);
			else if (position == 0)
				p->offset_x++;
			if (position == 1)
				m_x++;
			//ft_dprintf(fd, "piece = %c | position = %d\n", p->piece[y][x], position);
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
	ft_dprintf(fd, "debug_1\n");
	ft_dprintf(fd, "offset_y = %d | offset_x = %d\n",p->offset_y, p->offset_x);
	return (1);
}



static	void	find_placement(int fd, t_player *p)
{
	int x;
	int y;

	y = 0;
	(void)fd;
	while(y < p->m_y)
	{
		x = 0;
		while (p->map[y][x])
		{
			if (p->nb == 1 && (p->map[y][x] == 'O' || p->map[y][x] == 'o'))
			{
				if (try_placement_p1(fd, p, x, y) == 1)
				{
					p->r_y = y - p->offset_y;
					p->r_x = x - p->offset_x;
					return ;
				}
			}
			else if (p->nb == 2 && (p->map[y][x] == 'X' || p->map[y][x] == 'x'))
			{
				if (try_placement_p2(fd, p, x, y) == 1)
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
