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

static char	find_best_strategy(int cost_rr, int cost_rrr, int cost_ra_rrb, int cost_rra_rb)
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

static char get_move_strategy(int nb, t_list *stack_a, t_list *stack_b)
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

static void execute_rr_strategy(t_list **stack_a, t_list **stack_b, int pos_a, int pos_b)
{
	while (pos_a > 0 && pos_b > 0)
	{
		rotate(stack_a, 'a');
		rotate(stack_b, 'b');
		pos_a--;
		pos_b--;
	}
	while (pos_a-- > 0)
		rotate(stack_a, 'a');
	while (pos_b-- > 0)
		rotate(stack_b, 'b');
}

static void execute_rrr_strategy(t_list **stack_a, t_list **stack_b, int rev_a, int rev_b)
{
	while (rev_a > 0 && rev_b > 0)
	{
		reverse_rotate(stack_a, 'a');
		reverse_rotate(stack_b, 'b');
		rev_a--;
		rev_b--;
	}
	while (rev_a-- > 0)
		reverse_rotate(stack_a, 'a');
	while (rev_b-- > 0)
		reverse_rotate(stack_b, 'b');
}

static void execute_mixed_strategy(t_list **stack_a, t_list **stack_b, char strategy, int pos_a, int pos_b, int size_a, int size_b)
{
	int	rev_b;
	int	rev_a;

	if (strategy == 'x')
	{
		while (pos_a-- > 0)
			rotate(stack_a, 'a');
		rev_b = size_b - pos_b;
		while (rev_b-- > 0)
			reverse_rotate(stack_b, 'b');
	}
	else if (strategy == 'X')
	{
		rev_a = size_a - pos_a;
		while (rev_a-- > 0)
			reverse_rotate(stack_a, 'a');
		while (pos_b-- > 0)
			rotate(stack_b, 'b');
	}
}

void put_to_top(int nb, t_list **stack_a, t_list **stack_b)
{
	int		buddy;
	int		pos_a;
	int		pos_b;
	int		size_a;
	int		size_b;
	char	strategy;

	buddy = get_buddy(nb, *stack_a);
	pos_a = get_position(*stack_a, buddy);
	pos_b = get_position(*stack_b, nb);
	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	strategy = get_move_strategy(nb, *stack_a, *stack_b);
	if (strategy == 'r')
		execute_rr_strategy(stack_a, stack_b, pos_a, pos_b);
	else if (strategy == 'R')
		execute_rrr_strategy(stack_a, stack_b, size_a - pos_a, size_b - pos_b);
	else
		execute_mixed_strategy(stack_a, stack_b, strategy, pos_a, pos_b, size_a, size_b);
}


