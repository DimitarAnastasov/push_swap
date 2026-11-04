/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 16:54:18 by dianasta          #+#    #+#             */
/*   Updated: 2026/08/02 00:25:34 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// returns a pointer to the last occurrecne of the character

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*pointer;

	i = 0;
	pointer = NULL;
	while (str[i])
	{
		if (str[i] == (char)c)
			pointer = (char *)&str[i];
		i++;
	}
	if (str[i] == (char)c)
		pointer = (char *)&str[i];
	return (pointer);
}
