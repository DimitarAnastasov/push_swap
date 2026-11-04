/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 18:34:05 by dianasta          #+#    #+#             */
/*   Updated: 2026/08/02 00:27:34 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len);

static void	*free_array(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static int	count_words(const char *s, char c)
{
	size_t	i;
	int		wc;

	i = 0;
	wc = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			wc++;
		i++;
	}
	return (wc);
}

static char	*save_word(const char *s, char c, size_t *i)
{
	size_t	n;
	char	*word;

	n = 0;
	while (s[*i + n] && s[*i + n] != c)
		n++;
	word = ft_substr(s, *i, n);
	*i += n;
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	**output;
	size_t	i;
	int		wc;

	if (!s)
		return (NULL);
	output = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!output)
		return (NULL);
	i = 0;
	wc = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			output[wc] = save_word(s, c, &i);
			if (!output[wc])
				return (free_array(output, wc));
			wc++;
		}
	}
	output[wc] = NULL;
	return (output);
}
