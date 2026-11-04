/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 20:10:22 by dianasta          #+#    #+#             */
/*   Updated: 2026/06/29 16:58:29 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*newvar;
	size_t			i;

	i = 0;
	newvar = (unsigned char *)s;
	while (i < n)
	{
		newvar[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
