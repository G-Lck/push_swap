#include "push_swap.h"

void	swap(t_list **lst, char c)
{
	void *tmp;

	if (!lst || !*lst || !(*lst)->next)
		return;
	tmp = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = tmp;

	ft_printf("s%c\n", c);
}



