/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:10:23 by smakni            #+#    #+#             */
/*   Updated: 2018/12/10 23:13:37 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>

typedef	struct	s_player
{
	int 	nb;
	int 	m_y;
	int		m_x;
	int		p_y;
	int		p_x;
	int 	r_y;
	int 	r_x;
	char	**map;
	char	**piece;
	int		i;
	int		check;
}				t_player;

int				save_data(int fd, char *line, t_player *p);


#endif
