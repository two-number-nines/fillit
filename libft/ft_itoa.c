/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/22 15:09:53 by vmulder        #+#    #+#                */
/*   Updated: 2019/01/25 20:49:14 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_algo(char *nstring, int i, long int min, int p)
{
	while (min >= 10)
	{
		nstring[i] = (char)(min % 10 + '0');
		min = min / 10;
		i++;
	}
	nstring[i++] = (char)(min + '0');
	if (p < 0)
		nstring[i++] = '-';
	nstring[i] = '\0';
	ft_strrev(nstring);
	return (nstring);
}

char			*ft_itoa(int n)
{
	long int	min;
	int			p;
	int			i;
	char		*nstring;

	min = n;
	if (!(nstring = (char *)malloc(sizeof(char) * ft_getdigits(n) + 1)))
		return (NULL);
	i = 0;
	p = 0;
	if (n < 0)
	{
		min = min * -1;
		p = -1;
	}
	ft_algo(nstring, i, min, p);
	return (nstring);
}
