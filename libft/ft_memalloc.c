/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/20 15:02:33 by vmulder        #+#    #+#                */
/*   Updated: 2019/01/25 16:19:30 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *n;

	if (!(n = (void *)malloc(sizeof(void) * (size))))
		return (NULL);
	ft_memset(n, 0, size);
	return (n);
}
