/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 12:04:09 by vmulder       #+#    #+#                 */
/*   Updated: 2019/01/19 12:49:50 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	void			*p;
	unsigned char	*ar;

	c = (unsigned char)c;
	p = (void *)s;
	ar = (unsigned char *)p;
	i = 0;
	while (i < n)
	{
		if (ar[i] == c)
			return (p);
		i++;
		p++;
	}
	return (0);
}
