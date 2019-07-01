/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 17:08:30 by vmulder        #+#    #+#                */
/*   Updated: 2019/01/25 22:53:51 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *nee, size_t len)
{
	size_t		i;
	size_t		pos;
	size_t		nlen;

	i = 0;
	pos = 0;
	nlen = ft_strlen(nee);
	if (*hay == '\0' && *nee != '\0')
		return (NULL);
	if (*nee == '\0')
		return ((char *)hay);
	while (hay[i] && i < len)
	{
		while (nee[pos] == hay[i + pos] && (i + pos) < len)
		{
			if (pos == nlen - 1)
				return ((char *)hay + i);
			pos++;
		}
		pos = 0;
		i++;
	}
	return (0);
}
