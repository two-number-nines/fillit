/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_skipwhite.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/25 20:40:22 by vmulder       #+#    #+#                 */
/*   Updated: 2019/01/25 20:40:52 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_skipwhite(const char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || \
			str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
		i++;
	return (i);
}
