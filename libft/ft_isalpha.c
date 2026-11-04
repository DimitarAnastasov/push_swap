/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 16:23:32 by dianasta          #+#    #+#             */
/*   Updated: 2026/06/23 21:55:29 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>

int	ft_isalpha(int s)
{
	if ((s > 64 && s < 91) || (s > 96 && s < 123))
	{
		return (1);
	}
	return (0);
}

// int	main(void)
// {
// 	char	letter;

// 	letter = 's';
// 	if isalpha (letter)
// 	{
// 		printf("this is a letter\n");
// 	}
// 	else
// 	{
// 		printf("this is not\n");
// 	}
// 	if (ft_isalpha(letter))
// 	{
// 		printf("this is a letter\n");
// 	}
// 	else
// 	{
// 		printf("this is not\n");
// 	}
// 	return (0);
// }
// second version
// int ft_isalpha (int s) {
//     return ( (s > 64 && s < 91) || ( s > 96 && s < 123));
// }