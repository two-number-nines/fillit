/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 12:22:57 by vmulder       #+#    #+#                 */
/*   Updated: 2019/01/25 15:31:35 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}
