/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   allocate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 21:10:15 by vmulder        #+#    #+#                */
/*   Updated: 2019/03/29 20:24:24 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			ft_splithelp(char const *s, char ***ar, char c, int cnt)
{
	t_struct all;

	initialize(&all);
	while (all.x < 4)
	{
		(*ar)[all.x] = ft_strnew(5);
		while (s[cnt] && s[cnt] != c)
		{
			(*ar)[all.x][all.y] = s[cnt];
			all.y++;
			cnt++;
		}
		(*ar)[all.x][all.y] = '\n';
		(*ar)[all.x][all.y + 1] = '\0';
		all.y = 0;
		all.x++;
		cnt++;
	}
	(*ar)[all.x] = NULL;
	return (cnt);
}

static int			help_alloc(int fd, int tmp, char **lol, char *buf)
{
	char *tmp2;

	while (tmp > 0)
	{
		tmp2 = *lol;
		*lol = ft_strjoin(*lol, buf);
		tmp = read(fd, buf, 21);
		free(tmp2);
		if (tmp != 21 && tmp != 0)
			return (0);
	}
	return (1);
}

char				***ft_tetrimino_split(char const *s, char c)
{
	char	***ar;
	int		cnt;
	int		axis;
	int		i;

	cnt = 0;
	i = 0;
	if (!s)
		return (NULL);
	axis = (ft_strlen(s) / 21) + 1;
	ar = (char***)malloc(sizeof(char**) * axis + 1);
	if (!ar)
		return (NULL);
	while (i < axis)
	{
		ar[i] = (char**)malloc(sizeof(char*) * 5);
		if (ar == NULL)
			return (NULL);
		cnt = ft_splithelp(s, &ar[i], c, cnt);
		cnt++;
		i++;
	}
	ar[i] = NULL;
	free((void*)s);
	return (ar);
}

char				***allocate(int fd)
{
	int		tmp;
	char	*lol;
	char	***res;
	char	buf[BUFF_SIZE];

	res = NULL;
	tmp = read(fd, buf, 20);
	if (tmp != 20)
		return (NULL);
	lol = (char*)malloc(sizeof(char) * 1);
	if (!lol)
		return (NULL);
	if (!(help_alloc(fd, tmp, &lol, buf)))
		return (NULL);
	if (!(check_valid_before(lol)))
		return (NULL);
	res = ft_tetrimino_split(lol, '\n');
	return (res);
}
