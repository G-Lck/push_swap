/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 00:00:00 by glucken           #+#    #+#             */
/*   Updated: 2025/11/22 00:00:00 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

static int	is_sorted(t_list *stack_a, t_list *stack_b)
{
	int	prev;
	int	current;

	if (stack_b)
		return (0);
	if (!stack_a)
		return (1);
	while (stack_a->next)
	{
		prev = *(int *)stack_a->content;
		current = *(int *)stack_a->next->content;
		if (prev > current)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

static int	init_stacks(int argc, char **argv, t_list **stack_a, t_list **stack_b)
{
	char	*str;
	int		*arr;
	size_t	len;

	*stack_a = NULL;
	*stack_b = NULL;
	if (argc < 2)
		return (0);
	str = build_string_from_args(argc, argv);
	if (!str)
		return (0);
	if (!validate_and_parse(str, &arr, &len))
	{
		free(str);
		return (0);
	}
	convert_arr_to_list(arr, stack_a, len);
	free(arr);
	free(str);
	return (1);
}

static int	process_instructions(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!execute_operation(line, stack_a, stack_b))
		{
			printf("Error\n");
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (!init_stacks(argc, argv, &stack_a, &stack_b))
		return (1);
	if (!process_instructions(&stack_a, &stack_b))
	{
		free_list(&stack_a);
		free_list(&stack_b);
		return (1);
	}
	if (is_sorted(stack_a, stack_b))
		printf("OK\n");
	else
		printf("KO\n");
	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}
