/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:06:40 by smakni            #+#    #+#             */
/*   Updated: 2018/12/10 19:45:48 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>
/*
void	ft_tabdel(char **tab)
{
	while (!tab)
		ft_strdel(tab);
}
*/

void	algo(int fd, char *line, t_map *map, t_player *p)
{
	if (line[0] == 'P' || line[0] == '$')
	{	
		//ft_dprintf(fd, "p->nb = %d\n", p->nb);
		first_read(fd, line, map, p);
	}
	p->y = 8;
	p->x = 2;
}

void	init_map_player(t_map *map, t_player *p)
{
	map->x = 0;
	map->y = 0;
	map->x_p = 0;
	map->y_p = 0;
	map->read = NULL;
	map->piece = NULL;
	p->nb = 0;
	p->y = 0;
	p->x = 0;
}

int		main(void)
{
	t_player	*p;
	t_map		*map;
	char		*line;
	int			fd;
	int			i;

	i = 0;
	line = NULL;
	p = ft_memalloc(sizeof(t_player));
	map = ft_memalloc(sizeof(t_map));
	init_map_player(map, p);
	fd = open("trace", O_TRUNC | O_WRONLY);
	while (get_next_line(0, &line) > 0)
	{
		algo(fd, line, map, p);
		ft_dprintf(fd, "%s\n", line);
		ft_strdel(&line);
		ft_printf("%d %d\n", p->y, p->x);
	}
	free(p);
	free(map);
	return (0);
}
