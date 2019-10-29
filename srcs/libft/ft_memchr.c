/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 11:33:36 by hshawand          #+#    #+#             */
/*   Updated: 2019/04/15 12:02:00 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*scan_b;
	unsigned char		ch;

	ch = (unsigned char)c;
	i = 0;
	scan_b = (unsigned char *)s;
	while (i < n)
	{
		if (scan_b[i] == ch)
			return (&scan_b[i]);
		i++;
	}
	return (NULL);
}
