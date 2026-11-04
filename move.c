/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 12:00:00 by dianasta          #+#    #+#             */
/*   Updated: 2026/11/04 13:41:02 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pos(t_stack *s, int idx)
{
	t_node	*n;
	int		pos;

	n = s->top;
	pos = 0;
	while (n)
	{
		if (n->index == idx)
			return (pos);
		pos++;
		n = n->next;
	}
	return (-1);
}

void	bring_to_top_a(t_ctx *c, int idx)
{
	int	pos;

	pos = find_pos(&c->a, idx);
	if (pos <= c->a.size / 2)
	{
		while (pos-- > 0)
			ra(c);
	}
	else
	{
		pos = c->a.size - pos;
		while (pos-- > 0)
			rra(c);
	}
}

void	bring_to_top_b(t_ctx *c, int idx)
{
	int	pos;

	pos = find_pos(&c->b, idx);
	if (pos <= c->b.size / 2)
	{
		while (pos-- > 0)
			rb(c);
	}
	else
	{
		pos = c->b.size - pos;
		while (pos-- > 0)
			rrb(c);
	}
}

int	max_bits(int n)
{
	int	bits;

	bits = 0;
	while ((n >> bits) != 0)
		bits++;
	return (bits);
}
