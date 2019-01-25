/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:59:44 by smakni            #+#    #+#             */
/*   Updated: 2019/01/25 13:57:23 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static	int		save_map(int fd, t_player *p, char *line)
{
	int i;

	i = 4;
	if (p->check_read < 2 
			&& (p->map[p->i] = malloc(sizeof(char) * p->m_x)) == 0)
		exit (-1);
	while (i < p->m_x + 4)
	{
		if (line[i] != '.' && line[i] != '*' 
				&& line[i] != 'X' && line[i] != 'O')
			exit (-1);
		p->map[p->i][i - 4] = line[i];
		i++;
	}
	p->map[p->i][i] = '\0';
	ft_dprintf(fd, "vline = %s\n", line);
	ft_dprintf(fd, "saved_map = %s\n", p->map[p->i]);
	p->i++;
	return (1);
}

static	int		save_piece(int fd, t_player *p, char *line)
{
	int i;

	i = 0;
	if ((p->piece[p->j] = malloc(sizeof(char) * (p->p_x + 1))) == 0)
		exit (-1);
	while (i < p->p_x)
	{
		if (line[i] != '.' && line[i] != '*')
			exit (-1);
		ft_dprintf(fd, "line = %c\n", line[i]);
		p->piece[p->j][i] = line[i];
		i++;
	}
	p->piece[p->j][i] = '\0';
	ft_dprintf(fd, "saved_piece = %s\n", p->piece[p->j]);
	p->j++;
	return (2);
}

int				save_data(int fd, t_player *p)
{
	int		check;
	char	*line;

	check = 0;
	(void)fd;
	if (get_next_line(0, &line) > 0)
	{
		//ft_dprintf(fd, ">>>>line = %s ", line);
		//ft_dprintf(fd, ">>>> %d\n", p->line);
		first_read(fd, line, p);
		if (p->line > 2 && p->line <= p->m_y + 2)
			check = save_map(fd, p, line);
		else if (p->line >= p->m_y + 4 && p->line <= p->p_y + p->m_y + 4)
			check = save_piece(fd, p, line);
		ft_strdel(&line);
		p->line++;
		if (p->line == p->m_y + p->p_y + 4)
		{
			p->line = 1;
			return (1);
		}
	}
	return (0);
}
