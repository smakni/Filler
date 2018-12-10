/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:59:44 by smakni            #+#    #+#             */
/*   Updated: 2018/12/10 18:57:47 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static	int	find_space(char *line, int start)
{
	int i;

	i = 0;
	while(line[i + start] && line[i + start] != ' ')
		i++;
	return (i);
}

void		save_map_data(char *line, t_map *map)
{
	int i;

	i = 0;
	i = find_space(line, 0);	
	map->y = ft_atoi(&line[i++]);
	i += find_space(line, i);
	map->x = ft_atoi(&line[i]);
	map->piece = ft_memalloc(sizeof(char *) * map->y);
}

void		save_piece_data(char *line, t_map *map)
{
	int i;

	i = 0;
	i = find_space(line, 0);	
	map->y_p = ft_atoi(&line[i++]);
	i += find_space(line, i);
	map->x_p = ft_atoi(&line[i]);
	map->piece = ft_memalloc(sizeof(char *) * map->y_p);
}
