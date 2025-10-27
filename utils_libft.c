#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dsize)
{
	size_t	i;

	i = 0;
	if (dsize == 0)
		return (ft_strlen(src));
	while (i + 1 < dsize && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s)
{
	char	*s_cpy;
	int		i;

	s_cpy = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!s_cpy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s_cpy[i] = s[i];
		i++;
	}
	s_cpy[i] = '\0';
	return (s_cpy);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && i < n - 1 && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	while (i < n)
	{
		temp_dest[i] = temp_src[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*temp_src;
	unsigned char	*temp_dest;

	if (!dest && !src)
		return (NULL);
	temp_src = (unsigned char *)src;
	temp_dest = (unsigned char *)dest;
	if (dest > src)
	{
		while (len--)
			temp_dest[len] = temp_src[len];
	}
	else
		ft_memcpy(dest, src, len);
	return (dest);
}
