/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:33:14 by dianasta          #+#    #+#             */
/*   Updated: 2026/11/05 23:02:42 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	strat_from_arg(char *arg)
{
	if (!ft_strcmp(arg, "--simple"))
		return (SIMPLE);
	if (!ft_strcmp(arg, "--medium"))
		return (MEDIUM);
	if (!ft_strcmp(arg, "--complex"))
		return (COMPLEX);
	if (!ft_strcmp(arg, "--adaptive"))
		return (ADAPTIVE);
	return (-1);
}

/* returns 1 = flag handled, 0 = not a flag, -1 = bad flag */
int	parse_flag(char *arg, t_ctx *c, int *strat_set)
{
	int	s;

	if (!ft_strcmp(arg, "--bench"))
	{
		c->bench = 1;
		return (1);
	}
	s = strat_from_arg(arg);
	if (s >= 0)
	{
		if (*strat_set)
			return (-1);
		*strat_set = 1;
		c->strat = s;
		return (1);
	}
	return (0);
}

int	parse_args(int argc, char **argv, t_ctx *c)
{
	int	i;
	int	r;//chnage name
	int	strat_set;

	strat_set = 0;
	i = 1;
	while (i < argc)
	{
		r = parse_flag(argv[i], c, &strat_set);
		if (r < 0)
			return (0);
		if (r == 0 && !add_arg(&c->a, argv[i]))
			return (0);
		i++;
	}
	return (1);
}
