/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:56:41 by hshawand          #+#    #+#             */
/*   Updated: 2019/10/07 13:45:21 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*output;

	if (!s2)
		return (0);
	if (!s1)
	{
		if (!(output = (char *)malloc(ft_strlen(s2) + 1)))
			return (0);
		ft_strcpy(output, s2);
	}
	else
	{
		if (!(output = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (0);
		strcpy(output, s1);
		strcat(output, s2);
	}
	return (output);
}
