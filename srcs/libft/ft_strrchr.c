/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:38:34 by hshawand          #+#    #+#             */
/*   Updated: 2019/04/15 12:06:39 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *str, int c)
{
	size_t		count;

	count = 0;
	while (*str != '\0')
	{
		str = str + 1;
		count++;
	}
	while (count > 0)
	{
		if (*str == c)
			return ((char *)str);
		str = str - 1;
		count--;
	}
	if (*str == c)
		return ((char *)str);
	return (0);
}
