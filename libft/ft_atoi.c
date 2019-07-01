/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 09:39:08 by vmulder        #+#    #+#                */
/*   Updated: 2019/01/25 20:46:25 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	int i;
	int nega;
	int res;

	nega = 1;
	i = 0;
	res = 0;
	i = ft_skipwhite(str, i);
	if ((str[i] < '0' || str[i] > '9') && \
		(str[i + 1] < '0' || str[i + 1] > '9'))
		return (0);
	if (str[i] == '-')
	{
		nega *= -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * nega);
}
