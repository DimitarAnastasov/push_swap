#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int	*d;
	int	n;
}	t_stack;

int		parse_args(int ac, char **av, t_stack *a);
void	normalize(t_stack *a);
int		is_sorted(t_stack *s);
void	sort(t_stack *a, t_stack *b);
void	sort_small(t_stack *a, t_stack *b);
void	sort3(t_stack *a);
void	sort_turk(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
int		find_pos(t_stack *s, int v);
void	rot_to(t_stack *s, int pos, void (*r)(t_stack *), void (*rr)(t_stack *));

#endif
