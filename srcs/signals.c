/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:04:07 by hshawand          #+#    #+#             */
/*   Updated: 2019/11/19 15:23:34 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	suspend_handle(void)
{
	putcap("ve");
	putcap("te");
	term_reconfig(0);
	signal(SIGTSTP, SIG_DFL);
	ioctl(2, TIOCSTI, "\032");
}

static void	continue_handle(void)
{
	term_reconfig(1);
	putcap("ti");
	putcap("vi");
	redraw(0, 0);
	signal_catch();
}

static void	signal_handler(int sig)
{
	if (sig == SIGWINCH)
	{
		redraw(0, 0);
		signal(SIGWINCH, signal_handler);
	}
	else if (sig == SIGINT || sig == SIGQUIT)
	{
		putcap("ve");
		putcap("te");
		term_reconfig(0);
		lst_free(0);
		exit(0);
	}
	else if (sig == SIGTSTP)
		suspend_handle();
	else if (sig == SIGCONT)
		continue_handle();
}

void		signal_catch(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	signal(SIGWINCH, signal_handler);
	signal(SIGTSTP, signal_handler);
	signal(SIGCONT, signal_handler);
}
