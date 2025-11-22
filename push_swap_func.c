/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 00:00:00 by glucken           #+#    #+#             */
/*   Updated: 2025/11/22 00:00:00 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap_func(char *str)
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
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
