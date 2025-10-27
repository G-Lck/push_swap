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
	stack_a = copynumbers(str, ' ', count_words(str, ' '));

	if (!stack_a)
	{
		ft_printf("Error\n");
		return ;
	}

	if (!check_unicity(stack_a, count_words(str, ' ')))
	{
		ft_printf("Error\n");
		return ;
	}

	stack_a = sort(stack_a, count_words(str, ' '));

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
	//push_swap("27942877249283");
	//push_swap("12 3 2");
	//push_swap("3 1 4 5 6 9 8 7 10 -2 -3 -4 -5");
	push_swap("1 4 7 10 13 16 19 22 25 28 31 34 37 40 43 46 49 52 55 58 61 64 67 70 73 76 79 82 85 88 91 94 97 100 3 6 9 12 15 18 21 24 27 30 33 36 39 42 45 48 51 54 57 60 63 66 69 72 75 78 81 84 87 90 93 96 99 2 5 8 11 14 17 20 23 26 29 32 35 38 41 44 47 50 53 56 59 62 65 68 71 74 77 80 83 86 89 92 95 98");
}
