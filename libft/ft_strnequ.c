/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnequ.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 15:00:41 by vmulder        #+#    #+#                */
/*   Updated: 2019/01/29 21:44:40 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (s1[i] == 0 && s2[i] == 0)
		return (1);
	while ((s1[i] || s2[i]) && n > i)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
