/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/20 16:48:37 by vmulder       #+#    #+#                 */
/*   Updated: 2019/01/20 17:43:20 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int				i;
	unsigned char	*nsrc;
	unsigned char	*ndst;

	ndst = (unsigned char *)dst;
	nsrc = (unsigned char *)src;
	i = 0;
	while (n > 0)
	{
		ndst[i] = nsrc[i];
		i++;
		n--;
	}
	return (ndst);
}
