/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/29 20:16:45 by vmulder        #+#    #+#                */
/*   Updated: 2019/01/29 20:32:34 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*tmp;
	t_list	*save;

	if (lst == NULL || f == NULL)
		return (NULL);
	if ((ret = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	ret = f(lst);
	save = ret;
	if (ret == NULL)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		if ((tmp = (t_list *)malloc(sizeof(t_list))) == NULL)
			return (NULL);
		tmp = f(lst);
		if (tmp == NULL)
			return (NULL);
		lst = lst->next;
		ret->next = tmp;
		ret = ret->next;
	}
	return (save);
}
