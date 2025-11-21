/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 00:00:00 by glucken           #+#    #+#             */
/*   Updated: 2025/11/21 00:00:00 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list_int(t_list *lst)
{
	t_list	*cur;
	int		i;

	cur = lst;
	i = 0;
	if (!lst)
	{
		ft_printf("(empty)\n");
		return ;
	}
	while (cur)
	{
		if (cur->content)
			ft_printf("[%d] %d\n", i, *(int *)cur->content);
		else
			ft_printf("[%d] (null)\n", i);
		cur = cur->next;
		i++;
	}
}

void	free_stack(t_list **stack)
{
	t_list	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp->content);
		free(temp);
	}
}

int	lst_is_sorted(t_list *lst, char c)
{
	int	a;
	int	b;

	if (!lst)
		return (1);
	while (lst && lst->next)
	{
		if (!lst->content || !lst->next->content)
			return (0);
		a = *(int *)(lst->content);
		b = *(int *)(lst->next->content);
		if (c == 'a' && a > b)
			return (0);
		if (c == 'd' && a < b)
			return (0);
		if (c == 'i' && a != b - 1)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	convert_arr_to_list(int *arr, t_list **stack_a, size_t len)
{
	size_t	i;
	t_list	*new_node;
	int		*new_int;

	i = 0;
	while (i < len)
	{
		new_int = malloc(sizeof(int));
		if (!new_int)
			return ;
		*new_int = arr[i];
		new_node = ft_lstnew(new_int);
		if (!new_node)
		{
			free(new_int);
			return ;
		}
		ft_lstadd_back(stack_a, new_node);
		i++;
	}
}

int	find_smallest(t_list *lst)
{
	int	smallest;
	int	current_val;

	smallest = INT_MAX;
	while (lst)
	{
		current_val = *(int *)lst->content;
		if (current_val < smallest)
			smallest = current_val;
		lst = lst->next;
	}
	return (smallest);
}
