/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 00:00:00 by glucken           #+#    #+#             */
/*   Updated: 2025/11/21 00:00:00 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strlen_s(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

int	count_words(const char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	if (ft_strlen_s(s, '\0') == 0)
		return (0);
	if (s[0] != c)
		count++;
	i = 1;
	while (s[i] != '\0')
	{
		if (s[i - 1] == c && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static int	validate_and_convert(char *word, int len)
{
	char	*itoa_result;
	int		result;

	itoa_result = ft_itoa(ft_atoi(word));
	if (!itoa_result)
		return (0);
	if (ft_strncmp(word, itoa_result, len) != 0)
	{
		free(itoa_result);
		return (0);
	}
	result = ft_atoi(word);
	free(itoa_result);
	return (result);
}

static int	process_word(char *str, int *arr, int i, int j)
{
	char	*word;
	int		len;
	int		result;

	len = ft_strlen_s(str + i, ' ');
	word = malloc(len + 1);
	if (!word)
		return (-1);
	ft_strlcpy(word, str + i, len + 1);
	result = validate_and_convert(word, len);
	if (result == 0 && ft_atoi(word) != 0)
	{
		free(word);
		return (-1);
	}
	arr[j] = result;
	free(word);
	return (0);
}

int	*copynumbers(char *str, char c, size_t len_array)
{
	int	*arr;
	int	i;
	int	j;

	arr = malloc(sizeof(int) * len_array);
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
		{
			if (process_word(str, arr, i, j) == -1)
			{
				free(arr);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	return (arr);
}
