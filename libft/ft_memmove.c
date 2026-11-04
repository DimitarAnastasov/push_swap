/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:47:56 by dianasta          #+#    #+#             */
/*   Updated: 2026/08/02 00:28:10 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (s > d)
		ft_memcpy(dest, src, n);
	else
	{
		i = n;
		while (i)
		{
			i--;
			d[i] = s[i];
		}
	}
	return (dest);
}
