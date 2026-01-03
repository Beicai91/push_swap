/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caibei <caibei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:57:41 by bcai              #+#    #+#             */
/*   Updated: 2026/01/03 21:49:57 by caibei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_moves(t_ablist **a, t_ablist *target)
{
	int			distance;
	int			len;
	int			moves;
	t_ablist	*temp;

	temp = *a;
	len = 0;
	while (temp != NULL)
	{
		len++;
		if (temp->value == target->value)
			distance = len;
		temp = temp->next;
	}
	if (distance > len / 2 + 1)
	{
		moves = len - distance + 1;
		target->direction = -1;
	}
	else
	{
		moves = distance - 1;
		target->direction = 1;
	}
	return (moves);
}

void	move_chunk_helper(t_ablist **a, t_ablist **b, t_ablist *cheapest)
{
	int	moves;

	moves = get_moves(a, cheapest);
	if (cheapest->direction == -1)
	{
		while (moves-- > 0)
			rra(a);
	}
	else if (cheapest->direction == 1)
	{
		while (moves-- > 0)
			ra(a);
	}
	pb(a, b);
}

t_ablist	*find_cheapest(t_ablist **a)
{
	t_ablist	*cheapest;
	t_ablist	*temp;

	temp = *a;
	while (temp->is_chunk == 0)
		temp = temp->next;
	cheapest = temp;
	temp = *a;
	while (temp != NULL)
	{
		if (temp->is_chunk == 1)
		{
			if (get_moves(a, temp) <= get_moves(a, cheapest))
				cheapest = temp;
		}
		temp = temp->next;
	}
	return (cheapest);
}

void	move_chunk(t_ablist **a, t_ablist **b, int count)
{
	t_ablist	*cheapest;

	while (count-- > 0)
	{
		cheapest = find_cheapest(a);
		move_chunk_helper(a, b, cheapest);
	}
}

void	key_move(t_ablist **a, t_ablist **b, int *array, int quantity)
{
	int			n;
	int			count;
	int			key;
	t_ablist	*temp;

	n = 1;
	count = 3;
	while (count-- > 0)
	{
		key = array[quantity / 4 * n - 1];
		temp = *a;
		while (temp != NULL)
		{
			if (temp->value <= key)
				temp->is_chunk = 1;
			temp = temp->next;
		}
		move_chunk(a, b, quantity / 4);
		n++;
	}
}
