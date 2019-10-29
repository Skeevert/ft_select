/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:38:47 by hshawand          #+#    #+#             */
/*   Updated: 2019/04/15 17:43:44 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	size_t				i;
	char				*fill;
	char				*src_data;

	i = 0;
	if (!destination && !source)
		return (NULL);
	fill = (char *)destination;
	src_data = (char *)source;
	while (i < num)
	{
		fill[i] = src_data[i];
		i++;
	}
	return (destination);
}
