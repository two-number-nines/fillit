/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/20 20:16:38 by vmulder        #+#    #+#                */
/*   Updated: 2019/01/25 16:32:19 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*ndst;
	unsigned char	*nsrc;

	ndst = (unsigned char *)dst;
	nsrc = (unsigned char *)src;
	i = 0;
	if (ndst < nsrc)
	{
		while (i < len)
		{
			ndst[i] = nsrc[i];
			i++;
		}
	}
	if (ndst > nsrc)
	{
		while (len-- > 0)
			ndst[len] = nsrc[len];
	}
	return (dst);
}
