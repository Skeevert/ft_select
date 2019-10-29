/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:45:02 by hshawand          #+#    #+#             */
/*   Updated: 2019/04/15 17:33:46 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static size_t	ft_word_count(char const *s, char c)
{
	size_t		amount;

	s = s + 1;
	amount = 0;
	while (*s && *(s - 1))
	{
		if (*s == c && *(s - 1) != c)
			amount++;
		s = s + 1;
	}
	return (amount + 1);
}

static char		*ft_word_alloc(char const *s, char c)
{
	size_t		size;
	char		*space;

	size = 0;
	while (s[size] != c && s[size])
		size++;
	space = (char *)malloc(sizeof(char) * (size + 2));
	return (space);
}

static int		ft_arr_form(char **array, size_t word_amount,
		char const *s, char c)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (*s == c && *s)
		s = s + 1;
	while (i < word_amount && *s)
	{
		j = 0;
		array[i] = ft_word_alloc(s, c);
		if (!array[i])
			return (-1);
		while (*s != c && *s)
		{
			array[i][j] = *s;
			s = s + 1;
			j++;
		}
		while (*s == c && *s)
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

char			**ft_strsplit(char const *s, char c)
{
	char				**array;
	size_t				word_amount;

	if (!s)
		return (0);
	word_amount = ft_word_count(s, c);
	array = (char **)malloc(sizeof(char *) * (word_amount + 1));
	if (!array)
		return (NULL);
	if (ft_arr_form(array, word_amount, s, c))
	{
		ft_arr_clean(array);
		return (NULL);
	}
	return (array);
}
