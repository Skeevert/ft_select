/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:38:08 by hshawand          #+#    #+#             */
/*   Updated: 2019/04/05 16:46:10 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int	ft_scan(const char *str1, const char *str2, size_t len, size_t i)
{
	while (*str2 != '\0')
	{
		if (*str1 != *str2 || i >= len)
			return (0);
		str1 = str1 + 1;
		str2 = str2 + 1;
		i++;
	}
	return (1);
}

char		*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t		i;

	i = 0;
	if (*str2 == '\0')
		return ((char *)str1);
	while (*str1 != '\0' && i < len)
	{
		if (*str1 == *str2)
			if (ft_scan(str1, str2, len, i))
				return ((char *)str1);
		str1 = str1 + 1;
		i++;
	}
	return (0);
}
