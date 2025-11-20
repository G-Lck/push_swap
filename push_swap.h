/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:37:54 by glucken           #+#    #+#             */
/*   Updated: 2025/10/11 14:20:43 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include "libftprintf/libftprintf.h"
# include "libft/libft.h"

int		get_buddy(int me, t_list *lst);
void	instruction(t_list **stack_a, t_list **stack_b, size_t len);
int		lst_is_sorted(t_list *lst, char c);
int		check_unicity(int *arr, size_t len);
int		count_words(const char *s, char c);
int		*copynumbers(char *str, char c, size_t len_array);
void	push_swap(char *str);
void	push(t_list **lst1, t_list **lst2, char c);
void	rotate(t_list **lst, char c);
void	swap(t_list **lst, char c);
void	convert_arr_to_list(int *arr, t_list **stack_a, size_t len);
int		get_position(t_list *stack, int nb);
int		min_moves(int nb, t_list *stack_a, t_list *stack_b);
void	put_to_top(int nb, t_list **stack_a, t_list **stack_b);
void	reverse_rotate(t_list **lst, char c);
int		less_cost_in_stack_a(t_list *stack_a, t_list *stack_b);
int		find_min_value(t_list *stack);
int		calculate_average(t_list *stack);
void	sort_small_lists(t_list **stack_a, t_list **stack_b, size_t len);
void	push_to_b(t_list **stack_a, t_list **stack_b, size_t *len_a, size_t *len_b);
void	finalize_sorting(t_list **stack_a);
void	sort3(t_list **stack_a);
void	sort4(t_list **stack_a, t_list **stack_b);
void	sort5(t_list **stack_a, t_list **stack_b);
int		get_min_value(t_list *stack);
int		get_max_value(t_list *stack);
void	put_value_to_top(t_list **stack_a, int value);

#endif
