#include "push_swap.h"

double	get_mean(t_list *lst)
{
	double mean;
	int len;

	len = ft_lstsize(lst);
	mean = 0;
	while (lst->next)
	{
		mean += lst->content;
		lst++;
	}
	mean = mean / len;
	return (mean);
}
