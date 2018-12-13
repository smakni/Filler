/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:10:23 by smakni            #+#    #+#             */
/*   Updated: 2018/12/13 15:57:44 by smakni           ###   ########.fr       */
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
	int		offset_y;
	int		offset_x;
	int		op_y;
	int		op_x;
	char	**map;
	char	**piece;
	int		i;
	int		j;
	int		check_read;
}				t_player;

void			algo(int fd, t_player *p);
int				save_data(t_player *p);
void			print_data(int fd, t_player *p);
void			first_read(char *line, t_player *p);
int				analyse_placement(t_player *p, int y, int x, int wid, int len);
int				analyse_y_p(t_player *p);
int				analyse_x_p(t_player *p);
void			find_opponent(t_player *p);
#endif
