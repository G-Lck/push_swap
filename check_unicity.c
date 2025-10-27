#include "push_swap.h"
int	check_unicity(int *arr, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

