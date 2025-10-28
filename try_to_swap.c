#include "push_swap.h"

void try_to_swap(t_list **lst, char c)
{
	if ((*lst)->next == NULL)
		return ;
	if (c == 'i' && *(int *)(*lst)->content > *(int *)(*lst)->next->content)
		swap(lst, 'a');
	if (c == 'd' && *(int *)(*lst)->content < *(int *)(*lst)->next->content)
		swap(lst, 'b');
}
