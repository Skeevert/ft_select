/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:27:31 by hshawand          #+#    #+#             */
/*   Updated: 2019/11/15 16:11:59 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		putcap(char *cap)
{
	char	buff[16];
	char	*ptr;

	ptr = buff;
	tputs(tgetstr(cap, &ptr), 1, printc);
	return (0);
}

int		ft_error_int(char *msg)
{
	write(2, "Error: ", 7);
	write(2, msg, strlen(msg));
	return (-1);
}

void	redraw(t_arg *args, int *w_state)
{
	static t_arg	*saved = 0;
	static int		*state;

	if (w_state)
		state = w_state;
	if (args)
		saved = args;
	if (saved)
	{
		putcap("cl");
		if (!ft_coord_calc(saved))
		{
			ft_args_print(saved);
			*state = 0;
		}
		else
		{
			ft_error_int("window size too small. Resize window\n");
			*state = 1;
		}
	}
}

void	signal_handler(int sig)
{
	if (sig == SIGWINCH)
	{
		redraw(0, 0);
		signal(SIGWINCH, signal_handler);
	}
}

int		printc(int c)
{
	return (write(2, &c, 1));
}
