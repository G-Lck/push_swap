#include "push_swap.h"

void	push_swap(char* str)
{
	int *arr;
	int *temp_arr;
	t_list *stack_a = NULL;
	t_list *stack_b = NULL;
	//int i;

	//i = 0;

	if (!str || ft_strlen(str) == 0)
	{
		ft_printf("Error\n");
		return ;
	}

	if(!str)
	{
		ft_printf("Error\n");
		return ;
	}
	arr = copynumbers(str, ' ', count_words(str, ' '));

	if (!arr)
	{
		ft_printf("Error\n");
		return ;
	}

	if (!check_unicity(arr, count_words(str, ' ')))
	{
		ft_printf("Error\n");
		return ;
	}

	temp_arr = malloc(sizeof(int) * count_words(str, ' '));
	if (!temp_arr)
		return ;
	ft_memmove(temp_arr, arr, count_words(str, ' ') * sizeof(int));
	sort(temp_arr, count_words(str, ' '));

	arr = convert_numbers_to_position(arr, temp_arr, count_words(str, ' '));

	//while (i < count_words(str, ' '))
	//{
	//	ft_printf("stack_a[%d] = %d\n", i, arr[i]);
	//	i++;
	//}
	//print_list_int(stack_a);
	//ft_printf("OK\n");

	convert_arr_to_list(arr, &stack_a, count_words(str, ' '));

	instruction(&stack_a, &stack_b, count_words(str, ' '));

	//free (arr);

	//print_list_int(stack_a);


}


int main()
{
	//push_swap("12 -3 5 6 0");
	//push_swap("27942877249283");
	//push_swap("12 3 2");
	//push_swap("3 1 4 5 6 9 8 7 10 -2 -3 -4 -5");
	//push_swap("3 hey");
	//push_swap("1");
	//push_swap("");
	//push_swap("1 4 7 10 -3 3 0 -6 13");
	push_swap("19354 10278 14613 40567 20317 10610 24546 34568 8961 42670 39784 46536 15733 5143 29527 39137 14378 32675 15053 19545 2639 38295 33220 35012 49419 34339 24566 38974 11068 20575 4322 27705 22666 37690 1778 48344 27536 6673 45261 15628 48238 23411 33451 7974 20850 42436 24290 33320 10180 7309");
	//push_swap("1 4 7 10 13 16 19 22 25 28 31 34 37 40 43 46 49 52 55 58 61 64 67 70 73 76 79 82 85 88 91 94 97 100 3 6 9 12 15 18 21 24 27 30 33 36 39 42 45 48 51 54 57 60 63 66 69 72 75 78 81 84 87 90 93 96 99 2 5 8 11 14 17 20 23 26 29 32 35 38 41 44 47 50 53 56 59 62 65 68 71 74 77 80 83 86 89 92 95 98");
}
