/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:52:08 by hshawand          #+#    #+#             */
/*   Updated: 2019/04/15 12:00:48 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*fill;
	unsigned char		*src_data;
	unsigned char		ch;

	i = 0;
	ch = (unsigned char)c;
	fill = (unsigned char *)dest;
	src_data = (unsigned char *)src;
	while (i < n)
	{
		fill[i] = src_data[i];
		if (fill[i] == ch)
			return (&fill[i + 1]);
		i++;
	}
	return (NULL);
}
