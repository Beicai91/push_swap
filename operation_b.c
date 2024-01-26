/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcai <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:57:07 by bcai              #+#    #+#             */
/*   Updated: 2024/01/26 18:38:27 by bcai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	sb(t_ablist **b)
{
	int	temp;

	temp = (*b)->value;
	(*b)->value = ((*b)->next)->value;
	((*b)->next)->value = temp;
	ft_putendl_fd("sb", 1);
}*/

/*
void	ss(t_ablist **a, t_ablist **b)
{
	sa(a);
	sb(b);
	ft_putendl_fd("ss", 1);
}*/

void	pb(t_ablist **a, t_ablist **b)
{
	t_ablist	*a_node;
	t_ablist	*temp;

	a_node = new ((*a)->value, (*a)->index);
	addfront(b, a_node);
	temp = *a;
	*a = (*a)->next;
	free(temp);
	ft_putendl_fd("pb", 1);
}

void	rb(t_ablist **b)
{
	t_ablist	*temp;
	t_ablist	*newnode;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	newnode = new ((*b)->value, (*b)->index);
	addback(b, newnode);
	temp = *b;
	*b = (*b)->next;
	free(temp);
	ft_putendl_fd("rb", 1);
}

/*
void	rr(t_ablist **a, t_ablist **b)
{
	ra(a);
	rb(b);
	ft_putendl_fd("rr", 1);
}*/

void	rrb(t_ablist **b)
{
	t_ablist	*temp;
	t_ablist	*second_to_last;
	t_ablist	*newnode;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	temp = *b;
	while (temp->next != NULL)
	{
		second_to_last = temp;
		temp = temp->next;
	}
	newnode = new (temp->value, temp->index);
	addfront(b, newnode);
	second_to_last->next = NULL;
	free(temp);
	ft_putendl_fd("rrb", 1);
}

/*
void	rrr(t_ablist **a, t_ablist **b)
{
	rra(a);
	rrb(b);
	ft_putendl_fd("rrr", 1);
}*/
