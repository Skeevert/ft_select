/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:51:49 by hshawand          #+#    #+#             */
/*   Updated: 2019/11/19 13:14:28 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		arg_add(t_arg **alst, t_arg *new)
{
	if (!alst || !new)
		return (-1);
	new->next = *alst;
	(*alst)->prev = new;
	*alst = new;
	return (0);
}

t_arg	*arg_new(void)
{
	t_arg	*new;

	if (!(new = (t_arg *)malloc(sizeof(t_arg))))
		return (0);
	ft_bzero(new, sizeof(t_arg));
	return (new);
}

void	lst_free(t_arg **start)
{
	static t_arg	*save;
	t_arg			*temp;

	if (start)
		save = *start;
	else
	{
		(save)->prev->value = 0;
		while ((save)->value)
		{
			temp = save;
			save = (save)->next;
			free(temp);
		}
		free(save);
	}
}
