/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 00:00:00 by glucken           #+#    #+#             */
/*   Updated: 2025/11/21 00:00:00 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort3(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	if (!*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	first = *(int *)(*stack_a)->content;
	second = *(int *)(*stack_a)->next->content;
	third = *(int *)(*stack_a)->next->next->content;
	if ((first > second) && (second < third) && (first < third))
		swap(stack_a, 'a');
	else if ((first > second) && (second > third) && (first > third))
	{
		swap(stack_a, 'a');
		reverse_rotate(stack_a, 'a');
	}
	else if ((first > second) && (second < third) && (first > third))
		rotate(stack_a, 'a');
	else if ((first < second) && (second > third) && (first < third))
	{
		swap(stack_a, 'a');
		rotate(stack_a, 'a');
	}
	else if ((first < second) && (second > third) && (first > third))
		reverse_rotate(stack_a, 'a');
}

void	sort4(t_list **stack_a, t_list **stack_b)
{
	int	min_val;

	min_val = get_min_value(*stack_a);
	put_value_to_top(stack_a, min_val);
	push(stack_a, stack_b, 'b');
	sort3(stack_a);
	push(stack_b, stack_a, 'a');
}

void	sort5(t_list **stack_a, t_list **stack_b)
{
	int	max_val;
	int	min_val;

	max_val = get_max_value(*stack_a);
	put_value_to_top(stack_a, max_val);
	push(stack_a, stack_b, 'b');
	min_val = get_min_value(*stack_a);
	put_value_to_top(stack_a, min_val);
	push(stack_a, stack_b, 'b');
	sort3(stack_a);
	push(stack_b, stack_a, 'a');
	push(stack_b, stack_a, 'a');
	rotate(stack_a, 'a');
}
