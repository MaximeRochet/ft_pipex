/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:04:08 by mrochet           #+#    #+#             */
/*   Updated: 2021/03/12 14:16:34 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len_num(int n)
{
	int	len;

	if (n == 0)
		return (2);
	if (n < 0)
		len = 1;
	else
		len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

unsigned int	ft_absolute(int n)
{
	if (n == -0)
		n = 0;
	if (n <= 0)
		n *= -1;
	return (n);
}

char	*ft_itoa(int n)
{
	char			*ret;
	short			size;
	unsigned int	nb;

	size = len_num(n);
	nb = ft_absolute(n);
	ret = malloc(sizeof(char) * size + 1);
	if (!ret)
		return (NULL);
	if (n < 0)
		ret[0] = '-';
	if (n == 0)
		ret[0] = '0';
	ret[size] = '\0';
	while (nb > 0)
	{
		size--;
		ret[size] = (nb % 10) + 48;
		nb /= 10;
	}
	return (ret);
}
