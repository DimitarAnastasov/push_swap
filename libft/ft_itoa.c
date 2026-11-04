/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 13:02:28 by dianasta          #+#    #+#             */
/*   Updated: 2026/07/26 18:09:14 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	findlen(long n)
{
	int	counter;

	counter = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		counter++;
	}
	while (n > 0)
	{
		counter++;
		n /= 10;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	num;

	len = findlen(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	num = n;
	if (n < 0)
		num = -num;
	while (len)
	{
		len--;
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

// int main(void)
// {
// 	int n = 12323;

// 	printf("%s", ft_itoa(n));
// 	// printf("%i", findlen(n));
// 	return (0);
// }