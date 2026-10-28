#include "push_swap.h"

static int	to_int(const char *s, int *out)
{
	long	r;
	int		neg;

	r = 0;
	neg = 1;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			neg = -1;
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		r = r * 10 + (*s++ - '0');
		if (r * neg > INT_MAX || r * neg < INT_MIN)
			return (0);
	}
	*out = (int)(r * neg);
	return (1);
}

static int	has_dup(int *d, int n)
{
	int	i;
	int	j;

	i = -1;
	while (++i < n)
	{
		j = i;
		while (++j < n)
			if (d[i] == d[j])
				return (1);
	}
	return (0);
}

static int	add_word(char *w, t_stack *a)
{
	return (to_int(w, &a->d[a->n++]));
}

static int	fill(char *s, t_stack *a)
{
	char	*w;
	int		ok;

	ok = 1;
	while (*s && ok)
	{
		while (*s == ' ' || (*s >= 9 && *s <= 13))
			s++;
		if (!*s)
			break ;
		w = s;
		while (*s && !(*s == ' ' || (*s >= 9 && *s <= 13)))
			s++;
		if (*s)
			*s++ = 0;
		ok = add_word(w, a);
	}
	return (ok);
}

static int	count_words(char *s)
{
	int	n;

	n = 0;
	while (*s)
	{
		while (*s == ' ' || (*s >= 9 && *s <= 13))
			s++;
		if (*s)
			n++;
		while (*s && !(*s == ' ' || (*s >= 9 && *s <= 13)))
			s++;
	}
	return (n);
}

int	parse_args(int ac, char **av, t_stack *a)
{
	int	i;
	int	cap;

	cap = 0;
	i = 0;
	while (++i < ac)
		cap += count_words(av[i]);
	a->d = malloc(sizeof(int) * (cap + 1));
	if (!a->d || cap == 0)
		return (0);
	a->n = 0;
	i = 0;
	while (++i < ac)
		if (!fill(av[i], a))
			return (0);
	return (!has_dup(a->d, a->n));
}

void	normalize(t_stack *a)
{
	int	*r;
	int	i;
	int	j;
	int	c;

	r = malloc(sizeof(int) * a->n);
	if (!r)
		exit(1);
	i = -1;
	while (++i < a->n)
	{
		c = 0;
		j = -1;
		while (++j < a->n)
			if (a->d[j] < a->d[i])
				c++;
		r[i] = c;
	}
	free(a->d);
	a->d = r;
}
