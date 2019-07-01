/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcat.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 12:46:13 by vmulder       #+#    #+#                 */
/*   Updated: 2019/01/18 12:05:11 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int b;

	i = ft_strlen(s1);
	b = 0;
	while (s2[b])
	{
		s1[i] = s2[b];
		i++;
		b++;
	}
	s1[i] = '\0';
	return (s1);
}
