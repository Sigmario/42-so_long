/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:48:56 by julmuntz          #+#    #+#             */
/*   Updated: 2022/07/10 19:59:42 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *))
{
	t_list	*new;
	t_list	*tmp;

	new = 0;
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst->content));
		if (tmp == NULL)
			ft_lstclear(&tmp, d);
		else
			ft_lstadd_back(&new, tmp);
		lst = lst->next;
	}
	return (new);
}
