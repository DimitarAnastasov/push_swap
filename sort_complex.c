/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 12:00:00 by dianasta          #+#    #+#             */
/*   Updated: 2026/11/04 13:41:14 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	radix_pass(t_ctx *c, int bit, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if ((c->a.top->index >> bit) & 1)
			ra(c);
		else
			pb(c);
		i++;
	}
	while (c->b.size > 0)
		pa(c);
}

void	sort_complex(t_ctx *c)
{
	int	bit;
	int	bits;
	int	n;

	n = c->a.size;
	bits = max_bits(n - 1);
	bit = 0;
	while (bit < bits && !is_sorted(&c->a))
	{
		radix_pass(c, bit, n);
		bit++;
	}
}
