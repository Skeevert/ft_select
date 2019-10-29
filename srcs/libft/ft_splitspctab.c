/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:45:02 by hshawand          #+#    #+#             */
/*   Updated: 2019/09/26 13:55:01 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static size_t	ft_word_count(char const *s)
{
	size_t		amount;

	s = s + 1;
	amount = 0;
	while (*s && *(s - 1))
	{
		if (WHTSPC(*s) && !WHTSPC(*(s - 1)))
			amount++;
		s = s + 1;
	}
	return (amount + 1);
}

static char		*ft_word_alloc(char const *s)
{
	size_t		size;
	char		*space;

	size = 0;
	while (!WHTSPC(s[size]) && s[size])
		size++;
	space = (char *)malloc(sizeof(char) * (size + 2));
	return (space);
}

static int		ft_arr_form(char **array, size_t word_amount,
		char const *s)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (WHTSPC(*s) && *s)
		s = s + 1;
	while (i < word_amount && *s)
	{
		j = 0;
		array[i] = ft_word_alloc(s);
		if (!array[i])
			return (-1);
		while (!WHTSPC(*s) && *s)
		{
			array[i][j] = *s;
			s = s + 1;
			j++;
		}
		while (WHTSPC(*s) && *s)
			s = s + 1;
		array[i][j] = '\0';
		i++;
	}
	array[i] = NULL;
	return (0);
}

static void		ft_arr_clean(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char			**ft_splitspctab(char const *s)
{
	char				**array;
	size_t				word_amount;

	if (!s)
		return (0);
	word_amount = ft_word_count(s);
	array = (char **)malloc(sizeof(char *) * (word_amount + 1));
	if (!array)
		return (NULL);
	if (ft_arr_form(array, word_amount, s))
	{
		ft_arr_clean(array);
		return (NULL);
	}
	return (array);
}
