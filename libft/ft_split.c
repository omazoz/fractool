/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omazoz <omazoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:54:03 by omazoz            #+#    #+#             */
/*   Updated: 2022/02/20 18:03:04 by omazoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static void	ft_free(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	ft_count(const char *str, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			j++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (j);
}

char	**ft_split2(char const *s, char c, int len, char **split)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] && i < len)
	{
		if (s[i] != c)
		{
			while (s[j] != c && j < len)
				j++;
			split[k] = ft_substr(s + i, 0, j - i + 1);
			if (!split[k])
				return (ft_free(split), NULL);
			split[k][j - i] = '\0';
			i = j;
			k++;
		}
		i++;
		j = i;
	}
	split[k] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	split = (char **)malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	ft_split2(s, c, len, split);
	return (split);
}
