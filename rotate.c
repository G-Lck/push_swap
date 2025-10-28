#include "push_swap.h"

void rotate(t_list **lst, char c)
{
	t_list *first;
	t_list *last;

	if (!lst || !*lst || !(*lst)->next)
		return;

	first = *lst;
	*lst = first->next;
	first->next = NULL;

	last = ft_lstlast(*lst);
	if (last)
		last->next = first;
	ft_printf("r%c\n", c);
}
