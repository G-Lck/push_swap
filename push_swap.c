/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 00:00:00 by glucken           #+#    #+#             */
/*   Updated: 2025/11/21 00:00:00 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(char *str)
{
	int		*arr;
	t_list	*stack_a;
	t_list	*stack_b;
	size_t	word_count;

	stack_a = NULL;
	stack_b = NULL;
	if (!str || ft_strlen(str) == 0)
	{
		ft_printf("Error\n");
		return ;
	}
	word_count = count_words(str, ' ');
	arr = copynumbers(str, ' ', word_count);
	if (!arr)
	{
		ft_printf("Error\n");
		return ;
	}
	if (!check_unicity(arr, word_count))
	{
		ft_printf("Error\n");
		return ;
	}
	convert_arr_to_list(arr, &stack_a, word_count);
	instruction(&stack_a, &stack_b, word_count);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	push_swap(argv[1]);
	return (0);
}
