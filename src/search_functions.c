/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:27:01 by smakni            #+#    #+#             */
/*   Updated: 2018/12/13 14:35:00 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	find_opponent(t_player *p)
{
	int x;
	int y;

	y = 0;
	while(y < p->m_y)
	{
		x = 0;
		while (p->map[y][x])
		{
			if (p->nb == 1 && (p->map[y][x] == 'X'))
			{
				p->op_y = y;
				p->op_x = x;
				break ;
			}
			else if (p->nb == 2 && (p->map[y][x] == 'O'))
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
