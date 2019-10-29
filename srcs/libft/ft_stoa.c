/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:12:05 by hshawand          #+#    #+#             */
/*   Updated: 2019/09/20 17:20:37 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static void		ft_fill(char *output, size_t dec, size_t n)
{
	size_t		i;

	i = 0;
	while (dec >= 1)
	{
		output[i++] = n / dec % 10 + '0';
		dec = dec / 10;
	}
	output[i] = '\0';
}

char			*ft_stoa(size_t n)
{
	size_t		size;
	size_t		dec;
	char		*output;

	size = 0;
	dec = 1;
	while (n / dec / 10 != 0)
	{
		size++;
		dec = dec * 10;
	}
	output = (char *)malloc(sizeof(char) * (size + 2));
	if (!output)
		return (NULL);
	ft_fill(output, dec, n);
	return (output);
}
