/* **************************************************************************ksq */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:45:01 by smakni            #+#    #+#             */
/*   Updated: 2018/12/11 17:23:56 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_tabdel(char **tab, int len)
{
	while (len > 0)
	{
		ft_strdel(&tab[len - 1]);
		len--;
	}
	free(tab);
}
