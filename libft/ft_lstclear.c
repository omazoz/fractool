/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omazoz <omazoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 23:19:02 by omazoz            #+#    #+#             */
/*   Updated: 2021/11/30 04:11:34 by omazoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lst_free;
	t_list	*next;

	if (!lst)
		return ;
	lst_free = *lst;
	while (lst_free)
	{
		next = lst_free->next;
		ft_lstdelone(lst_free, del);
		lst_free = next;
	}
	*lst = NULL;
}
