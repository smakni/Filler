/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:59:44 by smakni            #+#    #+#             */
/*   Updated: 2018/12/12 11:57:47 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static	int		save_map(t_player *p, char *line)
{
	if (p->check_read == 0)
		p->map[p->i] = ft_strsub(line, 4, p->m_x);
	else
		ft_strcpy_from(p->map[p->i], line, 4);	
	p->i++;
	return (1);
}

static	int		save_piece(t_player *p, char *line)
{
	p->piece[p->j] = ft_strdup(line);	
	p->j++;
	return (2);
}

int				save_data(t_player *p) //seg protection
{
	int check;
	char *line;

	check = 0;
	if (get_next_line(0, &line) > 0)
	{
		if (line[0] == 'P' || line[0] == '$')
			first_read(line, p);
		else if (ft_isdigit(line[0]) == 1)
			check = save_map(p, line);
		else if (line[0] == '.' || line[0] == '*')
			check = save_piece(p, line);		
		ft_strdel(&line);
		if (check == 2 && p->j == p->p_y && p->i == p->m_y)	
			return (1);
	}
	return (0);
}
