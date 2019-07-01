/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strsub.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/20 13:13:19 by vmulder       #+#    #+#                 */
/*   Updated: 2019/01/25 15:09:15 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*nstring;
	size_t	i;
	size_t	b;

	b = 0;
	i = (size_t)start;
	if (!s)
		return (0);
	nstring = (char *)malloc(len + 1);
	if (!nstring)
		return (NULL);
	if ((ft_strlen(s) + 1) < (start + len))
		return (NULL);
	while (s[i] && len > 0)
	{
		nstring[b] = s[i];
		b++;
		i++;
		len--;
	}
	nstring[b] = '\0';
	return (nstring);
}
