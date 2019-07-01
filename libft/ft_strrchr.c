/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 20:35:31 by vmulder       #+#    #+#                 */
/*   Updated: 2019/01/25 16:22:09 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_help(char *s, int c)
{
	int i;

	i = 0;
	i = i + 1;
	while (s[i])
	{
		if (c == s[i])
			return (0);
		i++;
	}
	return (1);
}

char		*ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (c == s[i])
		{
			if (ft_help((char *)&s[i], c) == 1)
				return ((char *)&s[i]);
			i++;
		}
		i++;
	}
	return (0);
}
