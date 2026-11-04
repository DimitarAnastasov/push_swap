/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:01:41 by dianasta          #+#    #+#             */
/*   Updated: 2026/08/02 00:41:24 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*newvar;

	i = 0;
	newvar = (unsigned char *)s;
	while (i < n)
	{
		newvar[i] = '\0';
		i++;
	}
}

// alt below
// void	ft_bzero(void *s, size_t n)
// {
// 	ft_memset(s, 0, n);
// }