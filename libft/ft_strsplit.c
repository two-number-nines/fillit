/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 20:01:09 by vmulder       #+#    #+#                 */
/*   Updated: 2019/02/01 12:09:14 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wordcount(char const *s, int wordcount, int c)
{
	int i;

	i = -1;
	while (s[++i])
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			wordcount++;
	return (wordcount);
}

static void		ft_copystring(char const *s, char *ns, int start, int end)
{
	int i;

	i = 0;
	while (start < end)
	{
		ns[i] = s[start];
		i++;
		start++;
	}
	ns[i] = '\0';
}

static void		ft_retstr(char const *s, char **ns, int wordcount, int c)
{
	int	i;
	int start;
	int end;

	start = 0;
	end = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
		{
			end = i + 1;
			if (start <= end)
			{
				ns[wordcount] = (char*)malloc((end - start + 1));
				ft_copystring(s, ns[wordcount], start, end);
				wordcount++;
				start = end;
			}
		}
	}
}

char			**ft_strsplit(char const *s, char c)
{
	int		wordcount;
	int		i;
	char	**ns;

	if (!s)
		return (0);
	wordcount = 0;
	i = -1;
	wordcount = ft_wordcount(s, wordcount, c);
	if (!(ns = (char**)malloc((wordcount + 1) * sizeof(char**))))
		return (NULL);
	ns[wordcount] = 0;
	wordcount = 0;
	ft_retstr(s, ns, wordcount, c);
	return (ns);
}
