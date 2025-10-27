#include "push_swap.h"

void	push_swap(char* str)
{
	int *stack_a;
	int i;

	i = 0;

	if(!str)
	{
		ft_printf("Error\n");
		return ;
	}
	stack_a = malloc(sizeof(int) * count_words(str, ' '));
	//t_list **stack_b;
	if (!stack_a)
	{
		ft_printf("Error\n");
		return ;
	}

	copynumbers(stack_a, str, ' ');
	if (!stack_a)
	{
		ft_printf("Error\n");
		return ;
	}

	while (i < count_words(str, ' '))
	{
		ft_printf("stack_a[%d] = %d\n", i, stack_a[i]);
		i++;
	}
	//print_list_int(stack_a);
	ft_printf("OK\n");
	free (stack_a);


}


int main()
{
	//push_swap("12 -3 5");
	push_swap("27942877249283");
	//push_swap("12 3 2");
	//push_swap("  1");
}
