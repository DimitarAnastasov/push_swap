/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:35:58 by dianasta          #+#    #+#             */
/*   Updated: 2026/06/23 20:12:54 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int n)
{
	if (n > 47 && n < 58)
		return (1);
	return (0);
}

// second version and its a lot more efficient

// int ft_isdigit (int n) {
//     return (n > 47 && n < 58);
// }