/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:49:30 by hshawand          #+#    #+#             */
/*   Updated: 2019/04/15 12:16:52 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static size_t	ft_count(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_strmap(char const *s, char (*f)(char))
{
	size_t		size;
	char		*result;
	size_t		i;

	if (!s || !f)
		return (0);
	size = ft_count(s) + 1;
	result = (char *)malloc(sizeof(char) * size);
	if (!result)
		return (result);
	i = 0;
	while (s[i])
	{
		result[i] = (*f)(s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
