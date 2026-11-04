/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 12:00:00 by dianasta          #+#    #+#             */
/*   Updated: 2026/11/04 12:00:00 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ctx *c)
{
	rotate(&c->a);
	record(c, OP_RA, "ra\n");
}

void	rb(t_ctx *c)
{
	rotate(&c->b);
	record(c, OP_RB, "rb\n");
}

void	rr(t_ctx *c)
{
	rotate(&c->a);
	rotate(&c->b);
	record(c, OP_RR, "rr\n");
}
