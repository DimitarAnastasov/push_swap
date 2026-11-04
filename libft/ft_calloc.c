/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 16:38:17 by dianasta          #+#    #+#             */
/*   Updated: 2026/06/30 17:29:03 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size != 0 && (nmemb * size) / size != nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr)
	{
		ft_memset(ptr, 0, nmemb * size);
		return (ptr);
	}
	return (NULL);
}
