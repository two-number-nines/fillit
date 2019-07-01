/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:54:39 by vmulder        #+#    #+#                */
/*   Updated: 2019/01/19 10:08:10 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
		ft_putstr("-2147483648");
	else if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr(nbr * -1);
	}
	else if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
	else
		ft_putchar(nbr + '0');
}
