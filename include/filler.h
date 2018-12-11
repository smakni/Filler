/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:10:23 by smakni            #+#    #+#             */
/*   Updated: 2018/12/11 17:52:08 by smakni           ###   ########.fr       */
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
	int		j;
	int		check_read;
}				t_player;

int				save_data(t_player *p);
void			print_data(int fd, t_player *p);

#endif
