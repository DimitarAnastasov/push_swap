#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac < 2)
		return (0);
	if (!parse_args(ac, av, &a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	normalize(&a);
	b.d = malloc(sizeof(int) * a.n);
	if (!b.d)
		return (1);
	b.n = 0;
	sort(&a, &b);
	free(a.d);
	free(b.d);
	return (0);
}
