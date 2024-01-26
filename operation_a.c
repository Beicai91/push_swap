/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcai <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:57:07 by bcai              #+#    #+#             */
/*   Updated: 2024/01/26 18:36:47 by bcai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ablist **a)
{
	int	temp;

	temp = (*a)->value;
	(*a)->value = ((*a)->next)->value;
	((*a)->next)->value = temp;
	ft_putendl_fd("sa", 1);
}

/*
void	ss(t_ablist **a, t_ablist **b)
{
	sa(a);
	sb(b);
	ft_putendl_fd("ss", 1);
}*/

void	pa(t_ablist **a, t_ablist **b)
{
	t_ablist	*b_node;
	t_ablist	*temp;

	b_node = new ((*b)->value, (*b)->index);
	addfront(a, b_node);
	temp = *b;
	*b = (*b)->next;
	free(temp);
	ft_putendl_fd("pa", 1);
}

void	ra(t_ablist **a)
{
	t_ablist	*temp;
	t_ablist	*newnode;

	if (*a == NULL || (*a) == NULL)
		return ;
	newnode = new ((*a)->value, (*a)->index);
	addback(a, newnode);
	temp = *a;
	*a = (*a)->next;
	free(temp);
	ft_putendl_fd("ra", 1);
}

/*
void	rr(t_ablist **a, t_ablist **b)
{
	ra(a);
	rb(b);
	ft_putendl_fd("rr", 1);
}*/

void	rra(t_ablist **a)
{
	t_ablist	*temp;
	t_ablist	*second_to_last;
	t_ablist	*newnode;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = *a;
	while (temp->next != NULL)
	{
		second_to_last = temp;
		temp = temp->next;
	}
	newnode = new (temp->value, temp->index);
	addfront(a, newnode);
	second_to_last->next = NULL;
	free(temp);
	ft_putendl_fd("rra", 1);
}

/*
void	rrr(t_ablist **a, t_ablist **b)
{
	rra(a);
	rrb(b);
	ft_putendl_fd("rrr", 1);
}*/
