/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:00:29 by hshawand          #+#    #+#             */
/*   Updated: 2019/04/19 12:44:02 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static t_list	*ft_clean(t_list *failed_list)
{
	t_list *temp;

	while (failed_list)
	{
		temp = failed_list;
		failed_list = failed_list->next;
		free(temp->content);
		free(temp);
	}
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*start;
	t_list		*current;
	t_list		*tmp;

	if (!lst || !f)
		return (NULL);
	start = (t_list *)malloc(sizeof(t_list));
	if (!start)
		return (NULL);
	current = start;
	while (lst)
	{
		tmp = (*f)(lst);
		if (!tmp)
			return (ft_clean(start));
		*current = *tmp;
		free(tmp);
		current->next = (t_list *)malloc(sizeof(t_list));
		if (!current->next)
			return (ft_clean(start));
		lst = lst->next;
		current = current->next;
	}
	return (start);
}
