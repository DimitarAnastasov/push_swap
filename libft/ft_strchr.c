/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 14:20:25 by dianasta          #+#    #+#             */
/*   Updated: 2026/08/02 14:13:32 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != (char)c)
		i++;
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (NULL);
}

// int main(int argc, char **argv)
// {
// 	char *str = argv[1];
// 	int c = argv[2][0];
// 	if (ft_strchr(str, c))
// 		printf("found the character %c inside %s \n it is this:%s", c, str,
//			ft_strchr(str, c));
			// 	else
			// 		printf("didn't find the character %c inside %s \n", c, str);
			// 	return(0);
			// }