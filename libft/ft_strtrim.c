/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 14:47:30 by vmulder        #+#    #+#                */
/*   Updated: 2019/01/25 21:25:44 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_trimhelp(int l, int i, int b, char const *s)
{
	int		q;
	char	*sstring;

	q = 0;
	sstring = (char *)malloc(sizeof(char) * (b - i) + 2);
	if (sstring == NULL)
		return (0);
	l = b - i + 1;
	while (l > 0)
	{
		sstring[q] = s[i];
		l--;
		i++;
		q++;
	}
	sstring[q] = '\0';
	return (sstring);
}

static int		ft_checkwhite(char const *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		if (s[i + 1] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s)
{
	int		l;
	int		b;
	int		i;
	char	*sstring;

	b = 0;
	i = 0;
	l = 0;
	if (!s)
		return (0);
	if (ft_checkwhite(s) == 1)
	{
		sstring = (char *)malloc(sizeof(char) * 1);
		*sstring = '\0';
		return (sstring);
	}
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	b = ft_strlen(s) - 1;
	while (s[b] == ' ' || s[b] == '\n' || s[b] == '\t')
		b--;
	l = b - i + 1;
	sstring = ft_trimhelp(l, i, b, s);
	return (sstring);
}
