/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 00:00:00 by glucken           #+#    #+#             */
/*   Updated: 2025/11/21 00:00:00 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static char	find_best_strategy(int cost_rr, int cost_rrr,
					int cost_ra_rrb, int cost_rra_rb)
{
	int		min;
	char	strategy;

	min = cost_rr;
	strategy = 'r';
	if (cost_rrr < min)
	{
		min = cost_rrr;
		strategy = 'R';
	}
	if (cost_ra_rrb < min)
	{
		min = cost_ra_rrb;
		strategy = 'x';
	}
	if (cost_rra_rb < min)
		strategy = 'X';
	return (strategy);
}

static char	get_move_strategy(int nb, t_list *stack_a, t_list *stack_b)
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
	return (find_best_strategy(get_max(pos_a, pos_b),
			get_max(size_a - pos_a, size_b - pos_b),
			pos_a + (size_b - pos_b),
			(size_a - pos_a) + pos_b));
}

void	put_to_top(int nb, t_list **stack_a, t_list **stack_b)
{
	int		buddy;
	int		pos_a;
	int		pos_b;
	char	strategy;

	buddy = get_buddy(nb, *stack_a);
	pos_a = get_position(*stack_a, buddy);
	pos_b = get_position(*stack_b, nb);
	strategy = get_move_strategy(nb, *stack_a, *stack_b);
	if (strategy == 'r')
		execute_rr_strategy(stack_a, stack_b, pos_a, pos_b);
	else if (strategy == 'R')
		execute_rrr_strategy(stack_a, stack_b,
			ft_lstsize(*stack_a) - pos_a, ft_lstsize(*stack_b) - pos_b);
	else if (strategy == 'x')
		execute_ra_rrb_strategy(stack_a, stack_b, pos_a, pos_b);
	else if (strategy == 'X')
		execute_rra_rb_strategy(stack_a, stack_b, pos_a, pos_b);
}
