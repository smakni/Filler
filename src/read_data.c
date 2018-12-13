/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:49:57 by smakni            #+#    #+#             */
/*   Updated: 2018/12/13 17:11:24 by smakni           ###   ########.fr       */
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

void			first_read(char *line, t_player *p)
{
	if (p->nb == 0)
		p->nb = ft_atoi(&(line[10]));
	else if (line[1] == 'l' && p->check_read == 0)
		save_map_data(line, p);
	else
	{
		p->check_read = 1;
		save_piece_data(line, p);
	}
}
