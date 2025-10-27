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

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include "libftprintf/libftprintf.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int *convert_numbers_to_position(int* numbers, int* position, size_t len);
void	sort(int* arr, size_t len);
int	check_unicity(int *arr, size_t len);
int	count_words(const char *s, char c);
int * copynumbers(char *str, char c, size_t len_array);
void	push_swap(char* str);
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
void	swap(t_list **lst);
void	print_list_int(t_list *lst);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t dsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
char	**ft_split(const char *str, char c);

#endif
