/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_is_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 00:00:00 by glucken           #+#    #+#             */
/*   Updated: 2025/11/21 00:00:00 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
