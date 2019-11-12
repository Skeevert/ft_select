/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <[hshawand@student.42.fr]>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:25:15 by hshawand          #+#    #+#             */
/*   Updated: 2019/11/12 13:40:36 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_error_int(char *msg)
{
	write(2, "Error: ", 7);
	write(2, msg, strlen(msg));
	return (-1);
}

int		ft_loop(t_arg *args)
{
	char	cmd[8];

	ft_bzero(cmd, 8);
	args->flags |= 0x01;
	ft_args_print(args);
	while (read(0, cmd, 3))
	{
		if 		(!strcmp(cmd, "\033[C")) 	keyctl(0, args);
		else if (!strcmp(cmd, "\033[A")) 	keyctl(1, args);
		else if (!strcmp(cmd, "\033[D")) 	keyctl(2, args);
		else if (!strcmp(cmd, "\033[B")) 	keyctl(3, args);
		else if (!strcmp(cmd, "\033")) 		return (0);
		else if (!strcmp(cmd, " ")) 		keyctl(4, args);
		ft_bzero(cmd, 8);
		tputs(tgetstr("cl", NULL), 1, printc);
		ft_args_print(args);
	}
	return (0);
}

int		printc(int c)
{
	return (write(1, &c, 1));
}

void	term_reconfig()
{
	struct termios	new;

	tcgetattr(1, &new);
	new.c_lflag &= ~(ICANON | ECHO);
	new.c_cc[VMIN] = 1;
	new.c_cc[VTIME] = 0;
	tcsetattr(1, TCSANOW, &new);
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
	tcgetattr(1, &save);
	term_reconfig();
	tputs(tgetstr("ti", NULL), 1, printc);
	tputs(tgetstr("vi", NULL), 1, printc);
//	tputs(tgetstr("cl", NULL), 1, printc);
	init_arg(argc, argv);
	tputs(tgetstr("ve", NULL), 1, printc);
	tputs(tgetstr("te", NULL), 1, printc);
	tcsetattr(1, TCSANOW, &save);
	return (0);
}

int		main(int argc, char **argv)
{
	int		tty;

	tty = STDOUT_FILENO;
	if (!isatty(tty))
		return (ft_error_int("not a tty\n"));
	term_init(argc, argv);
	return (0);
}
