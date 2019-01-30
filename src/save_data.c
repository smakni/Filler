/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:59:44 by smakni            #+#    #+#             */
/*   Updated: 2019/01/30 16:34:28 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static	int		save_map(int fd, t_player *p, char *line)
{
	int i;

	i = 4;
	(void)fd;
	if ((int)ft_strlen(line) != p->m_x + 4)
		return (-1);
	if (p->check_read < 2
			&& (p->map[p->i] = ft_memalloc(sizeof(char) * (p->m_x + 1))) == 0)
		return (-1);
	while (line[i])
	{
		if (line[i] != '.' && line[i] != 'X' && line[i] != 'O')
			return (-1);
		if (line[i] == 'X')
			p->check_x++;
		if (line[i] == 'O')
			p->check_o++;
		p->map[p->i][i - 4] = line[i];
		i++;
	}
	p->map[p->i][i - 4] = '\0';
	p->i++;
	return (0);
}

static	int		save_piece(int fd, t_player *p, char *line)
{
	int i;

	i = 0;
	(void)fd;
	if ((int)ft_strlen(line) != p->p_x)
		return (-1);
	if ((p->piece[p->j] = ft_memalloc(sizeof(char) * (p->p_x + 1))) == 0)
		return (-1);
	while (line[i])
	{
		if (line[i] != '.' && line[i] != '*')
			return (-1);
		p->piece[p->j][i] = line[i];
		i++;
	}
	p->piece[p->j][i] = '\0';
	p->j++;
	return (0);
}

static	int		check_end(char *line, t_player *p, int error)
{
	ft_strdel(&line);
	p->line++;
	if (error == -1)
	{
		ft_tabdel(p->piece, p->p_y);
		return (error);
	}
	if (p->line == p->m_y + p->p_y + 4)
	{
		p->line = 1;
		return (1);
	}
	return (0);
}

int				save_data(int fd, t_player *p)
{
	char	*line;
	int		error;

	(void)fd;
	error = 0;
	if (get_next_line(0, &line) > 0)
	{
		if (line[0] == '\0')
			error = -1;
		else if (error == 0
				&& (p->nb == 0 || p->line == 1 || p->line == p->m_y + 3))
			error = first_read(fd, line, p);
		else if (error == 0 && p->line > 2 && p->line <= p->m_y + 2)
			error = save_map(fd, p, line);
		else if (error == 0
				&& p->line >= p->m_y + 4 && p->line <= p->p_y + p->m_y + 4)
			error = save_piece(fd, p, line);
		else if (p->line != 2)
			error = -1;
		return (check_end(line, p, error));
	}
	return (0);
}
