/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:49:57 by smakni            #+#    #+#             */
/*   Updated: 2019/01/25 14:30:01 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static	int		find_space(char *line, int start)
{
	int i;

	i = 0;
	while (line[i + start] && line[i + start] != ' ')
		i++;
	return (i);
}

static	void	save_map_data(char *line, t_player *p)
{
	int i;

	i = 0;
	i = find_space(line, 0);
	p->m_y = ft_atoi(&line[i++]);
	i += find_space(line, i);
	p->m_x = ft_atoi(&line[i]);
	p->map = ft_memalloc(sizeof(char *) * (p->m_y));
}

static	void	save_piece_data(char *line, t_player *p)
{
	int i;

	i = 0;
	i = find_space(line, 0);
	p->p_y = ft_atoi(&line[i++]);
	i += find_space(line, i);
	p->p_x = ft_atoi(&line[i]);
	p->piece = ft_memalloc(sizeof(char *) * p->p_y);
}

void			first_read(int fd, char *line, t_player *p)
{
	if (p->nb == 0)
	{
		ft_dprintf(fd, "line = %s\n", line);
		if (ft_strstr(line, "p1") && ft_strstr(line, "smakni.filler"))
		{
			p->nb = 1;
			p->my_c = 'O';
			p->op_c = 'X';
		}
		else if (ft_strstr(line, "p2") && ft_strstr(line, "smakni.filler"))
		{
			p->nb = 2;
			p->my_c = 'X';
			p->op_c = 'O';
		}
		else
			exit (-1);
	}
	else if (ft_strnequ("Plateau ", line, 8) && p->check_read == 0)
	{
		p->line = 1;
		ft_dprintf(fd, "Plateau_line = %s\n", line);
		save_map_data(line, p);
		p->check_read++;
	}
	else if (ft_strnequ("Piece ", line, 6))
	{
		ft_dprintf(fd, "Piece_line = %s\n", line);
		p->check_read++;
		save_piece_data(line, p);
	}
}
