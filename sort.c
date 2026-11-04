/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 12:00:00 by dianasta          #+#    #+#             */
/*   Updated: 2026/11/04 13:41:21 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	adaptive_pick(double disorder)
{
	if (disorder < 0.2)
		return (SIMPLE);
	if (disorder < 0.5)
		return (MEDIUM);
	return (COMPLEX);
}

void	run_sort(t_ctx *c)
{
	c->used = c->strat;
	if (c->strat == ADAPTIVE)
		c->used = adaptive_pick(c->disorder);
	if (is_sorted(&c->a))
		return ;
	if (c->used == SIMPLE)
		sort_simple(c);
	else if (c->used == MEDIUM)
		sort_medium(c);
	else
		sort_complex(c);
}
