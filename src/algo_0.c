/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:18:11 by smakni            #+#    #+#             */
/*   Updated: 2019/01/30 16:30:19 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static	int		algo_0(t_player *p)
{
	int y;
	int x;

	y = 0;
	x = 0;
	p->check_path = 0;
	p->save_path = 0;
	while (y < p->m_y)
	{
		x = 0;
		while (x < p->m_x)
		{
			if (p->map[y][x] == p->my_c)
				path(p, y, x);
			x++;
		}
		y++;
	}
	if (p->save_path == 0)
		return (-1);
	return (0);
}

int				algo(int fd, t_player *p)
{
	(void)fd;
	if (algo_0(p) == -1)
		return (-1);
	ft_printf("%d %d\n", p->r_y, p->r_x);
	p->j = 0;
	p->i = 0;
	return (0);
}
