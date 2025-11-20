/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_cost_in_stack_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 00:00:00 by glucken           #+#    #+#             */
/*   Updated: 2025/11/21 00:00:00 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	less_cost_in_stack_a(t_list *stack_a, t_list *stack_b)
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
