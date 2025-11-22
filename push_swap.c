/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 00:00:00 by glucken           #+#    #+#             */
/*   Updated: 2025/11/21 00:00:00 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(char *str)
{
	int		*arr;
	t_list	*stack_a;
	t_list	*stack_b;
	size_t	word_count;

	stack_a = NULL;
	stack_b = NULL;
	if (!validate_and_parse(str, &arr, &word_count))
		return (ft_printf("Error\n"), 1);
	convert_arr_to_list(arr, &stack_a, word_count);
	free(arr);
	instruction(&stack_a, &stack_b, word_count);
	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}

int	handle_multiple_args(int argc, char **argv)
{
	char	*str;
	int		result;

	str = build_string_from_args(argc, argv);
	if (!str)
		return (ft_printf("Error\n"), 1);
	result = push_swap(str);
	free(str);
	return (result);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (ft_printf("Error\n"), 1);
	if (argc == 2)
		return (push_swap(argv[1]));
	else
		return (handle_multiple_args(argc, argv));
	return (0);
}
                            