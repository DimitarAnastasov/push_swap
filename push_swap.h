/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 16:32:21 by dianasta          #+#    #+#             */
/*   Updated: 2026/11/04 12:00:00 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
};

enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
};

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

typedef struct s_ctx
{
	t_stack	a;
	t_stack	b;
	int		strat;
	int		bench;
	int		ops[11];
	int		used;
	double	disorder;
}	t_ctx;

/* ft_atol.c, utils.c */
long	ft_atol(const char *str);
int		ft_strcmp(const char *s1, const char *s2);

/* stack.c */
void	ctx_init(t_ctx *c);
int		stack_add_bottom(t_stack *s, int value);
int		stack_has(t_stack *s, int value);
void	free_stack(t_stack *s);

/* parse.c, parse_utils.c */
int		parse_args(int argc, char **argv, t_ctx *c);
int		parse_flag(char *arg, t_ctx *c, int *strat_set);
int		add_arg(t_stack *a, char *arg);

/* ops_basic.c, ops_rotate.c: raw moves, no printing */
void	swap(t_stack *s);
void	push(t_stack *from, t_stack *to);
void	rotate(t_stack *s);
void	reverse_rotate(t_stack *s);

/* ops_*.c: the 11 printed and counted operations */
void	record(t_ctx *c, int op, char *name);
void	sa(t_ctx *c);
void	sb(t_ctx *c);
void	ss(t_ctx *c);
void	pa(t_ctx *c);
void	pb(t_ctx *c);
void	ra(t_ctx *c);
void	rb(t_ctx *c);
void	rr(t_ctx *c);
void	rra(t_ctx *c);
void	rrb(t_ctx *c);
void	rrr(t_ctx *c);

/* rank.c: sortedness, ranks, disorder */
int		is_sorted(t_stack *s);
void	rank_stack(t_stack *s);
double	compute_disorder(t_stack *s);

/* move.c: helpers shared by the strategies */
int		find_pos(t_stack *s, int idx);
void	bring_to_top_a(t_ctx *c, int idx);
void	bring_to_top_b(t_ctx *c, int idx);
int		max_bits(int n);

/* sort.c and the strategies */
void	run_sort(t_ctx *c);
void	sort_three(t_ctx *c);
void	sort_simple(t_ctx *c);
void	sort_medium(t_ctx *c);
void	sort_complex(t_ctx *c);

/* bench.c */
void	print_bench(t_ctx *c);

#endif
