/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 12:00:00 by dianasta          #+#    #+#             */
/*   Updated: 2026/11/04 12:00:00 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *s)
{
	t_node	*first;
	t_node	*last;

	if (s->size < 2)
		return ;
	first = s->top;
	s->top = first->next;
	last = s->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	reverse_rotate(t_stack *s)
{
	t_node	*prev;
	t_node	*last;

	if (s->size < 2)
		return ;
	prev = s->top;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = s->top;
	s->top = last;
}
