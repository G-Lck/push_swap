/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_buddy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 00:00:00 by glucken           #+#    #+#             */
/*   Updated: 2025/11/21 00:00:00 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_smallest(t_list *lst)
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

int	get_buddy(int me, t_list *lst)
{
	int		min_distance;
	int		buddy;
	int		current_val;
	int		found_bigger;
	t_list	*original_lst;

	min_distance = INT_MAX;
	buddy = me;
	found_bigger = 0;
	original_lst = lst;
	while (lst)
	{
		current_val = *(int *)lst->content;
		if (current_val > me && current_val - me < min_distance)
		{
			min_distance = current_val - me;
			buddy = current_val;
			found_bigger = 1;
		}
		lst = lst->next;
	}
	if (!found_bigger)
		buddy = find_smallest(original_lst);
	return (buddy);
}
