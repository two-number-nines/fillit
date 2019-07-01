/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 21:10:31 by vmulder        #+#    #+#                */
/*   Updated: 2019/03/29 19:09:16 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define BUFF_SIZE 1000
# define ENDL 		'\n'

typedef struct	s_struct
{
	int		cnt;
	int		lol;
	int		lol2;
	int		y;
	int		x;
	int		ex;
	int		i;
	char	*str;

}				t_struct;

void			initialize(t_struct *all);

/*
** functions from check_tets2.c
*/

int				checker(char **res, int y, int x);
int				check_tetrimino(char ***res);

/*
** functions from check_valid.c
*/

int				after_help(char ***s);
int				check_valid_before(char *s);

/*
** functions from gridcalc.c
*/

char			***allocate(int fd);
char			***ft_tetrimino_split(char const *s, char c);

/*
** functions from gridcalc.c
*/

int				min_grid(char ***res);
char			**newgrid(int gridsize);

/*
** functions from sort_test.c
*/

int				ft_sort_tets(char ***tets, char **output, int i, char c);

/*
** functions from sort_test2.c
*/

int				help_space_two(t_struct *all, int *i);
void			remove_x(char **input);
void			remove_y(char **input);

/*
** functions from sort_test3.c
*/

void			ft_clear_tet(char ***output, char c);
char			*cut_tet(char **input);

#endif
