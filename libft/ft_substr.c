/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 12:38:20 by dianasta          #+#    #+#             */
/*   Updated: 2026/08/02 00:25:26 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		*ptr = '\0';
		return (ptr);
	}
	i = len;
	if (ft_strlen(s + start) < len)
		i = ft_strlen(s + start);
	ptr = malloc(i + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, (s + start), i);
	ptr[i] = '\0';
	return (ptr);
}
