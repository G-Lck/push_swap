/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 00:00:00 by glucken           #+#    #+#             */
/*   Updated: 2025/11/21 00:00:00 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	absval(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static size_t	get_size(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		len = len + 1;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;
	int		sign;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = (n < 0);
	n = absval(n);
	result = malloc(sizeof(char) * (get_size(n) + sign + 1));
	if (!result)
		return (NULL);
	if (sign)
		result[0] = '-';
	i = get_size(n) - 1 + sign;
	result[get_size(n) + sign] = '\0';
	while (i >= sign)
	{
		result[i--] = '0' + n % 10;
		n = n / 10;
	}
	return (result);
}
