/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:25:27 by smakni            #+#    #+#             */
/*   Updated: 2018/04/12 16:44:24 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned long i;
	unsigned long x;

	i = 0;
	x = 0;
	while (s1[x])
		x++;
	while (i < n && s2[i])
	{
		s1[x + i] = s2[i];
		i++;
	}
	s1[x + i] = '\0';
	return (s1);
}
