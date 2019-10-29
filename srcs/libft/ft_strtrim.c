/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:19:14 by hshawand          #+#    #+#             */
/*   Updated: 2019/09/12 13:38:48 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static size_t	ft_memory_count(char const *s)
{
	size_t count;

	count = 0;
	if (!(*s))
		return (0);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s = s + 1;
	while (*s)
	{
		count++;
		s = s + 1;
	}
	count++;
	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\0')
	{
		if (count == 0)
			return (0);
		count--;
		s = s - 1;
	}
	return (count);
}

char			*ft_strtrim(char const *s)
{
	size_t			size;
	char			*trim;
	size_t			i;

	if (!s)
		return (NULL);
	size = ft_memory_count(s);
	i = 0;
	trim = (char *)malloc(sizeof(char) * (size + 1));
	if (!trim)
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s = s + 1;
	while (i < size)
	{
		trim[i] = *s;
		s = s + 1;
		i++;
	}
	trim[i] = '\0';
	return (trim);
}
