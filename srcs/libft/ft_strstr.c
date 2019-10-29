/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:52:31 by hshawand          #+#    #+#             */
/*   Updated: 2019/04/05 16:12:38 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_scan(const char *str1, const char *str2)
{
	while (*str2 != '\0')
	{
		if (*str1 != *str2)
			return (0);
		str1 = str1 + 1;
		str2 = str2 + 1;
	}
	return (1);
}

char			*ft_strstr(const char *str1, const char *str2)
{
	if (*str2 == '\0')
		return ((char *)str1);
	while (*str1 != '\0')
	{
		if (*str1 == *str2)
			if (ft_scan(str1, str2))
				return ((char *)str1);
		str1 = str1 + 1;
	}
	return (0);
}
