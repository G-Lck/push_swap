/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest_element.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 00:00:00 by glucken           #+#    #+#             */
/*   Updated: 2025/11/21 00:00:00 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_cost(int cost1, int cost2, int cost3, int cost4)
{
	int	min;

	min = cost1;
	if (cost2 < min)
		min = cost2;
	if (cost3 < min)
		min = cost3;
	if (cost4 < min)
		min = cost4;
	return (min);
}

static int	get_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static int	min_moves(int nb, t_list *stack_a, t_list *stack_b)
{
	int	buddy;
	int	pos_a;
	int	pos_b;
	int	size_a;
	int	size_b;

	buddy = get_buddy(nb, stack_a);
	pos_a = get_position(stack_a, buddy);
	pos_b = get_position(stack_b, nb);
	size_a = ft_lstsize(stack_a);
	size_b = ft_lstsize(stack_b);
	return (get_min_cost(get_max(pos_a, pos_b),
			get_max(size_a - pos_a, size_b - pos_b),
			pos_a + (size_b - pos_b),
			(size_a - pos_a) + pos_b));
}

int	find_cheapest_element(t_list *stack_a, t_list *stack_b)
{
	int		min_cost;
	int		best_nb;
	t_list	*current;
	int		nb;
	int		cost;

	min_cost = INT_MAX;
	best_nb = -1;
	current = stack_b;
	while (current)
	{
		nb = *(int *)current->content;
		cost = min_moves(nb, stack_a, stack_b);
		if (cost < min_cost)
		{
			min_cost = cost;
			best_nb = nb;
		}
		current = current->next;
	}
	return (best_nb);
}
