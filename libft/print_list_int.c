/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 00:00:00 by glucken           #+#    #+#             */
/*   Updated: 2025/11/21 00:00:00 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
