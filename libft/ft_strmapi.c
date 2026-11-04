/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 18:17:50 by dianasta          #+#    #+#             */
/*   Updated: 2026/08/02 00:25:58 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s1;

	if (!s || !f)
		return (NULL);
	i = 0;
	s1 = malloc(ft_strlen(s) + 1);
	if (!s1)
		return (NULL);
	while (*(s + i))
	{
		*(s1 + i) = f(i, *(s + i));
		i++;
	}
	*(s1 + i) = '\0';
	return (s1);
}
