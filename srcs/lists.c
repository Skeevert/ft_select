/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <[hshawand@student.42.fr]>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:51:49 by hshawand          #+#    #+#             */
/*   Updated: 2019/11/11 17:28:01 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	arg_add(t_arg	**alst, t_arg new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	*alst->prev = new;
	*alst = new;
}

t_arg	*arg_new(void)
{
	t_arg	*new;

	if (!(new = (t_arg *)malloc(sizeof(t_arg))))
		return (0);
	ft_bzero(new, sizeof(t_arg));
	return(new);
}

void	lst_free(t_arg	**start)
{
	t_arg	*temp;

	staar->prev->value = 0;
	while (*start->value)
	{
		temp = *start;
		*start = (*start)->next;
		free(temp);
	}
	free(*start);
}
