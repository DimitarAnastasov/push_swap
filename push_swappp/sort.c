#include "push_swap.h"

int	is_sorted(t_stack *s)
{
	int	i;

	i = 0;
	while (++i < s->n)
		if (s->d[i - 1] > s->d[i])
			return (0);
	return (1);
}

int	find_pos(t_stack *s, int v)
{
	int	i;

	i = 0;
	while (s->d[i] != v)
		i++;
	return (i);
}

void	rot_to(t_stack *s, int pos, void (*r)(t_stack *), void (*rr)(t_stack *))
{
	if (pos <= s->n / 2)
		while (pos-- > 0)
			r(s);
	else
		while (pos++ < s->n)
			rr(s);
}

void	sort(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (a->n <= 5)
		return (sort_small(a, b));
	sort_turk(a, b);
}
