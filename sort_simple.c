/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 12:00:00 by dianasta          #+#    #+#             */
/*   Updated: 2026/11/04 13:41:19 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	three_case(t_ctx *c, int x, int y, int z)
{
	if (x > y && y < z && x < z)
		sa(c);
	else if (x > y && y > z)
	{
		sa(c);
		rra(c);
	}
	else if (x > y && y < z && x > z)
		ra(c);
	else if (x < y && y > z && x < z)
	{
		sa(c);
		ra(c);
	}
	else if (x < y && y > z && x > z)
		rra(c);
}

void	sort_three(t_ctx *c)
{
	t_node	*n;

	if (c->a.size == 2 && c->a.top->value > c->a.top->next->value)
		sa(c);
	if (c->a.size != 3)
		return ;
	n = c->a.top;
	three_case(c, n->value, n->next->value, n->next->next->value);
}

void	sort_simple(t_ctx *c)
{
	int	target;

	target = 0;
	while (c->a.size > 3)
	{
		bring_to_top_a(c, target);
		pb(c);
		target++;
	}
	sort_three(c);
	while (c->b.size > 0)
		pa(c);
}
