/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasse <cmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:46:14 by cmasse            #+#    #+#             */
/*   Updated: 2021/06/08 14:33:33 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s_temp;

	i = 0;
	s_temp = (char *)s;
	if (!c)
		return (s_temp + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == c)
		{
			return ((char *)(s += i));
		}
		i++;
	}
	return (0);
}
