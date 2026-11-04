/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 12:00:00 by dianasta          #+#    #+#             */
/*   Updated: 2026/11/04 12:00:00 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *s)
{
	t_node	*n;

	n = s->top;
	while (n && n->next)
	{
		if (n->value > n->next->value)
			return (0);
		n = n->next;
	}
	return (1);
}

void	rank_stack(t_stack *s)
{
	t_node	*n;
	t_node	*m;

	n = s->top;
	while (n)
	{
		n->index = 0;
		m = s->top;
		while (m)
		{
			if (m->value < n->value)
				n->index++;
			m = m->next;
		}
		n = n->next;
	}
}

double	compute_disorder(t_stack *s)
{
	t_node	*i;
	t_node	*j;
	long	mistakes;
	long	total;

	mistakes = 0;
	total = 0;
	i = s->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total == 0)
		return (0.0);
	return ((double)mistakes / (double)total);
}
