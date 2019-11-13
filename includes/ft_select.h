/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <[hshawand@student.42.fr]>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:18:26 by hshawand          #+#    #+#             */
/*   Updated: 2019/11/13 15:49:22 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H

# define FT_SELECT_H

# include "libft.h"
# include <termios.h>
# include <termcap.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <fcntl.h>
 
/* Not technically required, but needed on some UNIX distributions */
# include <sys/types.h>
# include <sys/stat.h>


/*
** 0x01 -- IS_SELECTED
** 0x02 -- IS_UNDERLINED
*/

typedef struct	s_arg
{
	struct s_arg	*next;
	struct s_arg	*prev;
	char			flags;
	char			*value;
	unsigned short	coord_x;
	unsigned short	coord_y;
	size_t			len;
}					t_arg;

int					ft_error_int(char *msg);
int					printc(int c);
int					ft_loop(t_arg *args);
int					init_arg(int argc, char **argv);
int					ft_args_print(t_arg *args);
int					ft_coord_calc(t_arg *args);

int					arg_add(t_arg	**alst, t_arg *new);
t_arg				*arg_new(void);
void				lst_free(t_arg	**start);

void				keyctl(int key, t_arg *args);
int					finish_sel(t_arg *args);
t_arg				*keydel(t_arg *args);
t_arg				*keyback(t_arg *args);

#endif
