/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:30:41 by younghoc          #+#    #+#             */
/*   Updated: 2023/10/15 11:48:07 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*nextnode;

	node = *lst;
	while (node)
	{
		nextnode = node->next;
		ft_lstdelone(node, del);
		node = nextnode;
	}
	*lst = NULL;
}
