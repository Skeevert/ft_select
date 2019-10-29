/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:12:11 by hshawand          #+#    #+#             */
/*   Updated: 2019/04/15 12:20:22 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strnew(size_t size)
{
	char	*string;
	size_t	i;
	size_t	max;

	if (size + 1 == 0)
		return (NULL);
	string = (char *)malloc(size + 1);
	if (!string)
		return (NULL);
	i = 0;
	max = size + 1;
	while (i < max)
	{
		string[i] = '\0';
		i++;
	}
	return (string);
}
