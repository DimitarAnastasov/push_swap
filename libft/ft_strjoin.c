/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 18:27:33 by dianasta          #+#    #+#             */
/*   Updated: 2026/08/02 00:26:47 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	n;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	n = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = malloc(n);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
	ft_strlcat(ptr, s2, n);
	return (ptr);
}
