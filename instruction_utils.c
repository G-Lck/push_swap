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

static int	find_min_value_internal(t_list *stack)
{
	int		min;
	t_list	*current;

	if (!stack)
		return (0);
	min = *(int *)stack->content;
	current = stack->next;
	while (current)
	{
		if (*(int *)current->content < min)
			min = *(int *)current->content;
		current = current->next;
	}
	return (min);
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

void	sort_small_lists(t_list **stack_a, t_list **stack_b, size_t len)
{
	if (len == 2)
	{
		if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
			swap(stack_a, 'a');
	}
	else if (len == 3)
		sort3(stack_a);
	else if (len == 4)
		sort4(stack_a, stack_b);
	else if (len == 5)
		sort5(stack_a, stack_b);
}

void	push_to_b(t_list **stack_a, t_list **stack_b, size_t *len_a, size_t *len_b)
{
	int	rotations;
	int	average;
	int	top_element;

	rotations = 0;
	while (*len_a > 2)
	{
		average = calculate_average(*stack_a);
		top_element = *(int *)(*stack_a)->content;
		if (top_element <= average)
		{
			push(stack_a, stack_b, 'b');
			(*len_b)++;
			(*len_a)--;
			rotations = 0;
		}
		else
		{
			rotate(stack_a, 'a');
			rotations++;
			if (rotations >= (int)*len_a)
			{
				push(stack_a, stack_b, 'b');
				(*len_b)++;
				(*len_a)--;
				rotations = 0;
			}
		}
	}
}

void	finalize_sorting(t_list **stack_a)
{
	int	min_val;
	int	min_pos;
	int	size_a;

	min_val = find_min_value_internal(*stack_a);
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
