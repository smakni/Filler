/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:59:44 by smakni            #+#    #+#             */
/*   Updated: 2018/12/11 18:25:38 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static	int		find_space(char *line, int start)
{
	int i;

	i = 0;
	while(line[i + start] && line[i + start] != ' ')
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
	p->map = ft_memalloc(sizeof(char *) * (p->m_y + 1));
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

static	void	first_read(char *line, t_player *p)
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

int				save_data(t_player *p) //seg protection
{
	int i; 
	int j;
	int check;
	char *line;

	check = 0;
	i = 0;
	j = 0;
	if (get_next_line(0, &line) > 0)
	{
		if (line == NULL)
			exit(0);
		if (line[0] == 'P' || line[0] == '$')
			first_read(line, p);
		else if (line[0] == ' ' || ft_isdigit(line[0]) == 1)
		{
			if (p->check_read == 0)
				p->map[p->i] = ft_strdup(line);
			else
				ft_strcpy(p->map[p->i], line);	
			p->i++;
			check = 1;
		}
		else if (line[0] == '.' || line[0] == '*')
		{
			p->piece[p->j] = ft_strdup(line);	
			p->j++;
			check = 2;
		}
		ft_strdel(&line);
		if (check == 2 && p->j == p->p_y && p->i == p->m_y + 1)	
			return (1);
	}
	return (0);
}
