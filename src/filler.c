/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:06:40 by smakni            #+#    #+#             */
/*   Updated: 2019/01/30 16:34:25 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	init_player(t_player *p)
{
	p->nb = 0;
	p->my_c = 0;
	p->op_c = 0;
	p->m_y = 0;
	p->m_x = 0;
	p->p_y = 0;
	p->p_x = 0;
	p->r_y = 0;
	p->r_x = 0;
	p->offset_y = 0;
	p->offset_x = 0;
	p->map = NULL;
	p->piece = NULL;
	p->i = 0;
	p->j = 0;
	p->save = 0;
	p->save_path = 0;
	p->check_path = 0;
	p->check_read = 0;
	p->check_p = 0;
	p->check_x = 0;
	p->check_o = 0;
	p->line = 0;
}

int		main(void)
{
	t_player	*p;
	int			fd;
	int			error;

	p = ft_memalloc(sizeof(t_player));
	init_player(p);
	fd = open("trace", O_TRUNC | O_WRONLY);
	while (1)
	{
		if ((error = save_data(fd, p)) == 1)
		{
			analyse_map(fd, p);
			print_data(fd, p);
			if (algo(fd, p) == -1)
				break ;
			ft_tabdel(p->piece, p->p_y);
		}
		else if (error == -1)
			break ;
	}
	if (error != -1)
		ft_printf("0 0\n");
	ft_tabdel(p->map, p->m_y);
	free(p);
	return (0);
}
