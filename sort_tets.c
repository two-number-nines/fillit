/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_tets.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 21:12:36 by vmulder        #+#    #+#                */
/*   Updated: 2019/03/29 20:35:47 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		help_space(int *i, int *x)
{
	(*i)++;
	(*x)++;
}

static int		check_space(char **output, t_struct all)
{
	int	x;
	int	i;

	x = all.x;
	i = 0;
	while (output[all.y] && all.str[i])
	{
		while (output[all.y][x] && all.str[i])
		{
			if (all.str[i] == '.'
				&& (output[all.y][x] >= 'A' && output[all.y][x] <= 'Z'))
				help_space(&i, &x);
			else if (help_space_two(&all, &i))
				break ;
			else if (output[all.y][x] == '.' || all.str[i] == '.')
				help_space(&i, &x);
			else
				return (0);
		}
		x = all.x;
		all.y++;
	}
	if (all.str[i] == '\0')
		return (1);
	return (0);
}

static void		place_tet(char **output, t_struct all, char c)
{
	int	x;

	x = all.x;
	all.ex = 0;
	while (output[all.y] && all.str[all.ex])
	{
		while (output[all.y][x] && all.str[all.ex])
		{
			if (all.str[all.ex] == '\n')
			{
				all.ex++;
				break ;
			}
			else if (output[all.y][x] == '.' && all.str[all.ex] == '#')
			{
				output[all.y][x] = c;
				help_space(&all.ex, &x);
			}
			else if ((output[all.y][x] == '.' && all.str[all.ex] == '.')
					|| all.str[all.ex] == '.')
				help_space(&all.ex, &x);
		}
		x = all.x;
		all.y++;
	}
}

static void		print_map(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putstr(str[i]);
		i++;
	}
	exit(1);
}

int				ft_sort_tets(char ***tets, char **output, int i, char c)
{
	t_struct	all;

	initialize(&all);
	if (tets[i] == NULL)
		print_map(output);
	all.str = cut_tet(tets[i]);
	while (output[all.y])
	{
		while (output[all.y][all.x])
		{
			if (output[all.y][all.x])
				if (check_space(output, all))
				{
					place_tet(output, all, c);
					if (ft_sort_tets(tets, output, i + 1, c + 1))
						return (1);
					ft_clear_tet(&output, c);
				}
			all.x++;
		}
		all.x = 0;
		all.y++;
	}
	free(all.str);
	return (0);
}
