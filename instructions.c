/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 00:00:00 by glucken           #+#    #+#             */
/*   Updated: 2025/11/21 00:00:00 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	instruction(t_list **stack_a, t_list **stack_b, size_t len)
{
	size_t	len_a;
	size_t	len_b;
	int		nb;

	if (lst_is_sorted(*stack_a, 'a'))
		return ;
	if (len <= 5)
	{
		sort_small_lists(stack_a, stack_b, len);
		return ;
	}
	len_a = len;
	len_b = 0;
	push_to_b(stack_a, stack_b, &len_a, &len_b);
	if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
		swap(stack_a, 'a');
	while (len_b--)
	{
		nb = find_cheapest_element(*stack_a, *stack_b);
		put_to_top(nb, stack_a, stack_b);
		push(stack_b, stack_a, 'a');
	}
	finalize_sorting(stack_a);
}
