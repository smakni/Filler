/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:59:44 by smakni            #+#    #+#             */
/*   Updated: 2019/01/29 16:24:16 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static	void	save_map(int fd, t_player *p, char *line)
{
	int i;

	i = 4;
	if (p->check_read < 2 
			&& (p->map[p->i] = malloc(sizeof(char) * (p->m_x + 1))) == 0)
		exit (-1);
	if ((int)ft_strlen(line) != p->m_x + 4)
		exit (-1);
	while (line[i])
	{
		if (line[i] != '.' && line[i] != 'X' && line[i] != 'O')
			exit (-1);
		if (line[i] == 'X')
			p->check_x++;
		if (line[i] == 'O')
			p->check_o++;
		p->map[p->i][i - 4] = line[i];
		i++;
	}
	p->map[p->i][i - 4] = '\0';
	//ft_dprintf(fd, "vline = %s\n", line);
	ft_dprintf(fd, "saved_map = %s\n", p->map[p->i]);
	p->i++;
}

static	void	save_piece(int fd, t_player *p, char *line)
{
	int i;

	i = 0;
	if ((p->piece[p->j] = malloc(sizeof(char) * (p->p_x + 1))) == 0)
		exit (-1);
	if ((int)ft_strlen(line) != p->p_x)
		exit (-1);
	while (line[i])
	{
		if (line[i] != '.' && line[i] != '*')
			exit (-1);
		//ft_dprintf(fd, "line = %c\n", line[i]);
		p->piece[p->j][i] = line[i];
		i++;
	}
	p->piece[p->j][i] = '\0';
	ft_dprintf(fd, "saved_piece = %s\n", p->piece[p->j]);
	p->j++;
}

int				save_data(int fd, t_player *p)
{
	char	*line;

	(void)fd;
	if (get_next_line(0, &line) > 0)
	{
		//ft_dprintf(fd, ">>>>line = %s ", line);
		//ft_dprintf(fd, ">>>> %d\n", p->line);
		if (line[0] == '\0')
			exit(-1);
		if (p->nb == 0 || p->line == 1 || p->line == p->m_y + 3)
			first_read(fd, line, p);
		else if (p->line > 2 && p->line <= p->m_y + 2)
			save_map(fd, p, line);
		else if (p->line >= p->m_y + 4 && p->line <= p->p_y + p->m_y + 4)
			save_piece(fd, p, line);
		else if (p->line != 2)
			exit (-1);
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
