/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 12:00:00 by dianasta          #+#    #+#             */
/*   Updated: 2026/11/04 13:41:16 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chunk_size(int n)
{
	int	root;

	root = 1;
	while ((root + 1) * (root + 1) <= n)
		root++;
	return (n / root + 1);
}

static void	push_chunks(t_ctx *c, int chunk)
{
	int	pushed;

	pushed = 0;
	while (c->a.size > 0)
	{
		if (c->a.top->index < pushed)
		{
			pb(c);
			if (c->b.size > 1)
				rb(c);
			pushed++;
		}
		else if (c->a.top->index < pushed + chunk)
		{
			pb(c);
			pushed++;
		}
		else
			ra(c);
	}
}

void	sort_medium(t_ctx *c)
{
	push_chunks(c, chunk_size(c->a.size));
	while (c->b.size > 0)
	{
		bring_to_top_b(c, c->b.size - 1);
		pa(c);
	}
}
