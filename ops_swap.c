/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 12:00:00 by dianasta          #+#    #+#             */
/*   Updated: 2026/11/04 12:00:00 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	record(t_ctx *c, int op, char *name)
{
	c->ops[op]++;
	ft_putstr_fd(name, 1);
}

void	sa(t_ctx *c)
{
	swap(&c->a);
	record(c, OP_SA, "sa\n");
}

void	sb(t_ctx *c)
{
	swap(&c->b);
	record(c, OP_SB, "sb\n");
}

void	ss(t_ctx *c)
{
	swap(&c->a);
	swap(&c->b);
	record(c, OP_SS, "ss\n");
}
