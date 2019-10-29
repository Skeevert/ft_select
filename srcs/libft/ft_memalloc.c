/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:42:44 by hshawand          #+#    #+#             */
/*   Updated: 2019/04/15 12:57:25 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	void		*memory;
	char		*init;
	size_t		i;
	size_t		max;

	memory = malloc(size);
	if (!memory)
		return (NULL);
	init = (char *)memory;
	i = 0;
	max = size;
	while (i < max)
	{
		init[i] = 0;
		i++;
	}
	return (memory);
}
