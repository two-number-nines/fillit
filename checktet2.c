/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checktet2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 17:03:24 by vmulder        #+#    #+#                */
/*   Updated: 2019/03/29 19:10:14 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			initialize_spec(int y, int x, t_struct *all)
{
	all->cnt = 0;
	all->lol = 0;
	all->lol2 = 0;
	all->y = y;
	all->x = x;
	all->ex = 0;
}

static int			checkerhelperzero(char **res, t_struct *all)
{
	if (res[all->y][all->x + 1] == '#' && res[all->y][all->x + 2] == '#')
	{
		if (res[all->y + 1])
			if (res[all->y + 1][all->x] == '#')
				all->cnt++;
		all->x++;
	}
	else
		return (0);
	return (1);
}

static int			checkerhelperone(char **res, t_struct *all)
{
	if ((res[all->y + 1] && res[all->y + 2])
		&& (res[all->y + 1][all->x] == '#' && res[all->y + 2][all->x] == '#'))
	{
		if (res[all->y][all->x + 1] == '#')
		{
			all->cnt++;
			all->lol++;
		}
		if (all->x > 0 && res[all->y + 1][all->x - 1] == '#')
		{
			all->cnt++;
			all->lol2++;
		}
		all->y++;
	}
	else
		return (0);
	return (1);
}

static int			checkerhelpertwo(char **res, t_struct *all)
{
	if (res[all->y + 1] && res[all->y + 1][all->x] == '#')
	{
		if (res[all->y][all->x + 1] == '#' && all->lol2 == 0)
			all->cnt++;
		all->y++;
		all->lol = 0;
		all->lol2 = 0;
	}
	else if (res[all->y][all->x + 1] == '#' && all->lol == 0)
	{
		all->lol++;
		all->x++;
	}
	else if (res[all->y][all->x - 1] == '#')
	{
		all->x--;
		all->lol2++;
	}
	else
		return (0);
	return (1);
}

int					checker(char **res, int y, int x)
{
	t_struct all;

	initialize_spec(y, x, &all);
	while (res[all.y][all.x] == '#')
	{
		all.cnt++;
		if (all.cnt == 4)
			break ;
		if (checkerhelperzero(res, &all) == 1)
			all.ex++;
		else if (checkerhelperone(res, &all) == 1)
			all.ex++;
		else if (checkerhelpertwo(res, &all) == 1)
			all.ex++;
		else
			return (0);
	}
	return (1);
}
