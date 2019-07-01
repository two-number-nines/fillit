/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 20:13:50 by vmulder        #+#    #+#                */
/*   Updated: 2019/01/25 17:51:17 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstring;
	int		i;
	int		b;

	i = 0;
	b = 0;
	if (!s1 || !s2)
		return (0);
	nstring = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (nstring == NULL)
		return (0);
	while (s1[i])
	{
		nstring[i] = s1[i];
		i++;
	}
	while (s2[b])
	{
		nstring[i] = s2[b];
		i++;
		b++;
	}
	nstring[i] = '\0';
	return (nstring);
}
