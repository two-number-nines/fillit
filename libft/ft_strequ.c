/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strequ.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 17:27:24 by vmulder        #+#    #+#                */
/*   Updated: 2019/01/25 17:50:28 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int			res;
	unsigned	i;

	res = 0;
	i = 0;
	if (!s1 || !s2)
		return (0);
	if (s1[i] == 0 && s2[i] == 0)
		return (1);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (res);
		i++;
	}
	return (res + 1);
}
