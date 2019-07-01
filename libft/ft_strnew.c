/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 18:20:54 by vmulder        #+#    #+#                */
/*   Updated: 2019/01/25 17:18:38 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*nstr;
	size_t	i;

	i = 0;
	nstr = (char *)malloc(sizeof(char) * size + 1);
	if (!nstr)
		return (NULL);
	while (nstr != '\0' && i <= size)
	{
		nstr[i] = '\0';
		i++;
	}
	return (nstr);
}
