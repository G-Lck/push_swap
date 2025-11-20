#include "push_swap.h"

int min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int max(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int min_of_4(int a, int b, int c, int d)
{
	int min1;
	int min2;

	min1 = min(a, b);
	min2 = min(c, d);
	return (min(min1, min2));
}

int get_position(int nb, t_list *stack)
{
	int i;
	int len;

	len = ft_lstsize(stack);
	i = 0;
	while (i < len)
	{
		if (stack->content = nb)
			break;
		i++;
		stack = stack->next
	}
	return (i);
}


