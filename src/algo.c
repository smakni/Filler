/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 20:39:43 by smakni            #+#    #+#             */
/*   Updated: 2018/12/14 19:27:12 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>
/*
static 	int	nb_p(t_player *p)
{
	int y;
	int x;

	y = 0;
	while (y < p->p_y)
		x = 0;
*/
static	int test_piece(int fd, t_player *p, int p_y, int p_x, int m_y, int m_x)
{
	int check;
	int y;
	int x;
	int save;

	(void)fd;
	check = 0;
	y = 0;
	m_y = m_y - p_y;
	m_x = m_x - p_x;
	save = m_x;
	//check2 = 0;
	while (y < p->p_y && m_y < p->m_y)
	{
		x = 0;
		while (x < p->p_x)
		{
			//ft_dprintf(fd, "p[%d][%d] = %c | m[%d][%d] = %c\ncheck - %d\n"
			//		, y, x, p->piece[y][x], m_y, m_x, p->map[m_y][m_x], check);
			if (p->piece[y][x] == '*' && (m_y < 0 || m_x < 0 || m_x > p->m_x || m_y > p->m_y))
				return (0);
			if (check == 0 && p->piece[y][x] == '*' && p->map[m_y][m_x] == 'O')
				  check++;
			else if (check == 0 && p->piece[y][x] == '*' && p->map[m_y][m_x] == 'X')
				return (0);
			else if (check == 1 && p->piece[y][x] == '*' && p->map[m_y][m_x] != '.')
				return (0);
			x++;
			m_x++;
		}
		m_x = save;
		y++;
		m_y++;
	}
	if (check != 1)
		return (0);
	return (1);
}

static	int	test_placement_up(int fd, t_player *p, int m_y, int m_x)
{
	int y;
	int	x;

	(void)fd;
	ft_dprintf(fd, "ALGO_1\n");
	y = p->p_y - 1;
	while (y > 0)
	{
		x = p->p_x - 1;
		while (x > 0)
		{
			//ft_dprintf(fd, "PLACEMENT_[%d][%d]\n", m_y, m_x);
			if (test_piece(fd, p, y, x, m_y, m_x) == 1 &&
					analyse_placement(p, m_y - y, m_x - x) == 0)
			{
			//	ft_dprintf(fd, "y %d | x = %d\n", y, x);
				p->r_y = m_y - y;
				p->r_x = m_x - x;
				return (1);
			}
			x--;
		}
		y--;
	}
	return (0);
}

static	int	find_placement_1(int fd, t_player *p)
{
	int y;
	int x;

	(void)fd;
	y = 0;
	p->wid = analyse_y_p(p);
	p->len = analyse_x_p(p);
	while (y < p->m_y)
	{
		x = 0;
		while (x < p->m_x)
		{
			if (p->map[y][x] == 'O' && test_placement_up(fd, p, y, x) == 1)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void		algo(int fd, t_player *p)
{
	find_opponent(p);
	if (find_placement_1(fd, p) == 0) 
	{
		if (find_placement_3(fd, p) == 0)
		{	
			if (find_placement_2(fd, p) == 0)
				{
					p->r_y = 0;
					p->r_x = 0;
				}
		}
	}
	ft_dprintf(fd, "return = %d | %d\n", p->r_y, p->r_x);
	ft_printf("%d %d\n", p->r_y, p->r_x);
	p->j = 0;
	p->i = 0;
}
