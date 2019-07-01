/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 10:15:14 by vmulder       #+#    #+#                 */
/*   Updated: 2019/01/19 12:43:37 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ar;

	c = (unsigned char)c;
	ar = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ar[i] = c;
		i++;
	}
	return (b);
}
