/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omazoz <omazoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:50:11 by omazoz            #+#    #+#             */
/*   Updated: 2021/11/30 04:17:29 by omazoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*d;
	unsigned const char	*s;
	size_t				size;

	d = (unsigned char *)dst;
	s = (unsigned const char *)src;
	i = 0;
	size = len;
	if (!d && !s)
		return (NULL);
	if (len == 0 || d == s)
		return (dst);
	if (d > s)
	{
		while (len--)
		{
			d[len] = s[len];
		}
	}
	else
		ft_memcpy(d, s, size);
	return (dst);
}
