/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <[hshawand@student.42.fr]>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:18:58 by hshawand          #+#    #+#             */
/*   Updated: 2019/11/12 16:02:46 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_args_print(t_arg *args)
{
	while (args->value)
	{
		tputs(tgoto(tgetstr("cm", NULL), args->coord_x, args->coord_y), 1, printc);
		args->flags & 0x01 ? tputs(tgetstr("us", NULL), 1, printc) : 0;
		args->flags & 0x02 ? tputs(tgetstr("mr", NULL), 1, printc) : 0;
		ft_putstr(args->value);
		args->flags & 0x01 ? tputs(tgetstr("ue", NULL), 1, printc) : 0;
		args->flags & 0x02 ? tputs(tgetstr("me", NULL), 1, printc) : 0;
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
	ioctl(0, TIOCGWINSZ, &win); /* Add error */
	x = 0;
	while (args->value)
	{
		y = 0;
		while (args->value && y < win.ws_row)
		{
			if (x + args->len  > win.ws_col)
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
	ft_coord_calc(args); /* TODO: Change! */
//		ft_args_print(args);
	ret = ft_loop(args);
	lst_free(&args);
	return(ret);
}
