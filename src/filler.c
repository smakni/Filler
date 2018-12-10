/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:06:40 by smakni            #+#    #+#             */
/*   Updated: 2018/12/10 23:18:34 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	algo(int fd, t_player *p)
{
	ft_dprintf(fd, "DEBUG\n");
	p->r_y = 8;
	p->r_x = 2;
	ft_dprintf(fd, "%d %d\n", 8, 2);
	ft_printf("%d %d\n", 8, 2);
}

void	init_player(t_player *p)
{
	p->nb = 0;
	p->m_y = 0;
	p->m_x = 0;
	p->p_y = 0;
	p->p_x = 0;
	p->r_y = 0;
	p->r_x = 0;
	p->map = NULL;
	p->piece = NULL;
	p->i = 0;
	p->check = 0;
}

int		main(void)
{
	t_player	*p;
	char		*line;
	int			fd;
	int			i;

	i = 0;
	line = NULL;
	p = ft_memalloc(sizeof(t_player));
	init_player(p);
	fd = open("trace", O_TRUNC | O_WRONLY);
	while (get_next_line(0, &line) > 0)
	{
		//ft_printf("%d %d\n", 8, 2);
		//ft_dprintf(fd, "%s\n", line);
		i = save_data(fd, line, p);
		ft_strdel(&line);
		if (i == 1)
			algo(fd, p);
	}
	free(p);
	return (0);
}
