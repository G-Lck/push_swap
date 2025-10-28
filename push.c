#include "push_swap.h"

void	push(t_list **lst1, t_list **lst2, char c)
{
	t_list *first;

	if (!lst1 || !*lst1)
		return;
	if (!lst2)
		return;

	first = *lst1;
	*lst1 = first->next;

	ft_lstadd_front(lst2, first);

	ft_printf("p%c\n", c);
}

