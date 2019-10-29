/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 11:54:33 by hshawand          #+#    #+#             */
/*   Updated: 2019/04/15 12:02:09 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t				i;
	unsigned char		*com_1;
	unsigned char		*com_2;

	i = 0;
	com_1 = (unsigned char *)ptr1;
	com_2 = (unsigned char *)ptr2;
	while (i < num)
	{
		if (com_1[i] != com_2[i])
			return (com_1[i] - com_2[i]);
		i++;
	}
	return (0);
}
