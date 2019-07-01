/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 17:24:57 by vmulder       #+#    #+#                 */
/*   Updated: 2019/01/24 15:46:05 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned i;

	i = 0;
	while ((s1[i] || s2[i]) && (n > i))
	{
		if ((s1[i] - s2[i]) < 0)
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		else if ((s1[i] - s2[i]) > 0)
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
