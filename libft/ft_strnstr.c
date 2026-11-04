/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 18:16:17 by dianasta          #+#    #+#             */
/*   Updated: 2026/08/02 13:57:24 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!little[0])
		return ((char *)&big[0]);
	while (big[i] && i < len)
	{
		while (big[i + j] == little[j] && little[j] && i + j < len)
			j++;
		if (!little[j])
			return ((char *)&big[i]);
		i++;
		j = 0;
	}
	return (NULL);
}

// i want to reuse the  ft_strchr function that finds a char inside a string

// int main(int argc, char **argv)
// {
// 	if (argc != 3)
// 		return (1);
// 	printf("%s", ft_strnstr(argv[1], argv[2], 10));
// 	return (0);
// }