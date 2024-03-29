/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:49:57 by smakni            #+#    #+#             */
/*   Updated: 2019/01/30 13:19:07 by smakni           ###   ########.fr       */
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

static	int		save_map_data(char *line, t_player *p)
{
	int i;

	i = 0;
	i = find_space(line, 0);
	p->m_y = ft_atoi(&line[i++]);
	i += find_space(line, i);
	p->m_x = ft_atoi(&line[i]);
	if (p->m_y > 0 && (p->map = ft_memalloc(sizeof(char *) * p->m_y)) == 0)
		return (-1);
	return (0);
}

static	int		save_piece_data(char *line, t_player *p)
{
	int i;

	i = 0;
	i = find_space(line, 0);
	p->p_y = ft_atoi(&line[i++]);
	i += find_space(line, i);
	p->p_x = ft_atoi(&line[i]);
	if (p->p_y > 0 && (p->piece = ft_memalloc(sizeof(char *) * p->p_y)) == 0)
		return (-1);
	return (0);
}

static	int		player_nb(char *line, t_player *p)
{
	if (ft_strstr(line, "p1") && ft_strstr(line, "smakni.filler"))
	{
		p->nb = 1;
		p->my_c = 'O';
		p->op_c = 'X';
		return (0);
	}
	else if (ft_strstr(line, "p2") && ft_strstr(line, "smakni.filler"))
	{
		p->nb = 2;
		p->my_c = 'X';
		p->op_c = 'O';
		return (0);
	}
	return (-1);
}

int				first_read(int fd, char *line, t_player *p)
{
	(void)fd;
	if (p->line == 0)
	{
		if (player_nb(line, p) == -1)
			return (-1);
		return (0);
	}
	else if (p->line == 1
			&& ft_strnequ("Plateau ", line, 8))
	{
		p->line = 1;
		if (p->check_read == 0 && save_map_data(line, p) == -1)
			return (-1);
		p->check_read++;
		return (0);
	}
	else if (p->line == p->m_y + 3 && ft_strnequ("Piece ", line, 6))
	{
		if (p->check_o == 0 || p->check_x == 0
				|| save_piece_data(line, p) == -1)
			return (-1);
		p->check_read++;
		return (0);
	}
	return (-1);
}
