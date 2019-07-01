/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 17:34:05 by vmulder        #+#    #+#                */
/*   Updated: 2019/01/24 11:12:39 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	const char	*psource;
	char		*pdes;
	char		*res;

	psource = s1;
	pdes = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	res = pdes;
	if (pdes == NULL)
		return (NULL);
	while (*psource != '\0')
	{
		*pdes = *psource;
		pdes++;
		psource++;
	}
	*pdes = '\0';
	return (res);
}
