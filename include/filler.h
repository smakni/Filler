/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:10:23 by smakni            #+#    #+#             */
/*   Updated: 2019/01/30 16:19:56 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>

typedef	struct	s_player
{
	int		nb;
	char	my_c;
	char	op_c;
	int		m_y;
	int		m_x;
	int		p_y;
	int		p_x;
	int		r_y;
	int		r_x;
	int		offset_y;
	int		offset_x;
	int		save;
	int		save_path;
	char	**map;
	char	**piece;
	int		i;
	int		j;
	int		check_path;
	int		check_read;
	int		check_p;
	int		check_o;
	int		check_x;
	int		line;
}				t_player;

int				algo(int fd, t_player *p);
int				save_data(int fd, t_player *p);
void			print_data(int fd, t_player *p);
int				first_read(int fd, char *line, t_player *p);
void			analyse_map(int fd, t_player *p);
void			find_offset(int fd, t_player *p);
void			path(t_player *p, int y, int x);

#endif
