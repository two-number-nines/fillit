/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_valid.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 21:09:59 by vmulder        #+#    #+#                */
/*   Updated: 2019/03/29 18:56:41 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_valid_after(char ***s, int i, int y, int x)
{
	int cnt;

	cnt = 0;
	while (s[i])
	{
		while (s[i][y])
		{
			while (s[i][y][x])
			{
				if (s[i][y][x] == '#')
					cnt++;
				x++;
			}
			x = 0;
			y++;
		}
		if (cnt != 4)
			return (0);
		y = 0;
		cnt = 0;
		i++;
	}
	return (1);
}

static int		check_before_help(char *s)
{
	int test;

	test = 20;
	while (s[test])
	{
		if (s[test] != '\n')
			return (0);
		test += 21;
	}
	return (1);
}

int				check_valid_before(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (ft_strlen(s) > 545)
		return (0);
	if (!(check_before_help(s)))
		return (0);
	while (s[i])
	{
		if (s[i] != '.' && s[i] != '#' && s[i] != '\n')
			return (0);
		if (s[i] == '\n' && s[i + 1] == '\n'
			&& s[i + 2] != '.' && s[i + 2] != '#')
			return (0);
		if (s[i] != '\n')
			len++;
		if (len > 4)
			return (0);
		len = 0;
		i++;
	}
	return (1);
}

int				after_help(char ***s)
{
	int i;
	int y;
	int x;

	i = 0;
	x = 0;
	y = 0;
	if (!(check_valid_after(s, i, y, x)))
		return (0);
	return (1);
}
