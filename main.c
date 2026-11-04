/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 16:05:47 by dianasta          #+#    #+#             */
/*   Updated: 2026/11/04 13:40:51 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ctx	c;

	if (argc < 2)
		return (0);
	ctx_init(&c);
	if (!parse_args(argc, argv, &c))
	{
		free_stack(&c.a);
		write(2, "Error\n", 6);
		return (1);
	}
	rank_stack(&c.a);
	c.disorder = compute_disorder(&c.a);
	run_sort(&c);
	if (c.bench)
		print_bench(&c);
	free_stack(&c.a);
	free_stack(&c.b);
	return (0);
}
