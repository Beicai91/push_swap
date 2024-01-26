/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcai <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:58:14 by bcai              #+#    #+#             */
/*   Updated: 2024/01/26 18:38:44 by bcai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_ablist **a)
{
	if ((*a)->value > ((*a)->next)->value)
		sa(a);
}

void	sort_3(t_ablist **a)
{
	t_ablist	*temp1;
	t_ablist	*temp2;

	temp1 = (*a)->next;
	temp2 = temp1->next;
	if ((*a)->value > temp1->value)
		sa(a);
	if (temp2->value < (*a)->value)
		rra(a);
	else if (temp2->value < temp1->value)
	{
		rra(a);
		sa(a);
	}
}

void	sort_5(t_ablist **a, t_ablist **b)
{
	int	len;
	int	distance;

	get_min(a, &len, &distance);
	sort_min_helper(a, b, distance, len);
	get_min(a, &len, &distance);
	sort_min_helper(a, b, distance, len);
	sort_3(a);
	pa(a, b);
	pa(a, b);
}
