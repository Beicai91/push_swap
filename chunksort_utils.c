/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcai <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:58:14 by bcai              #+#    #+#             */
/*   Updated: 2024/01/26 18:40:24 by bcai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_min_helper(t_ablist **a, t_ablist **b, int distance, int len)
{
	int	moves;

	if (distance > len / 2 + 1)
	{
		moves = len - distance + 1;
		while (moves-- > 0)
			rra(a);
	}
	else
	{
		while (distance-- > 1)
			ra(a);
	}
	pb(a, b);
}

void	sort_max_helper(t_ablist **a, t_ablist **b, int distance, int n)
{
	int	moves;

	if (distance <= n)
	{
		moves = distance - 1;
		while (moves-- > 0)
			rb(b);
	}
	else
	{
		moves = get_len(*b) - distance + 1;
		while (moves-- > 0)
			rrb(b);
	}
	pa(a, b);
}

void	sort_max_helper2(t_ablist **a, t_ablist **b, int distance, int len)
{
	int	moves;

	if (distance > len / 2 + 1)
	{
		moves = len - distance + 1;
		while (moves-- > 0)
			rrb(b);
	}
	else
	{
		while (distance-- > 1)
			rb(b);
	}
	pa(a, b);
}

void	get_min(t_ablist **a, int *len, int *distance)
{
	t_ablist	*min;
	t_ablist	*temp;

	temp = *a;
	min = temp;
	*len = 0;
	*distance = 0;
	while (temp != NULL)
	{
		if (temp->value < min->value)
		{
			min = temp;
			*distance = *len + 1;
		}
		temp = temp->next;
		(*len)++;
	}
}

void	get_max(t_ablist **lst, int *len, int *distance)
{
	t_ablist	*temp;
	t_ablist	*max;

	temp = *lst;
	max = temp;
	*len = 0;
	*distance = 0;
	while (temp != NULL)
	{
		(*len)++;
		if (temp->value > max->value)
		{
			max = temp;
			(*distance) = (*len);
		}
		temp = temp->next;
	}
}

