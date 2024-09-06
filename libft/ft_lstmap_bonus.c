/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:52:28 by younghoc          #+#    #+#             */
/*   Updated: 2023/10/15 15:15:18 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*copy_node(void *c, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	void	*content;

	content = f(c);
	if (content == NULL)
		return (NULL);
	result = ft_lstnew(content);
	if (result == NULL)
	{
		del(content);
		return (NULL);
	}
	return (result);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*result_tail;
	t_list	*temp;

	result = NULL;
	result_tail = NULL;
	while (lst)
	{
		temp = copy_node(lst->content, f, del);
		if (temp == NULL)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		if (result == NULL)
			result = temp;
		else
			result_tail->next = temp;
		result_tail = temp;
		lst = lst->next;
	}
	return (result);
}
