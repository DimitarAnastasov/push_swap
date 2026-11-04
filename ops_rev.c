/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 12:00:00 by dianasta          #+#    #+#             */
/*   Updated: 2026/11/04 13:41:07 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_ctx *c)
{
	reverse_rotate(&c->a);
	record(c, OP_RRA, "rra\n");
}

void	rrb(t_ctx *c)
{
	reverse_rotate(&c->b);
	record(c, OP_RRB, "rrb\n");
}

void	rrr(t_ctx *c)
{
	reverse_rotate(&c->a);
	reverse_rotate(&c->b);
	record(c, OP_RRR, "rrr\n");
}
