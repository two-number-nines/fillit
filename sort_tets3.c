/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_tets3.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 21:34:03 by vmulder        #+#    #+#                */
/*   Updated: 2019/03/29 20:26:43 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		copy_tet(char **input, char *str)
{
	t_struct	all;

	initialize(&all);
	while (input[all.y])
	{
		while (input[all.y][all.x])
		{
			if (input[all.y][all.x] != '!')
			{
				str[all.i] = input[all.y][all.x];
				all.i++;
			}
			all.x++;
		}
		all.x = 0;
		all.y++;
	}
	str[all.i - 1] = '\0';
}

void			ft_clear_tet(char ***output, char c)
{
	t_struct	all;

	initialize(&all);
	while (output[0][all.y])
	{
		while (output[0][all.y][all.x])
		{
			if (output[0][all.y][all.x] == c)
				output[0][all.y][all.x] = '.';
			all.x++;
		}
		all.x = 0;
		all.y++;
	}
}

char			*cut_tet(char **input)
{
	t_struct	all;
	int			len;
	char		*str;

	initialize(&all);
	len = 0;
	remove_x(input);
	remove_y(input);
	while (input[all.y])
	{
		while (input[all.y][all.x])
		{
			if (input[all.y][all.x] != '!')
				len++;
			all.x++;
		}
		all.y++;
	}
	str = (char*)malloc(sizeof(char) * len + 1);
	copy_tet(input, str);
	return (str);
}
