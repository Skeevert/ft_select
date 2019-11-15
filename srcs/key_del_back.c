/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_del_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:39:56 by hshawand          #+#    #+#             */
/*   Updated: 2019/11/15 15:23:03 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_arg	*keyback(t_arg *args)
{
	t_arg	*to_del;

	while (!(args->flags & 0x01) || !(args->value))
		args = args->next;
	to_del = args->prev->value ? args->prev : args->prev->prev;
	if (to_del == args)
	{
		free(to_del->next);
		free(to_del);
		return (0);
	}
	to_del->prev->next = to_del->next;
	to_del->next->prev = to_del->prev;
	free(to_del);
	while (args->prev->value)
		args = args->next;
	ft_coord_calc(args);
	return (args);
}

t_arg	*keydel(t_arg *args)
{
	t_arg	*to_del;

	while (!(args->flags & 0x01) || !(args->value))
		args = args->next;
	to_del = args;
	args = args->next;
	to_del->prev->next = args;
	args->prev = to_del->prev;
	free(to_del);
	if (args == args->next)
	{
		free(args);
		return (0);
	}
	args->value ? (args->flags |= 0x01) : (args->next->flags |= 0x01);
	while (args->prev->value)
		args = args->next;
	ft_coord_calc(args);
	return (args);
}
