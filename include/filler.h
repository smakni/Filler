/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:10:23 by smakni            #+#    #+#             */
/*   Updated: 2018/12/10 19:45:44 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>

typedef	struct	s_map
{
	int		x;
	int 	y;
	int		x_p;
	int		y_p;
	char	**read;
	char	**piece;
}				t_map;

typedef	struct	s_player
{
	int nb;
	int y;
	int x;
}				t_player;

void			first_read(int fd, char *line, t_map *map, t_player *p);
void			save_map_data(char *line, t_map *map);
void			save_piece_data(char *line, t_map *map);


#endif
