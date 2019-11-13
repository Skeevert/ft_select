/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <[hshawand@student.42.fr]>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:25:15 by hshawand          #+#    #+#             */
/*   Updated: 2019/11/13 15:05:59 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_error_int(char *msg)
{
	write(2, "Error: ", 7);
	write(2, msg, strlen(msg));
	return (-1);
}

void	redraw(t_arg *args)
{
	static t_arg *saved = 0;

	if (args)
		saved = args;
	if (saved)
	{
		tputs(tgetstr("cl", NULL), 1, printc);
		if (!ft_coord_calc(saved))
			ft_args_print(saved);
		else
			ft_error_int("window size too small. Resize window\n");
	}
}


void	signal_handler(int sig)
{
	if (sig == SIGWINCH)
	{
		redraw(0);
		signal(SIGWINCH, signal_handler);
	}
}

int		ft_loop(t_arg *args)
{
	char	cmd[8];

	ft_bzero(cmd, 8);
	args->flags |= 0x01;
	signal(SIGWINCH, signal_handler);
	redraw(args);
	while (read(2, cmd, 4))
	{
		if 		(!strcmp(cmd, "\033[C")) 	keyctl(0, args);
		else if (!strcmp(cmd, "\033[A")) 	keyctl(1, args);
		else if (!strcmp(cmd, "\033[D")) 	keyctl(2, args);
		else if (!strcmp(cmd, "\033[B")) 	keyctl(3, args);
		else if (!strcmp(cmd, "\033")) 		return (0);
		else if (!strcmp(cmd, " ")) 		keyctl(4, args);
		else if (!strcmp(cmd, "\n"))		return (finish_sel(args));
		else if (!strcmp(cmd, "\033[3~"))	args = keydel(args);
		if		(!args)						return (0);
		ft_bzero(cmd, 8);
		tputs(tgetstr("cl", NULL), 1, printc);
		ft_args_print(args);
	}
	return (0);
}

int		printc(int c)
{
	return (write(2, &c, 1));
}

void	term_reconfig()
{
	struct termios	new;

	tcgetattr(2, &new);
	new.c_lflag &= ~(ICANON | ECHO);
	new.c_cc[VMIN] = 1;
	new.c_cc[VTIME] = 0;
	tcsetattr(2, TCSANOW, &new);
}

int		term_init(int argc, char **argv)
{
	char			*termtype;
	char			term_buffer[2048];
	int				success;
	struct termios	save;

	if (!(termtype = getenv("TERM")))
		return (ft_error_int("cannot find TERM variable\n"));
	success = tgetent(term_buffer, termtype);
	if (success < 0)
		return (ft_error_int("cannot access termcap database\n"));
	else if (success == 0)
		return (ft_error_int("terminal type undefined\n"));
	tcgetattr(2, &save);
	term_reconfig();
	tputs(tgetstr("ti", NULL), 1, printc);
	tputs(tgetstr("vi", NULL), 1, printc);
//	tputs(tgetstr("cl", NULL), 1, printc);
	init_arg(argc, argv);
	tputs(tgetstr("ve", NULL), 1, printc);
	tputs(tgetstr("te", NULL), 1, printc);
	tcsetattr(2, TCSANOW, &save);
	return (0);
}

int		main(int argc, char **argv)
{
	int		tty;

	tty = STDERR_FILENO;
	if (!isatty(tty))
		return (ft_error_int("not a tty\n"));
	term_init(argc, argv);
	finish_sel(0);
	return (0);
}
