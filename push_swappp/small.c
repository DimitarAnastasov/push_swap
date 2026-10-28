#include "push_swap.h"

void	sort3(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->d[0];
	y = a->d[1];
	z = a->d[2];
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z)
		rra(a);
}

void	sort_small(t_stack *a, t_stack *b)
{
	int	v;

	if (a->n == 2)
		return (sa(a));
	v = 0;
	while (a->n > 3)
	{
		rot_to(a, find_pos(a, v++), ra, rra);
		pb(a, b);
	}
	sort3(a);
	while (b->n > 0)
		pa(a, b);
}
