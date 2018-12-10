/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:46:38 by smakni            #+#    #+#             */
/*   Updated: 2018/12/10 19:15:43 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	first_read(int fd, char *line, t_map *map, t_player *p)
{
	(void)fd;
	if (p->nb == 0)
		p->nb = ft_atoi(&(line[10]));
	else if (line[1] == 'l')
	{
		save_map_data(line, map);
	//	ft_dprintf(fd, "map = %d\n", map->y);
	}
	else
	{	
		save_piece_data(line, map);
	//	ft_dprintf(fd, "piece = %d\n", map->y_p);
	}
}
