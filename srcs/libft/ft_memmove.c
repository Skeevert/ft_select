/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 11:04:29 by hshawand          #+#    #+#             */
/*   Updated: 2019/04/09 09:20:19 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t num)
{
	size_t		i;

	if (source >= destination)
		ft_memcpy(destination, source, num);
	else
	{
		i = 1;
		while ((int)(num - i) >= 0)
		{
			((char *)destination)[num - i] = ((char *)source)[num - i];
			i++;
		}
	}
	return (destination);
}
