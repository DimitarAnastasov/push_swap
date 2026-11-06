/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 16:05:47 by dianasta          #+#    #+#             */
/*   Updated: 2026/11/05 22:46:49 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	if (argc < 2)
		return (0);
	ctx_init(&ctx);
	if (!parse_args(argc, argv, &ctx))
	{
		free_stack(&ctx.a);
		write(2, "Error\n", 6);
		return (1);
	}
	rank_stack(&ctx.a);
	ctx.disorder = compute_disorder(&ctx.a);
	run_sort(&ctx);
	if (ctx.bench)
		print_bench(&ctx);
	free_stack(&ctx.a);
	free_stack(&ctx.b);
	return (0);
}
