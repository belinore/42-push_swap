/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:56:08 by belinore          #+#    #+#             */
/*   Updated: 2025/02/01 13:57:38 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_delimeter(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

int	count_words(char *str)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (str[i])
	{
		while (is_delimeter(str[i]) == 1)
			i++;
		if (str[i] == '\0')
			break ;
		while (is_delimeter(str[i]) == 0 && str[i])
			i++;
		word_count += 1;
	}
	return (word_count);
}

static void	copy_strings(char *src, char *dst, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

static int	allocate_word(char *str, char **result, int start_of_word)
{
	int	i;
	int	letters;

	i = start_of_word;
	letters = 0;
	while (is_delimeter(str[i]) == 1)
		i++;
	start_of_word = i;
	while (is_delimeter(str[i]) == 0 && str[i])
	{
		i++;
		letters++;
	}
	*result = malloc(sizeof(char) * (letters + 1));
	if (*result == NULL)
		return (-1);
	copy_strings(&str[start_of_word], *result, letters);
	return (i);
}

char	**ft_split(char *str)
{
	char	**result;
	int		i;
	int		words;
	int		start_of_word;

	if (str == NULL)
		return (NULL);
	words = count_words(str);
	start_of_word = 0;
	result = malloc(sizeof(char *) * (words + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < words)
	{
		start_of_word = allocate_word(str, &result[i], start_of_word);
		if (start_of_word == -1)
		{
			free_array(result, i);
			return (NULL);
		}
		i++;
	}
	result[words] = NULL;
	return (result);
}
