/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 12:03:39 by hshawand          #+#    #+#             */
/*   Updated: 2019/04/15 12:06:24 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char			*ft_strdup(const char *src)
{
	size_t		size;
	char		*dup;
	size_t		i;

	size = ft_strlen(src) + 1;
	dup = (char *)malloc(sizeof(char) * size);
	if (dup == 0)
		return (dup);
	i = 0;
	while (src[i] != '\0')
	{
		dup[i] = (char)(src[i]);
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
