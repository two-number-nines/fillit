/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gridcalc.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 21:11:58 by vmulder        #+#    #+#                */
/*   Updated: 2019/03/28 22:35:27 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		nbrs_tet(char ***res)
{
	int i;

	i = 0;
	while (res[i])
		i++;
	return (i);
}

int				min_grid(char ***res)
{
	int min;
	int grid;
	int i;

	i = 1;
	grid = 5;
	min = nbrs_tet(res);
	if (min == 1)
		grid = 2;
	if (min == 2)
		grid = 3;
	if (min == 3 || min == 4)
		grid = 4;
	else
		min *= 4;
	while ((grid * grid) < min)
		grid++;
	return (grid);
}

char			**newgrid(int gridsize)
{
	t_struct	all;
	char		**temp;

	temp = (char**)malloc(sizeof(char*) * gridsize + 1);
	if (!temp)
		return (NULL);
	temp[gridsize] = NULL;
	initialize(&all);
	while (all.y < gridsize)
	{
		temp[all.y] = ft_strnew(gridsize + 1);
		while (all.x < gridsize + 1)
		{
			if (all.x == gridsize)
				temp[all.y][all.x] = '\n';
			else
				temp[all.y][all.x] = '.';
			all.x++;
		}
		all.y++;
		all.x = 0;
	}
	return (temp);
}
