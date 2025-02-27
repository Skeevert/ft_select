/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:25:15 by hshawand          #+#    #+#             */
/*   Updated: 2019/11/19 14:52:28 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_arg	*input_parse(t_arg *args, char *cmd)
{
	if (!strcmp(cmd, "\033[C"))
		keyctl(0, args);
	else if (!strcmp(cmd, "\033[A"))
		keyctl(1, args);
	else if (!strcmp(cmd, "\033[D"))
		keyctl(2, args);
	else if (!strcmp(cmd, "\033[B"))
		keyctl(3, args);
	else if (!strcmp(cmd, "\033"))
		return (0);
	else if (!strcmp(cmd, " "))
		keyctl(4, args);
	else if (!strcmp(cmd, "\n"))
	{
		finish_sel(args);
		return (0);
	}
	else if (!strcmp(cmd, "\033[3~"))
		args = keydel(args);
	else if (cmd[0] == 127)
		args = keyback(args);
	return (args);
}

int				ft_loop(t_arg *args)
{
	char			cmd[8];
	int				w_state;

	ft_bzero(cmd, 8);
	args->flags |= 0x01;
	lst_free(&args);
	signal_catch();
	w_state = 0;
	redraw(args, &w_state);
	while (read(2, cmd, 4))
	{
		if (!w_state)
		{
			args = input_parse(args, cmd);
			if (!args)
				return (0);
			ft_bzero(cmd, 8);
			putcap("cl");
			ft_args_print(args);
		}
	}
	return (0);
}

void			term_reconfig(int mode)
{
	struct termios			new;
	static struct termios	save;

	if (mode)
	{
		tcgetattr(2, &new);
		tcgetattr(2, &save);
		new.c_lflag &= ~(ICANON | ECHO);
		new.c_cc[VMIN] = 1;
		new.c_cc[VTIME] = 0;
		tcsetattr(2, TCSANOW, &new);
	}
	else
		tcsetattr(2, TCSANOW, &save);
}

static int		term_init(int argc, char **argv)
{
	char			*termtype;
	char			term_buffer[2048];
	int				success;

	if (!(termtype = getenv("TERM")))
		return (ft_error_int("cannot find TERM variable\n"));
	success = tgetent(term_buffer, termtype);
	if (success < 0)
		return (ft_error_int("cannot access termcap database\n"));
	else if (success == 0)
		return (ft_error_int("terminal type undefined\n"));
	term_reconfig(1);
	putcap("ti");
	putcap("vi");
	init_arg(argc, argv);
	putcap("ve");
	putcap("te");
	term_reconfig(0);
	return (0);
}

int				main(int argc, char **argv)
{
	int		tty;

	tty = STDERR_FILENO;
	if (!isatty(tty))
		return (ft_error_int("not a tty\n"));
	term_init(argc, argv);
	finish_sel(0);
	return (0);
}
