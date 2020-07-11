/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 14:04:11 by ytomiyos          #+#    #+#             */
/*   Updated: 2020/07/03 14:43:20 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;
	t_list	*li;

	li = *lst;
	if (!li)
		return ;
	while (li)
	{
		next = li->next;
		del(li->content);
		free(li);
		li = next;
	}
	*lst = NULL;
}
