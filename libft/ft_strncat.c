/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 14:51:05 by vmulder       #+#    #+#                 */
/*   Updated: 2019/01/18 12:04:17 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	size_t	b;

	i = ft_strlen(s1);
	b = 0;
	while (s2[b] && b < n)
	{
		s1[i] = s2[b];
		i++;
		b++;
	}
	s1[i] = '\0';
	return (s1);
}
