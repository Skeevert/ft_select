/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:25:50 by hshawand          #+#    #+#             */
/*   Updated: 2019/04/15 12:02:43 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *destination, int c, size_t n)
{
	size_t				i;
	char				*fill;

	i = 0;
	fill = (char *)destination;
	while (i < n)
		fill[i++] = c;
	return (destination);
}
