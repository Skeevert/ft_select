/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stroffcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 13:35:50 by hshawand          #+#    #+#             */
/*   Updated: 2019/09/20 13:37:31 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stroffcat(char *dst, const char *src, size_t num, char mode)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	if (mode)
		while (num)
		{
			dst[i] = src[j] ? src[j] : ' ';
			i++;
			src[j] ? j++ : 0;
			num--;
		}
	else
		while (num)
		{
			dst[i] = num > ft_strlen(src) ? ' ' : src[j];
			num > ft_strlen(src) ? 0 : j++;
			num--;
			i++;
		}
	dst[i] = 0;
	return (dst);
}
