/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasse <cmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:35:01 by cmasse            #+#    #+#             */
/*   Updated: 2020/11/24 19:07:49 by cmasse           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*new;
	size_t	i;
	int		x;

	x = (unsigned char)c;
	new = s;
	i = 0;
	while (i < n)
	{
		*new = x;
		i++;
		new++;
	}
	return (s);
}
