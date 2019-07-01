/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_tets2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 21:28:42 by vmulder        #+#    #+#                */
/*   Updated: 2019/03/29 18:36:18 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		set_row(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		input[i] = '!';
		i++;
	}
}

static void		set_collumn(char **input, int x)
{
	int y;

	y = 0;
	while (input[y])
	{
		input[y][x] = '!';
		y++;
	}
}

int				help_space_two(t_struct *all, int *i)
{
	if ((*all).str[(*i)] == '\n')
	{
		(*i)++;
		return (1);
	}
	return (0);
}

void			remove_x(char **input)
{
	t_struct all;

	initialize(&all);
	while (input[all.y])
	{
		while (input[all.y][all.x])
		{
			if (input[all.y][all.x] == '#')
				break ;
			if (input[all.y][all.x] == '\n')
				set_row(input[all.y]);
			all.x++;
		}
		all.x = 0;
		all.y++;
	}
}

void			remove_y(char **input)
{
	t_struct all;

	initialize(&all);
	while (all.x < 4)
	{
		while (input[all.y])
		{
			if (input[all.y][all.x] == '#')
				break ;
			all.y++;
		}
		if (input[all.y] == NULL)
			set_collumn(input, all.x);
		all.y = 0;
		all.x++;
	}
}
