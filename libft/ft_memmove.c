/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasse <cmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:05:05 by cmasse            #+#    #+#             */
/*   Updated: 2021/03/12 14:19:43 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*n_dst;
	unsigned char		*n_src;

	n_dst = (unsigned char *)dst;
	n_src = (unsigned char *)src;
	i = -1;
	if (n_dst == 0 && n_src == 0)
		return (0);
	if (dst > src)
	{
		while (len > 0)
		{
			n_dst[len - 1] = n_src[len - 1];
			len--;
		}
	}
	else
		while (++i < len)
			n_dst[i] = n_src[i];
	return (dst);
}
