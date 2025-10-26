#include "push_swap.h"

static int	ft_strlen_s(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

static int	count_words(const char *s)
{
	int	i;
	int	count;

	count = 0;
	if (ft_strlen_s(s, '\0') == 0)
		return (0);
	if (s[0] != ' ')
		count++;
	i = 1;
	while (s[i] != '\0')
	{
		if (s[i - 1] == ' ')
		{
			if (s[i] != ' ')
				count++;
		}
		i++;
	}
	return (count);
}

t_list	*parsing_str_to_list(char *str)
{
	t_list *stack_a;
	int n_words;
	int i;


	stack_a = NULL;
	i = 0;
	n_words = count_words(str);
	if (!n_words)
		return (0);
	ft_printf(" Here we have %i word \n", n_words);
	while (i < n_words)
	{
		ft_lstadd_back(&stack_a, ft_lstnew("yes"));
		ft_printf("yes\n");
		i++;
	}
	return (stack_a);

}
