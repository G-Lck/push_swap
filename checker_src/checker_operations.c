/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 00:00:00 by glucken           #+#    #+#             */
/*   Updated: 2025/11/22 00:00:00 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	handle_reverse_rotate(char *line, t_list **sa, t_list **sb)
{
	if (ft_strncmp(line, "rra\n", 4) == 0 ||
		ft_strncmp(line, "rra", 3) == 0)
		reverse_rotate_no_print(sa);
	else if (ft_strncmp(line, "rrb\n", 4) == 0 ||
			ft_strncmp(line, "rrb", 3) == 0)
		reverse_rotate_no_print(sb);
	else if (ft_strncmp(line, "rrr\n", 4) == 0 || ft_strncmp(line, "rrr", 3) == 0)
	{
		reverse_rotate_no_print(sa);
		reverse_rotate_no_print(sb);
	}
	else
		return (0);
	return (1);
}

static int	handle_other_ops(char *line, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(line, "sa\n", 3) == 0 || ft_strncmp(line, "sa", 2) == 0)
		swap_no_print(stack_a);
	else if (ft_strncmp(line, "sb\n", 3) == 0 || ft_strncmp(line, "sb", 2) == 0)
		swap_no_print(stack_b);
	else if (ft_strncmp(line, "ss\n", 3) == 0 || ft_strncmp(line, "ss", 2) == 0)
	{
		swap_no_print(stack_a);
		swap_no_print(stack_b);
	}
	else if (ft_strncmp(line, "pa\n", 3) == 0 || ft_strncmp(line, "pa", 2) == 0)
		push_no_print(stack_b, stack_a);
	else if (ft_strncmp(line, "pb\n", 3) == 0 || ft_strncmp(line, "pb", 2) == 0)
		push_no_print(stack_a, stack_b);
	else if (ft_strncmp(line, "ra\n", 3) == 0 || ft_strncmp(line, "ra", 2) == 0)
		rotate_no_print(stack_a);
	else if (ft_strncmp(line, "rb\n", 3) == 0 || ft_strncmp(line, "rb", 2) == 0)
		rotate_no_print(stack_b);
	else if (ft_strncmp(line, "rr\n", 3) == 0 || ft_strncmp(line, "rr", 2) == 0)
	{
		rotate_no_print(stack_a);
		rotate_no_print(stack_b);
	}
	else
		return (0);
	return (1);
}

int	execute_operation(char *line, t_list **stack_a, t_list **stack_b)
{

	if (handle_reverse_rotate(line, stack_a, stack_b))
		return (1);
	return (handle_other_ops(line, stack_a, stack_b));
}
