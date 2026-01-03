/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcai <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:57:24 by bcai              #+#    #+#             */
/*   Updated: 2024/01/26 18:37:08 by bcai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_ablist	*get_min_value(t_ablist **a)
{
	t_ablist	*min;
	t_ablist	*temp;

	temp = *a;
	while (temp->index != -1)
		temp = temp->next;
	min = temp;
	while (temp != NULL)
	{
		if (min->value >= temp->value && temp->index == -1)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

static void	index_init(t_ablist **a, int quantity)
{
	int			i;
	t_ablist	*min;

	i = 0;
	while (i < quantity)
	{
		min = get_min_value(a);
		min->index = i;
		i++;
	}
}

static int	get_max_bits(t_ablist **a)
{
	t_ablist	*temp;
	t_ablist	*max;
	int			max_bits;

	temp = *a;
	max = temp;
	while (temp != NULL)
	{
		if (max->index <= temp->index)
			max = temp;
		temp = temp->next;
	}
	max_bits = 0;
	while (((max->index) >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_ablist **a, t_ablist **b, int quantity)
{
	int	max_bits;
	int	i;
	int	j;
	int	len;

	index_init(a, quantity);
	max_bits = get_max_bits(a);
	i = 0;
	len = get_len(*a);
	while (i < max_bits)
	{
		j = 0;
		while (j < len)
		{
			if ((((*a)->index) >> i & 1) == 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
