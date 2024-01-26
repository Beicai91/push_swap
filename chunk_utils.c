/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_selection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcai <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:57:41 by bcai              #+#    #+#             */
/*   Updated: 2024/01/26 18:39:28 by bcai             ###   ########.fr       */
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

void	move_chunk_helper(t_ablist **a, t_ablist **b, t_ablist *chepeast)
{
	int	moves;

	moves = get_moves(a, chepeast);
	if (chepeast->direction == -1)
	{
		while (moves-- > 0)
			rra(a);
	}
	else if (chepeast->direction == 1)
	{
		while (moves-- > 0)
			ra(a);
	}
	pb(a, b);
}

t_ablist	*find_chepeast(t_ablist **a)
{
	t_ablist	*chepeast;
	t_ablist	*temp;

	temp = *a;
	while (temp->is_chunk == 0)
		temp = temp->next;
	chepeast = temp;
	temp = *a;
	while (temp != NULL)
	{
		if (temp->is_chunk == 1)
		{
			if (get_moves(a, temp) <= get_moves(a, chepeast))
				chepeast = temp;
		}
		temp = temp->next;
	}
	return (chepeast);
}

void	move_chunk(t_ablist **a, t_ablist **b, int count)
{
	t_ablist	*chepeast;

	while (count-- > 0)
	{
		chepeast = find_chepeast(a);
		move_chunk_helper(a, b, chepeast);
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