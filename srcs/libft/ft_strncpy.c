/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 12:15:33 by hshawand          #+#    #+#             */
/*   Updated: 2019/09/17 13:42:12 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *destination, const char *source, size_t num)
{
	size_t		i;

	i = 0;
	while (source[i] != '\0' && i < num)
	{
		destination[i] = source[i];
		i++;
	}
	while (i < num)
	{
		destination[i] = 0;
		i++;
	}
	return (destination);
}
