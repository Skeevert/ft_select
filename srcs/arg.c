/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <[hshawand@student.42.fr]>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:18:58 by hshawand          #+#    #+#             */
/*   Updated: 2019/11/06 17:53:01 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_coord_calc(t_arg *args)
{
	struct winsize	win;
	size_t			len_max;
	unsigned short	x;
	unsigned short	y;

	len_max = 0;
	ioctl(0, TIOCGWINSZ, &w); /* Add error */
	while (args->value)
	{
		args->len > len_max ? (len_max = args->len) : 0;


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
		args[j].value = argv[i];
		args[j].len = ft_strlen(argv[i]);
		i++;
		j++;
	}
	args[j].value = 0;
	ret = ft_loop(args);
	free(args);
	return(ret);
}
