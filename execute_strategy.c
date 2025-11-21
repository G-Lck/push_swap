/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_strategy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 00:00:00 by glucken           #+#    #+#             */
/*   Updated: 2025/11/21 00:00:00 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_rr_strategy(t_list **stack_a, t_list **stack_b,
				int pos_a, int pos_b)
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

void	execute_rrr_strategy(t_list **stack_a, t_list **stack_b,
				int rev_a, int rev_b)
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

void	execute_ra_rrb_strategy(t_list **stack_a, t_list **stack_b,
				int pos_a, int pos_b)
{
	int	rev_b;
	int	size_b;

	while (pos_a-- > 0)
		rotate(stack_a, 'a');
	size_b = ft_lstsize(*stack_b);
	rev_b = size_b - pos_b;
	while (rev_b-- > 0)
		reverse_rotate(stack_b, 'b');
}

void	execute_rra_rb_strategy(t_list **stack_a, t_list **stack_b,
				int pos_a, int pos_b)
{
	int	rev_a;
	int	size_a;

	size_a = ft_lstsize(*stack_a);
	rev_a = size_a - pos_a;
	while (rev_a-- > 0)
		reverse_rotate(stack_a, 'a');
	while (pos_b-- > 0)
		rotate(stack_b, 'b');
}
