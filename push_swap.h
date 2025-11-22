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

# include <limits.h>
# include "libftprintf/libftprintf.h"
# include "libft/libft.h"

/*
** ============================================================================
**                               MAIN FUNCTIONS
** ============================================================================
*/

/* Core program */
int		push_swap(char *str);

/*
** ============================================================================
**                            PARSING & VALIDATION
** ============================================================================
*/

/* Input processing */
int		count_words(const char *s, char c);
int		*copynumbers(char *str, char c, size_t len_array);
int		check_unicity(int *arr, size_t len);
void	convert_arr_to_list(int *arr, t_list **stack_a, size_t len);

/* String utilities */
char	*join_and_free(char *s1, char *s2);
char	*build_string_from_args(int argc, char **argv);
int		validate_and_parse(char *str, int **arr, size_t *word_count);
int		handle_multiple_args(int argc, char **argv);

/*
** ============================================================================
**                           STACK OPERATIONS
** ============================================================================
*/

/* Basic operations */
void	push(t_list **lst1, t_list **lst2, char c);
void	swap(t_list **lst, char c);
void	rotate(t_list **lst, char c);
void	reverse_rotate(t_list **lst, char c);

/* Basic operations without print */
void	push_no_print(t_list **lst1, t_list **lst2);
void	swap_no_print(t_list **lst);
void	rotate_no_print(t_list **lst);
void	reverse_rotate_no_print(t_list **lst);
int		execute_operation(char *line, t_list **stack_a, t_list **stack_b);

/* List helpers */
int		init_stacks(int argc, char **argv, t_list **stack_a, t_list **stack_b);
char	*get_next_line(int fd);
void	convert_arr_to_list(int *arr, t_list **stack_a, size_t len);
void	free_list(t_list **lst);
int		find_smallest(t_list *lst);

/*
** ============================================================================
**                           SORTING ALGORITHMS
** ============================================================================
*/

/* Main sorting logic */
void	instruction(t_list **stack_a, t_list **stack_b, size_t len);

/* Small size sorting */
void	sort_small_lists(t_list **stack_a, t_list **stack_b, size_t len);
void	sort3(t_list **stack_a);
void	sort4(t_list **stack_a, t_list **stack_b);
void	sort5(t_list **stack_a, t_list **stack_b);

/* Large size sorting */
void	push_to_b(t_list **stack_a, t_list **stack_b,
			size_t *len_a, size_t *len_b);
void	finalize_sorting(t_list **stack_a);

/*
** ============================================================================
**                           ALGORITHM HELPERS
** ============================================================================
*/

/* Position & movement calculations */
int		get_position(t_list *stack, int nb);
int		get_buddy(int me, t_list *lst);
int		find_cheapest_element(t_list *stack_a, t_list *stack_b);

/* Stack analysis */
int		lst_is_sorted(t_list *lst, char c);
int		get_min_value(t_list *stack);
int		get_max_value(t_list *stack);
int		calculate_average(t_list *stack);

/* Movement execution */
void	put_to_top(int nb, t_list **stack_a, t_list **stack_b);
void	put_value_to_top(t_list **stack_a, int value);

/* Execution strategies */
void	execute_rr_strategy(t_list **stack_a, t_list **stack_b,
			int pos_a, int pos_b);
void	execute_rrr_strategy(t_list **stack_a, t_list **stack_b,
			int rev_a, int rev_b);
void	execute_ra_rrb_strategy(t_list **stack_a, t_list **stack_b,
			int pos_a, int pos_b);
void	execute_rra_rb_strategy(t_list **stack_a, t_list **stack_b,
			int pos_a, int pos_b);

#endif
