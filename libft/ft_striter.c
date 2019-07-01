/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 13:11:01 by vmulder        #+#    #+#                */
/*   Updated: 2019/01/25 17:45:36 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(&s[i]);
		i++;
	}
}
