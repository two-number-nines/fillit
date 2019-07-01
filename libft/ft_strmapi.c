/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/20 14:44:06 by vmulder       #+#    #+#                 */
/*   Updated: 2019/01/20 15:01:53 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*nstring;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	nstring = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (nstring == NULL)
		return (NULL);
	while (s[i])
	{
		nstring[i] = f(i, s[i]);
		i++;
	}
	nstring[i] = '\0';
	return (nstring);
}
