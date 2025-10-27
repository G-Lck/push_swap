#include "push_swap.h"

int *convert_numbers_to_position(int* numbers, int* position, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;

	while (i < len)
	{
		j = 0;
		while ( j < len)
		{
			if (numbers[i] == position[j])
				break;
			j++;
		}
		numbers[i] = j;
		i++;
	}
	return (numbers);
}
