/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:59:44 by smakni            #+#    #+#             */
/*   Updated: 2018/12/10 23:18:36 by smakni           ###   ########.fr       */
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
	p->map = ft_memalloc(sizeof(char *) * p->m_y);
	p->check = 1;
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

static	void	first_read(int fd, char *line, t_player *p)
{
	if (p->nb == 0)
	{	
		p->nb = ft_atoi(&(line[10]));
		ft_dprintf(fd, "p = %d\n", p->nb);
	}
	else if (line[1] == 'l' && p->check == 0)
	{
		save_map_data(line, p);
		ft_dprintf(fd, "map = %d\n", p->m_y);
	}
	else
	{	
		save_piece_data(line, p);
		ft_dprintf(fd, "piece = %d\n", p->p_y);
	}
}

int				save_data(int fd, char *line, t_player *p)
{
	int 		check;

	check = 0;
	if (line[0] == 'P' || line[0] == '$')
	{	
		first_read(fd, line, p);
		check = 1;
	}
	else if (line[0] == ' ' || ft_isdigit(line[0]) == 1)
	{
		p->map[p->i] = ft_strdup(line);	
		ft_dprintf(fd, "p->map[%2d] = %s\n", p->i, p->map[p->i]);
		check = 2;
	}
	else if (line[0] == '.' || line[0] == '*')
	{
		p->piece[p->i] = ft_strdup(line);	
		ft_dprintf(fd, "p->piece[%2d] = %s\n", p->i, p->piece[p->i]);
		check = 3;
	}
	if (p->i == p->p_y - 1 && check == 3)
	{
		p->i = 0;
		return (1);
	}
	else if ((p->i == p->m_y && check == 2))
		p->i = 0;
	else if (check != 1)
		p->i++;
	return (0);
}
