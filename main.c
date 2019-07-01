/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 21:12:11 by vmulder        #+#    #+#                */
/*   Updated: 2019/03/29 18:18:16 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	fail_checks(char ****res, int fd)
{
	if (fd < 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	if (!(*res = allocate(fd)))
	{
		ft_putstr("error\n");
		return (0);
	}
	if (!(after_help(*res)))
	{
		ft_putstr("error\n");
		return (0);
	}
	if (!(check_tetrimino(*res)))
	{
		ft_putstr("error\n");
		return (0);
	}
	return (1);
}

void		initialize(t_struct *all)
{
	all->y = 0;
	all->x = 0;
	all->i = 0;
	all->cnt = 0;
}

int			main(int argc, char **argv)
{
	int		fd;
	char	***res;
	char	**output;
	int		x;
	int		gridsize;

	res = NULL;
	output = NULL;
	x = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (!(fail_checks(&res, fd)))
			exit(1);
		gridsize = min_grid(res);
		output = newgrid(gridsize);
		while (ft_sort_tets(res, output, 0, 'A') == 0)
		{
			gridsize++;
			output = newgrid(gridsize);
		}
	}
	else
		ft_putstr("Usage : ./fillit tetrimino_sample_file\n");
	return (0);
}
