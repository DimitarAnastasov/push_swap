/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 12:00:00 by dianasta          #+#    #+#             */
/*   Updated: 2026/11/04 12:00:00 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ctx_init(t_ctx *c)
{
	ft_bzero(c, sizeof(t_ctx));
	c->strat = ADAPTIVE;
}

int	stack_has(t_stack *s, int value)
{
	t_node	*n;

	n = s->top;
	while (n)
	{
		if (n->value == value)
			return (1);
		n = n->next;
	}
	return (0);
}

int	stack_add_bottom(t_stack *s, int value)
{
	t_node	*n;
	t_node	*last;

	n = malloc(sizeof(t_node));
	if (!n)
		return (0);
	n->value = value;
	n->index = -1;
	n->next = NULL;
	if (!s->top)
		s->top = n;
	else
	{
		last = s->top;
		while (last->next)
			last = last->next;
		last->next = n;
	}
	s->size++;
	return (1);
}

void	free_stack(t_stack *s)
{
	t_node	*tmp;

	while (s->top)
	{
		tmp = s->top->next;
		free(s->top);
		s->top = tmp;
	}
	s->size = 0;
}
