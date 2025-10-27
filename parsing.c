#include "push_swap.h"

static int	ft_strlen_s(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

int	count_words(const char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	if (ft_strlen_s(s, '\0') == 0)
		return (0);
	if (s[0] != c)
		count++;
	i = 1;
	while (s[i] != '\0')
	{
		if (s[i - 1] == c)
		{
			if (s[i] != c)
				count++;
		}
		i++;
	}
	return (count);
}

void	 copynumbers(int *arr, char *str, char c)
{
	int	len;
	int	i;
	char	*word;
	int		j;

	len = 0;
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
		{

			word = malloc (ft_strlen_s(str + i, c) + 1);
			if (!word)
			{
				return ;
			}
			len = ft_strlen_s(str + i, c);
			ft_strlcpy(word, str + i, len + 1);
			ft_printf("%s\n", word);
			ft_printf("%i\n", ft_atoi(word));
			if (ft_strncmp(word, ft_itoa(ft_atoi(word)), len))
			{
				free(word);
				arr = NULL;
				return ;
			}
			arr[j] = ft_atoi(word);
			free (word);
			j++;
		}
		i++;
	}
	return ;
}


