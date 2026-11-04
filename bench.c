/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 12:00:00 by dianasta          #+#    #+#             */
/*   Updated: 2026/11/04 15:52:01 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_percent(double d)
{
	int	p;

	p = (int)(d * 10000.0 + 0.5);
	ft_putnbr_fd(p / 100, 2);
	ft_putchar_fd('.', 2);
	if (p % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(p % 100, 2);
	ft_putchar_fd('%', 2);
}

static char	*strat_name(int s)
{
	if (s == SIMPLE)
		return ("Simple / O(n^2)");
	if (s == MEDIUM)
		return ("Medium / O(n*sqrt(n))");
	return ("Complex / O(n*log(n))");
}

static void	put_strategy(t_ctx *c)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	if (c->strat == ADAPTIVE)
		ft_putstr_fd("Adaptive -> ", 2);
	ft_putendl_fd(strat_name(c->used), 2);
}

static void	put_counts(t_ctx *c)
{
	static char	*names[11] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
		"rra", "rrb", "rrr"};
	int			i;

	i = 0;
	while (i < 11)
	{
		ft_putstr_fd("[bench] ", 2);
		ft_putstr_fd(names[i], 2);
		ft_putstr_fd(": ", 2);
		ft_putnbr_fd(c->ops[i], 2);
		ft_putchar_fd('\n', 2);
		i++;
	}
}

void	print_bench(t_ctx *c)
{
	int	i;
	int	total;

	total = 0;
	i = 0;
	while (i < 11)
		total += c->ops[i++];
	ft_putstr_fd("[bench] disorder: ", 2);
	put_percent(c->disorder);
	ft_putchar_fd('\n', 2);
	put_strategy(c);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total, 2);
	ft_putchar_fd('\n', 2);
	put_counts(c);
}
