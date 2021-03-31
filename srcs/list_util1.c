/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 23:14:48 by honlee            #+#    #+#             */
/*   Updated: 2021/03/31 20:50:41 by honlee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_lstnew(void *content)
{
	t_list		*ret;

	ft_salloc((void **)&ret, 1, sizeof(t_list));
	ret->content = content;
	ret->next = NULL;
	return (ret);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list		*head;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	head = *lst;
	while (head->next != NULL)
		head = head->next;
	head->next = new;
}

char	*ft_lst_getdata(t_list_info *list_info)
{
	int		idx;
	t_list	*list;

	idx = -1;
	list = *(list_info->head);
	while (++idx < list_info->pos)
		list = list->next;
	return (list->content);
}
