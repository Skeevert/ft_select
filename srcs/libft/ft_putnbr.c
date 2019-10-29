/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 09:38:39 by hshawand          #+#    #+#             */
/*   Updated: 2019/04/08 10:46:12 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n)
{
	unsigned int		dec;
	char				digit;

	dec = 1;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	while (n / dec / 10 > 0)
		dec = dec * 10;
	while (dec >= 1)
	{
		digit = n / dec % 10 + '0';
		write(1, &digit, 1);
		dec = dec / 10;
	}
}
