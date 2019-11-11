/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <[hshawand@student.42.fr]>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:18:58 by hshawand          #+#    #+#             */
/*   Updated: 2019/11/11 12:55:19 by hshawand         ###   ########.fr       */
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
		args++;
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
			args++;
		}
		x += len_max + 1;
	}
	return (0);
}

int		init_arg(int argc, char **argv)
{
	int		i;
	int		j;
	t_arg	*args;
	int		ret;

	i = 1;
	j = 0;
	if (!(args = (t_arg *)malloc(sizeof(t_arg) * argc)))
		return (ft_error_int("cannot allocate enough memory"));
	while (i < argc)
	{
		args[j].flags = 0;
		args[j].value = argv[i];
		args[j].len = ft_strlen(argv[i]);
		i++;
		j++;
	}
	args[j].value = 0;
//	args[0].flags |= 0x01;
//	args[1].flags |= 0x02;
//	args[2].flags |= 0x03;
	if (!ft_coord_calc(args)) /* TODO: Change! */
		ft_args_print(args);
	ret = ft_loop(args);
	free(args);
	return(ret);
}
