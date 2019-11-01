/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <[hshawand@student.42.fr]>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:25:15 by hshawand          #+#    #+#             */
/*   Updated: 2019/11/01 16:10:26 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_arg(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		ft_putendl(argv[i]);
		i++;
	}
}

int		printc(int c)
{
	return (write(1, &c, 1));
}

int		ft_error_int(char *msg)
{
	write(2, "Error: ", 7);
	write(2, msg, strlen(msg));
	return (-1);
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
	char			cache;
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
	tputs(tgetstr("cl", NULL), 1, printc);
	print_arg(argc, argv);
	read(0, &cache, 1);
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
