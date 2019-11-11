/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <[hshawand@student.42.fr]>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:47:47 by hshawand          #+#    #+#             */
/*   Updated: 2019/11/11 14:02:49 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	vert_mov(int key, t_arg *args)
{
	while (!(args->flags & 0x02))
		args = args->next;
	args->flags &= ~0x02;
	if (key == 1)
	{
		args = args->prev;
		args->value ? 0 : (args = args->prev);
	}
	else if (key == 3)
	{
		args = args->next;
		args->value ? 0 : (args = args->next);
	}
}

void	keyctl(int key, t_arg *args)
{
	if (key == 1 || key == 3)
		vert_mov(key, args);
	else
		return ;
}
