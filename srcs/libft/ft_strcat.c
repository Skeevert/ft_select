/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 12:28:37 by hshawand          #+#    #+#             */
/*   Updated: 2019/04/05 15:45:47 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *destination, const char *source)
{
	unsigned int	i;

	i = 0;
	while (destination[i] != '\0')
		i++;
	while (*source != '\0')
	{
		destination[i] = *source;
		i++;
		source = source + 1;
	}
	destination[i] = '\0';
	return (destination);
}
