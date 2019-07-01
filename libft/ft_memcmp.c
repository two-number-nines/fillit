/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/20 15:14:01 by vmulder       #+#    #+#                 */
/*   Updated: 2019/01/20 16:45:40 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *s1n;
	unsigned char *s2n;

	s1n = (unsigned char *)s1;
	s2n = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (*s1n != *s2n)
			return (*s1n - *s2n);
		s1n++;
		s2n++;
		n--;
	}
	return (0);
}
