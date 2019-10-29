/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:06:59 by hshawand          #+#    #+#             */
/*   Updated: 2019/09/26 14:51:29 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	long int		result;
	int				sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\f' || *str == '\r')
		str = str + 1;
	if (*str == '-')
	{
		sign = -1;
		str = str + 1;
	}
	else if (*str == '+')
		str = str + 1;
	while (*str >= '0' && *str <= '9')
	{
		if (sign * result > sign * (result * 10 + sign * (*str)))
			return (sign == 1 ? -1 : 0);
		result = result * 10 + sign * (*str - '0');
		str = str + 1;
	}
	return ((int)result);
}
