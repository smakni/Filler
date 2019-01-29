/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:42:17 by smakni            #+#    #+#             */
/*   Updated: 2019/01/29 16:44:24 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	print_data(int fd, t_player *p)
{
	int i;

	i = 0;
	ft_dprintf(fd, "p%d\n", p->nb);
	ft_dprintf(fd, "map = %d | %d\n", p->m_y, p->m_x);
	while (i < p->m_y)
		ft_dprintf(fd, "%s\n", p->map[i++]);
	i = 0;
	ft_dprintf(fd, "piece = %d | %d\n", p->p_y, p->p_x);
	while (i < p->p_y)
		ft_dprintf(fd, "%s\n", p->piece[i++]);
}
