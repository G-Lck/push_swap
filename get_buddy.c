#include "push_swap.h"

int get_buddy(int me, t_list *lst)
{
	int min_distance;
	int buddy;

	min_distance = INT_MAX;
	while (lst->next)
	{
		if (lst->content - me > 0)
			min_distance = min(lst->content - me, min_distance);
		if (min_distance == lst->content - me)
			buddy = lst->content;
		lst++;
	}
	return (buddy);
}
