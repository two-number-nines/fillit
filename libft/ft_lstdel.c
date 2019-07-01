/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/29 19:39:20 by vmulder        #+#    #+#                */
/*   Updated: 2019/01/29 21:16:38 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	if ((*alst)->next != NULL)
		ft_lstdel(&(*alst)->next, del);
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
