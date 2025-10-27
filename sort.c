# include "push_swap.h"

static int	is_sorted(int* arr, size_t len)
{
	size_t i;

	i = 0;
	while (i < len - 1)
	{
		if (arr[i] > arr [i + 1])
				return (0);
		i++;
	}
	return (1);
}

void sort(int* arr, size_t len)
{
	size_t i;
	int temp;

	i = 0;
	temp = 0;
	if (len <= 1)
		return;

	while (i < len)
	{
		ft_printf("temp_arr[%d] = %d\n", (int)i, arr[i]);
		i++;
	}

	while (!is_sorted(arr, len))
	{
		i = 0;
		while ( i < len - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
			i++;
		}
	}
	return ;
}
