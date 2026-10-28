#include "push_swap.h"

static void	swap_top(t_stack *s)
{
	int	t;

	if (s->n < 2)
		return ;
	t = s->d[0];
	s->d[0] = s->d[1];
	s->d[1] = t;
}

static void	rotate(t_stack *s)
{
	int	i;
	int	t;

	if (s->n < 2)
		return ;
	t = s->d[0];
	i = -1;
	while (++i < s->n - 1)
		s->d[i] = s->d[i + 1];
	s->d[s->n - 1] = t;
}

static void	rrotate(t_stack *s)
{
	int	i;
	int	t;

	if (s->n < 2)
		return ;
	t = s->d[s->n - 1];
	i = s->n;
	while (--i > 0)
		s->d[i] = s->d[i - 1];
	s->d[0] = t;
}

static void	push(t_stack *from, t_stack *to)
{
	int	i;
	int	v;

	if (from->n == 0)
		return ;
	v = from->d[0];
	i = -1;
	while (++i < from->n - 1)
		from->d[i] = from->d[i + 1];
	from->n--;
	i = to->n + 1;
	while (--i > 0)
		to->d[i] = to->d[i - 1];
	to->d[0] = v;
	to->n++;
}

void	sa(t_stack *a) { swap_top(a); write(1, "sa\n", 3); }
void	sb(t_stack *b) { swap_top(b); write(1, "sb\n", 3); }
void	pa(t_stack *a, t_stack *b) { push(b, a); write(1, "pa\n", 3); }
void	pb(t_stack *a, t_stack *b) { push(a, b); write(1, "pb\n", 3); }
void	ra(t_stack *a) { rotate(a); write(1, "ra\n", 3); }
void	rb(t_stack *b) { rotate(b); write(1, "rb\n", 3); }
void	rra(t_stack *a) { rrotate(a); write(1, "rra\n", 4); }
void	rrb(t_stack *b) { rrotate(b); write(1, "rrb\n", 4); }
void	rr(t_stack *a, t_stack *b) { rotate(a); rotate(b); write(1, "rr\n", 3); }
void	rrr(t_stack *a, t_stack *b) { rrotate(a); rrotate(b); write(1, "rrr\n", 4); }
