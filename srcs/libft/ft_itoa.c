/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:56:39 by hshawand          #+#    #+#             */
/*   Updated: 2019/09/12 14:10:53 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static void		ft_fill(char *output, int dec, int n)
{
	int				i;
	unsigned int	unsig_n;

	i = 0;
	if (n < 0)
	{
		output[i++] = '-';
		unsig_n = (unsigned int)-n;
	}
	else
		unsig_n = (unsigned int)n;
	while (dec >= 1)
	{
		output[i++] = unsig_n / dec % 10 + '0';
		dec = dec / 10;
	}
	output[i] = '\0';
}

char			*ft_itoa(int n)
{
	int		size;
	int		dec;
	char	*output;

	size = 0;
	dec = 1;
	while (n / dec / 10 != 0)
	{
		size++;
		dec = dec * 10;
	}
	if (n < 0)
		size++;
	output = (char *)malloc(sizeof(char) * (size + 2));
	if (!output)
		return (NULL);
	ft_fill(output, dec, n);
	return (output);
}
