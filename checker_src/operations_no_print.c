/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_no_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 00:00:00 by glucken           #+#    #+#             */
/*   Updated: 2025/11/21 00:00:00 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_no_print(t_list **lst1, t_list **lst2)
{
	t_list	*first;

	if (!lst1 || !*lst1)
		return ;
	if (!lst2)
		return ;
	first = *lst1;
	*lst1 = first->next;
	ft_lstadd_front(lst2, first);
}

void	swap_no_print(t_list **lst)
{
	void	*tmp;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	tmp = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = tmp;
}

void	rotate_no_print(t_list **lst)
{
	t_list	*first;
	t_list	*last;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	first = *lst;
	*lst = first->next;
	first->next = NULL;
	last = ft_lstlast(*lst);
	if (last)
		last->next = first;
}

void	reverse_rotate_no_print(t_list **lst)
{
	t_list	*last;
	t_list	*second_last;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	last = ft_lstlast(*lst);
	second_last = *lst;
	while (second_last->next != last)
		second_last = second_last->next;
	second_last->next = NULL;
	last->next = *lst;
	*lst = last;
}
