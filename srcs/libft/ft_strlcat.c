/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:19:10 by hshawand          #+#    #+#             */
/*   Updated: 2019/04/05 15:21:50 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		n;
	size_t		dlen;
	char		*d;
	char		*s;

	n = size;
	d = dst;
	s = (char *)src;
	while (n-- != 0 && *d != '\0')
		d = d + 1;
	dlen = d - dst;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen((char *)src));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}
