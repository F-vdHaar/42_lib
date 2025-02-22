/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:10:53 by fvon-der          #+#    #+#             */
/*   Updated: 2025/02/22 20:49:22 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_split(char **words, int j);
static int	ft_count_words(const char *s, char c);
static char	*ft_get_word(const char *s, char c, int *i);
static char	**ft_free_split(char **words, int j);

static int	ft_count_words(const char *s, char c)
{
	int	count;
	int	prev_char_is_delim;

	count = 0;
	prev_char_is_delim = 1;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
		{
			if (!prev_char_is_delim)
				prev_char_is_delim = 1;
		}
		else
		{
			if (prev_char_is_delim)
			{
				count++;
				prev_char_is_delim = 0;
			}
		}
		s++;
	}
	return (count);
}

static char	*ft_get_word(const char *s, char c, int *i)
{
	int	start;
	int	len;

	start = *i;
	len = 0;
	while (s[*i] == c)
		(*i)++;
	start = *i;
	while (s[*i] && s[*i] != c)
	{
		(*i)++;
		len++;
	}
	return (ft_substr(s, start, len));
}

static char	**ft_free_split(char **words, int j)
{
	while (j--)
		free(words[j]);
	free(words);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		word_count;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	word_count = ft_count_words(s, c);
	words = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words[j] = ft_get_word(s, c, &i);
			if (!words[j++])
				return (ft_free_split(words, j - 1));
		}
		else
			i++;
	} words[j] = NULL;
	return (words);
}

// void	ft_print_split_result(char **result)
// {
// 	int	i;

// 	if (!result)
// 	{
// 		ft_putstr_fd("Error: ft_split returned NULL\n", 2);
// 		return ;
// 	}
// 	i = 0;
// 	while (result[i])
// 	{
// 		ft_putstr_fd("\"", 1);
// 		ft_putstr_fd(result[i], 1);
// 		ft_putstr_fd("\"\n", 1);
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result);
// }

// int	main(void)
// {
// 	char	*test_str = "1 0 0 -1 -1 0 1 1 0 0";
// 	char	**result;

// 	result = ft_split(test_str, ' '); 
// 	ft_print_split_result(result);

// 	return (0);
// }
