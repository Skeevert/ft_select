/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <[hshawand@student.42.fr]>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:47:47 by hshawand          #+#    #+#             */
/*   Updated: 2019/11/13 16:21:04 by hshawand         ###   ########.fr       */
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

int		finish_sel(t_arg *args)
{
	static t_arg	*save = 0;
	static t_arg	*s_start;
	char			flag;

	flag = 0;
	if (args)
		save = args;
	else if (save)
	{
		s_start = save;
		while (save->value)
		{
			if (save->flags & 0x02)
			{
				flag == 0 ? (flag = 1) : ft_putchar(' ');
				write(1, save->value, save->len);
			}
			save = save->next;
		}
		lst_free(&s_start);
	}
	return (0);
}

void	hor_mov(int key, t_arg *args)
{
	short	y_save;

	y_save = args->coord_y;
	if (key == 0)
	{
		args = args->next;
		while (!(args->value) || args->coord_y != y_save)
			args = args->next;
	}
	else
	{
		args = args->prev;
		while (!(args->value) || args->coord_y != y_save)
			args = args->prev;
	}
	args->flags |= 0x01;
}

void	vert_mov(int key, t_arg *args)
{
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
	args->flags |= 0x01;
}

void	keyctl(int key, t_arg *args)
{
	while (!(args->flags & 0x01) || !(args->value))
		args = args->next;
	args->flags &= ~0x01;
	if (key == 1 || key == 3)
		vert_mov(key, args);
	else if (key == 0 || key == 2)
		hor_mov(key, args);
	else if (key == 4)
	{
		args->flags & 0x02 ? (args->flags &= ~0x02) : (args->flags |= 0x02);
		args = args->next;
		args->value ? 0 : (args = args->next);
		args->flags |= 0x01;
	}
	return ;
}
