#include "push_swap.h"

void	push_swap(char* str)
{
	t_list *stack_a;

	stack_a = NULL;
	//t_list **stack_b;
	if (!str)
	{
		ft_printf("The input is wrong");
		return ;
	}

	stack_a = parsing_str_to_list(str);
	if(!stack_a)
		return ;
	//ft_printf("%s\n", (*stack_a)->content);
	ft_printf("OK\n");

}


int main()
{
	push_swap("hey hey");
}
