/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:18:58 by hshawand          #+#    #+#             */
/*   Updated: 2019/11/15 15:22:50 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_args_print(t_arg *args)
{
	char	buff[16];
	char	*ptr;

	ptr = buff;
	while (args->value)
	{
		tputs(tgoto(tgetstr("cm", &ptr), args->coord_x, args->coord_y),
			1, printc);
		ptr = buff;
		args->flags & 0x01 ? putcap("us") : 0;
		args->flags & 0x02 ? putcap("mr") : 0;
		write(2, args->value, ft_strlen(args->value));
		args->flags & 0x01 ? putcap("ue") : 0;
		args->flags & 0x02 ? putcap("me") : 0;
		args = args->next;
	}
	return (0);
}

int		ft_coord_calc(t_arg *args)
{
	struct winsize	win;
	size_t			len_max;
	unsigned short	x;
	unsigned short	y;

	len_max = 0;
	if (ioctl(0, TIOCGWINSZ, &win) == -1)
		return (ft_error_int("cannot get window size\n"));
	x = 0;
	while (args->value)
	{
		y = 0;
		while (args->value && y < win.ws_row)
		{
			if (x + args->len > win.ws_col)
				return (-1);
			args->len > len_max ? (len_max = args->len) : 0;
			args->coord_x = x;
			args->coord_y = y;
			y++;
			args = args->next;
		}
		x += len_max + 1;
	}
	return (0);
}

int		init_arg(int argc, char **argv)
{
	int		i;
	t_arg	*args;
	t_arg	*last;
	int		ret;

	i = 1;
	if (!(args = arg_new()))
		return (ft_error_int("cannot allocate enough memory"));
	last = args;
	while (i < argc)
	{
		args->flags = 0;
		args->value = argv[i];
		args->len = ft_strlen(argv[i++]);
		if (arg_add(&args, arg_new()))
			return (ft_error_int("cannot allocate enough memory"));
	}
	args->value = 0;
	last->next = args;
	args->prev = last;
	args = args->next;
	ret = ft_loop(args);
	return (ret);
}
