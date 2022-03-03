/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omazoz <omazoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:16:07 by omazoz            #+#    #+#             */
/*   Updated: 2021/11/30 04:25:15 by omazoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *str, int c)
{
	char	*chaar ;

	chaar = (char *)str;
	while (*chaar != (char)c)
	{
		if (*chaar == '\0')
			return (0);
		chaar++;
	}
	return (chaar);
}
