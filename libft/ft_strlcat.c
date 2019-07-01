/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strlcat.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 09:54:59 by vmulder       #+#    #+#                 */
/*   Updated: 2019/01/19 16:24:16 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t srclen;

	i = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size < i)
		i = size;
	if (i == size)
		return (srclen + size);
	if (srclen >= size - i)
	{
		ft_strncat(dst, src, size - i - 1);
		dst[size - 1] = '\0';
	}
	else
		ft_strncat(dst, src, srclen + 1);
	return (srclen + i);
}
