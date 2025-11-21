/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 00:00:00 by glucken           #+#    #+#             */
/*   Updated: 2025/11/21 00:00:00 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_and_free(char *s1, char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}

char	*build_string_from_args(int argc, char **argv)
{
	char	*result;
	int		i;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 1;
	while (i < argc && result)
	{
		result = join_and_free(result, argv[i]);
		if (result && i < argc - 1)
			result = join_and_free(result, " ");
		i++;
	}
	return (result);
}

int	validate_and_parse(char *str, int **arr, size_t *word_count)
{
	if (!str || ft_strlen(str) == 0)
		return (0);
	*word_count = count_words(str, ' ');
	if (*word_count == 0)
		return (0);
	*arr = copynumbers(str, ' ', *word_count);
	if (!*arr)
		return (0);
	if (!check_unicity(*arr, *word_count))
	{
		free(*arr);
		return (0);
	}
	return (1);
}

int	check_unicity(int *arr, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
