/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrev.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/25 20:48:08 by vmulder        #+#    #+#                */
/*   Updated: 2019/01/25 20:50:12 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
{
	int		i;
	int		length;
	char	buff;

	i = 0;
	length = ft_strlen(str) - 1;
	while (length > i)
	{
		buff = str[i];
		str[i] = str[length];
		str[length] = buff;
		length--;
		i++;
	}
	return (str);
}
