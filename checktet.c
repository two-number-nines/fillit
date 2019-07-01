/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checktet.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 22:04:20 by vmulder        #+#    #+#                */
/*   Updated: 2019/03/28 22:35:36 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			check_tetrimino_helper(char **res, int cnt)
{
	t_struct all;

	initialize(&all);
	while (res[all.y])
	{
		while (res[all.y][all.x] != '\n')
		{
			if (res[all.y][all.x] == '#')
			{
				if (!(checker(res, all.y, all.x)))
					return (0);
				cnt++;
				break ;
			}
			all.x++;
		}
		if (cnt != 0)
			break ;
		all.x = 0;
		all.y++;
	}
	return (1);
}

int					check_tetrimino(char ***res)
{
	t_struct all;

	initialize(&all);
	while (res[all.i])
	{
		if (!(check_tetrimino_helper(res[all.i], all.cnt)))
			return (0);
		all.i++;
	}
	return (1);
}
