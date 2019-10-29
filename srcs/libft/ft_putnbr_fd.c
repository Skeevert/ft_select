/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:01:16 by hshawand          #+#    #+#             */
/*   Updated: 2019/04/08 10:46:55 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int		dec;
	char				digit;

	dec = 1;
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	while (n / dec / 10 > 0)
		dec = dec * 10;
	while (dec >= 1)
	{
		digit = n / dec % 10 + '0';
		write(fd, &digit, 1);
		dec = dec / 10;
	}
}
