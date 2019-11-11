/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <[hshawand@student.42.fr]>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:18:26 by hshawand          #+#    #+#             */
/*   Updated: 2019/11/11 15:00:46 by hshawand         ###   ########.fr       */
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

#endif
