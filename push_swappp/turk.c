#include "push_swap.h"

static int	rcost(t_stack *s, int pos)
{
	if (pos <= s->n / 2)
		return (pos);
	return (pos - s->n);
}

static int	target_in_b(t_stack *b, int v)
{
	int	i;
	int	best;
	int	max;

	best = -1;
	max = 0;
	i = -1;
	while (++i < b->n)
	{
		if (b->d[i] < v && (best == -1 || b->d[i] > b->d[best]))
			best = i;
		if (b->d[i] > b->d[max])
			max = i;
	}
	if (best == -1)
		return (max);
	return (best);
}

static int	target_in_a(t_stack *a, int v)
{
	int	i;
	int	best;
	int	min;

	best = -1;
	min = 0;
	i = -1;
	while (++i < a->n)
	{
		if (a->d[i] > v && (best == -1 || a->d[i] < a->d[best]))
			best = i;
		if (a->d[i] < a->d[min])
			min = i;
	}
	if (best == -1)
		return (min);
	return (best);
}

static int	total(int x, int y)
{
	if ((x >= 0) == (y >= 0))
		return (abs(x) > abs(y) ? abs(x) : abs(y));
	return (abs(x) + abs(y));
}

static void	do_moves(t_stack *a, t_stack *b, int x, int y)
{
	while (x > 0 && y > 0)
	{
		rr(a, b);
		x--;
		y--;
	}
	while (x < 0 && y < 0)
	{
		rrr(a, b);
		x++;
		y++;
	}
	while (x > 0 && x--)
		ra(a);
	while (x < 0 && x++ < 0)
		rra(a);
	while (y > 0 && y--)
		rb(b);
	while (y < 0 && y++ < 0)
		rrb(b);
}

void	sort_turk(t_stack *a, t_stack *b)
{
	int	i;
	int	best;
	int	bx;

	pb(a, b);
	pb(a, b);
	while (a->n > 3)
	{
		best = -1;
		i = -1;
		while (++i < a->n)
			if (best == -1 || total(rcost(a, i), rcost(b, target_in_b(b, a->d[i]))) < best)
			{
				best = total(rcost(a, i), rcost(b, target_in_b(b, a->d[i])));
				bx = i;
			}
		do_moves(a, b, rcost(a, bx), rcost(b, target_in_b(b, a->d[bx])));
		pb(a, b);
	}
	sort3(a);
	while (b->n > 0)
	{
		do_moves(a, b, rcost(a, target_in_a(a, b->d[0])), 0);
		pa(a, b);
	}
	rot_to(a, find_pos(a, 0), ra, rra);
}
