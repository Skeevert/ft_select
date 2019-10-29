/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:48:10 by hshawand          #+#    #+#             */
/*   Updated: 2019/04/05 17:01:58 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t num)
{
	unsigned char	*str1;
	unsigned char	*str2;

	if (num == 0)
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (*str1 != '\0' && num > 0)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1 = str1 + 1;
		str2 = str2 + 1;
		num--;
	}
	if (num == 0)
		return (0);
	else
		return (*str1 - *str2);
}
