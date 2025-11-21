/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 00:00:00 by glucken           #+#    #+#             */
/*   Updated: 2025/11/21 00:00:00 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position(t_list *stack, int nb)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (*(int *)stack->content == nb)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

int	calculate_average(t_list *stack)
{
	int		sum;
	int		count;
	t_list	*current;

	sum = 0;
	count = 0;
	current = stack;
	while (current)
	{
		sum += *(int *)current->content;
		count++;
		current = current->next;
	}
	if (count > 0)
		return (sum / count);
	return (0);
}

void	push_to_b(t_list **stack_a, t_list **stack_b,
			size_t *len_a, size_t *len_b)
{
	int	average;
	int	top_element;

	while (*len_a > 2)
	{
		average = calculate_average(*stack_a);
		top_element = *(int *)(*stack_a)->content;
		if (top_element <= average)
		{
			push(stack_a, stack_b, 'b');
			(*len_b)++;
			(*len_a)--;
		}
		else
		{
			rotate(stack_a, 'a');
		}
	}
}

void	finalize_sorting(t_list **stack_a)
{
	int	min_val;
	int	min_pos;
	int	size_a;

	min_val = find_smallest(*stack_a);
	min_pos = get_position(*stack_a, min_val);
	size_a = ft_lstsize(*stack_a);
	if (min_pos <= size_a / 2)
	{
		while (min_pos-- > 0)
			rotate(stack_a, 'a');
	}
	else
	{
		while (min_pos++ < size_a)
			reverse_rotate(stack_a, 'a');
	}
}
