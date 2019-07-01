/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 18:17:49 by vmulder       #+#    #+#                 */
/*   Updated: 2019/01/24 14:22:02 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (c == s[i])
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
