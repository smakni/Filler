/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:06:40 by smakni            #+#    #+#             */
/*   Updated: 2018/12/05 14:02:20 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		main(int ac, char **av)
{
	char *line;
	int fd;
	int first;

	(void)ac;
	(void)av;
	fd = open("trace", O_TRUNC | O_WRONLY);
	first = 0;
	while(get_next_line(0, &line) > 0)
	{
		ft_printf("%d %d\n", 8, 2);
		ft_dprintf(fd, "%s\n", line);
		ft_strdel(&line);
	}
	return (0);
}
