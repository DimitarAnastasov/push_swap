/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 12:00:00 by dianasta          #+#    #+#             */
/*   Updated: 2026/11/04 13:41:14 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	dist(t_stack *s, int idx)
{
	int	pos;

	pos = find_pos(s, idx);
	if (pos <= s->size / 2)
		return (pos);
	return (s->size - pos);
}

static void	push_small(t_ctx *c, int idx)
{
	bring_to_top_a(c, idx);
	pb(c);
}

static void	sort_four(t_ctx *c)
{
	push_small(c, 0);
	sort_three(c);
	pa(c);
}

static void	sort_five(t_ctx *c)
{
	int	first;
	int	second;

	first = 0;
	second = 1;
	if (dist(&c->a, 1) < dist(&c->a, 0))
	{
		first = 1;
		second = 0;
	}
	push_small(c, first);
	push_small(c, second);
	sort_three(c);
	if (c->b.top->index < c->b.top->next->index)
		sb(c);
	pa(c);
	pa(c);
}

void	sort_small(t_ctx *c)
{
	if (c->a.size <= 3)
		sort_three(c);
	else if (c->a.size == 4)
		sort_four(c);
	else
		sort_five(c);
}
