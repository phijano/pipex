/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:24:39 by phijano-          #+#    #+#             */
/*   Updated: 2022/07/19 11:58:34 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpipex.h"

struct s_split {
	size_t	c;
	int		count_word;
	int		beg;
	char	sep;
	int		bar;
};

static int	ft_start(char c, int count)
{
	if (c == '\"' || c == '\'')
		return (count + 1);
	return (count);
}

static char	ft_check_quote(char to_check, char c)
{
	char	separator;

	separator = c;
	if (to_check == '\"' || to_check == '\'')
		separator = to_check;
	return (separator);
}

static int	ft_count_words(const char *str, char c)
{
	int				count_words;
	int				word;
	unsigned int	count;
	char			separator;

	count_words = 0;
	word = 0;
	count = -1;
	separator = c;
	while (str[++count])
	{
		if (str[count] != separator && word == 0)
		{
			word = 1;
			count_words++;
			separator = ft_check_quote(str[count], c);
		}
		else if (str[count] == separator)
		{
			word = 0;
			separator = c;
		}
	}
	return (count_words);
}

static void	ft_fill(char const *s, char c, char **split, struct s_split var)
{
	while (++var.c <= ft_strlen(s))
	{	
		if (var.c > 0)
		{
			if (s[var.c - 1] == '\\')
				var.bar = 1;
			else
				var.bar = 0;
		}
		if (s[var.c] != var.sep && var.beg < 0)
		{
			var.beg = ft_start(s[var.c], var.c);
			var.sep = ft_check_quote(s[var.c], c);
		}
		else if ((s[var.c] == var.sep || var.c == ft_strlen(s)) && var.beg >= 0
			&& !(var.sep == '\"' && var.bar == 1))
		{
			split[var.count_word] = ft_substr(s, var.beg, var.c - var.beg);
			var.count_word++;
			var.beg = -1;
			var.sep = c;
		}
	}
	split[var.count_word] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char			**split;
	struct s_split	var;

	split = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!(s && split))
		return (NULL);
	var.c = -1;
	var.count_word = 0;
	var.beg = -1;
	var.sep = c;
	var.bar = 0;
	ft_fill(s, c, split, var);
	if (!split)
		return (NULL);
	return (split);
}
