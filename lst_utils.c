/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcai <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:56:35 by bcai              #+#    #+#             */
/*   Updated: 2024/01/26 18:36:26 by bcai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// utils for list manipulation
t_ablist	*new(int value, int index)
{
	t_ablist	*newnode;

	newnode = malloc(sizeof(t_ablist) * 1);
	if (!newnode)
		return (NULL);
	newnode->value = value;
	newnode->index = index;
	newnode->is_chunk = 0;
	newnode->direction = 0;
	return (newnode);
}

void	addback(t_ablist **list, t_ablist *new)
{
	t_ablist	*temp;

	if (!(*list))
	{
		(*list) = new;
		return ;
	}
	temp = *list;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	new->next = NULL;
}

void	addfront(t_ablist **list, t_ablist *new)
{
	new->next = *list;
	*list = new;
}

int	get_len(t_ablist *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

void	ft_free_stack(t_ablist **lst)
{
	t_ablist	*temp;

	while (*lst != NULL)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
}
