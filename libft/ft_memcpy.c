/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasse <cmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:00:18 by cmasse            #+#    #+#             */
/*   Updated: 2020/12/01 16:35:18 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*n_dst;
	const char	*n_src;

	n_dst = (char *)dst;
	n_src = (const char *)src;
	if (n_dst == 0 && n_src == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		n_dst[i] = n_src[i];
		i++;
	}
	return (dst);
}
