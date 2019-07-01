/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/20 17:47:08 by vmulder        #+#    #+#                */
/*   Updated: 2019/01/24 12:20:14 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	uc;
	unsigned char	*nsrc;
	unsigned char	*ndst;

	ndst = (unsigned char *)dst;
	nsrc = (unsigned char *)src;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		ndst[i] = (unsigned char)nsrc[i];
		if (nsrc[i] == uc)
		{
			i += 1;
			return (&ndst[i]);
		}
		i++;
	}
	return (NULL);
}
