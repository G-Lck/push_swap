#include "push_swap.h"

void	instruction(t_list **stack_a, t_list **stack_b, size_t len)
{
	size_t len_a;
	size_t len_b;
	long unsigned int sum_a;
	long unsigned int sum_b;

	len_a = len;
	len_b = 0;

	sum_a = (len_a * (len_a - 1)) / 2 ;
	sum_b = 0;

	//ft_printf("stack_a head content before convert = %i\n", *(int *)((*stack_a)->content));
	//int v = *(int *)((*stack_a)->content);

	//ft_printf("len_a == len ? %i\n", len_a == len);
	//ft_printf("lst_is_sorted ? %i\n", lst_is_sorted(*stack_a, 'i'));
	//ft_printf("condition ? %i\n", !(len_a == len && lst_is_sorted(*stack_a, 'i')));
	while (!(len_a == len && lst_is_sorted(*stack_a, 'i')))
	{
		while (!lst_is_sorted(*stack_a, 'i'))
		{
			if ((long unsigned) *(int *)(*stack_a)->content > sum_a / len_a)
			{
				rotate(stack_a, 'a');
			}else
			{
				sum_a = sum_a - (long unsigned) *(int *)(*stack_a)->content;
				len_a--;
				push(stack_a, stack_b, 'b');
				sum_b = sum_b + (long unsigned) *(int *)(*stack_b)->content;
				len_b++;
				try_to_swap(stack_b, 'd');
			}
		}
		//ft_printf("stack_a head content now = %i\n", *(int *)((*stack_a)->content));
		//ft_printf("stack_b head content now = %i\n", *(int *)((*stack_b)->content));
		while (len_b != 0 && !lst_is_sorted(*stack_b, 'd'))
		{
			if ((long unsigned) *(int *)(*stack_b)->content < sum_b / len_b)
			{
				rotate(stack_b, 'b');
			}else
			{
				sum_b = sum_b - (long unsigned) *(int *)(*stack_b)->content;
				len_b--;
				push(stack_b, stack_a, 'a');
				sum_a = sum_a + (long unsigned) *(int *)(*stack_a)->content;
				len_a++;
				try_to_swap(stack_a, 'i');
			}

		}
		if (lst_is_sorted(*stack_a, 'i') && lst_is_sorted(*stack_b, 'd'))
		{
			while (len_b > 0)
			{
				push(stack_b, stack_a, 'a');
				len_a++;
				len_b--;
			}
		}
	}
	//print_list_int(*stack_a);
}
