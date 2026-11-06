/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 12:00:00 by dianasta          #+#    #+#             */
/*   Updated: 2026/11/06 13:31:33 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_tokens(char **t)
{
	int	i;

	i = 0;
	while (t[i])
	{
		free(t[i]);
		i++;
	}
	free(t);
}

static int	is_number(char *s)
{
	if (*s == '+' || *s == '-')
		s++;
	if (!*s)
		return (0);
	while (ft_isdigit(*s))
		s++;
	return (*s == '\0');
}

static int	add_token(t_stack *a, char *tok)
{
	long	n;

	if (!is_number(tok))
		return (0);
	n = ft_atol(tok);
	if (n > INT_MAX || n < INT_MIN)
		return (0);
	if (stack_has(a, (int)n))
		return (0);
	return (stack_add_bottom(a, (int)n));
}

int	add_arg(t_stack *a, char *arg)
{
	char	**tokens;
	int		i;
	int		ok;

	tokens = ft_split(arg, ' ');
	if (!tokens)
		return (0);
	ok = (tokens[0] != NULL);
	i = 0;
	while (ok && tokens[i])
	{
		ok = add_token(a, tokens[i]);
		i++;
	}
	free_tokens(tokens);
	return (ok);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
