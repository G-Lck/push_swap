#include "push_swap.h"

void convert_arr_to_list(int* arr, t_list** stack_a, size_t len)
{
	size_t i;
	t_list* new_node;

	i = 0;
	while (i < len)
	{
		new_node = ft_lstnew(&arr[i]);
		if (!new_node)
			return ;
		ft_lstadd_back(stack_a, new_node);
		i++;
	}
}
