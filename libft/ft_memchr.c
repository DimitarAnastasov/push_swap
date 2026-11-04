/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:12:25 by dianasta          #+#    #+#             */
/*   Updated: 2026/08/02 13:55:27 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}

// alternative below

// void	*ft_memchr(const void *s, int c, size_t n)
// {
// 	unsigned char *ptr;

// 	ptr = (unsigned char *)s;
// 	while (ptr != (unsigned char *)s + n)
// 	{
// 		if (*ptr == (unsigned char)c)
// 			return (ptr);
// 		ptr++;
// 	}
// 	return (NULL);
// }