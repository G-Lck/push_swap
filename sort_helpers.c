/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 00:00:00 by glucken           #+#    #+#             */
/*   Updated: 2025/11/21 00:00:00 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_value(t_list *stack)
{
	t_list	*current;
	int		min_val;

	current = stack;
	min_val = *(int *)current->content;
	while (current)
	{
		if (*(int *)current->content < min_val)
			min_val = *(int *)current->content;
		current = current->next;
	}
	return (min_val);
}

int	get_max_value(t_list *stack)
{
	t_list	*current;
	int		max_val;

	current = stack;
	max_val = *(int *)current->content;
	while (current)
	{
		if (*(int *)current->content > max_val)
			max_val = *(int *)current->content;
		current = current->next;
	}
	return (max_val);
}

void	put_value_to_top(t_list **stack_a, int value)
{
	int	pos;
	int	size;

	pos = get_position(*stack_a, value);
	size = ft_lstsize(*stack_a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rotate(stack_a, 'a');
	}
	else
	{
		while (pos++ < size)
			reverse_rotate(stack_a, 'a');
	}
}
