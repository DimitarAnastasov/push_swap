/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:26:51 by dianasta          #+#    #+#             */
/*   Updated: 2026/07/26 18:15:34 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*ptr2;

	if (dest == src)
		return (dest);
	i = 0;
	ptr = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	while (i < n)
	{
		ptr[i] = ptr2[i];
		i++;
	}
	return (dest);
}

// what does this do? again fucking copy things no?