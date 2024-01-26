/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_selection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcai <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:57:41 by bcai              #+#    #+#             */
/*   Updated: 2024/01/26 18:37:54 by bcai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort_min(t_ablist **a, t_ablist **b, int n)
{
	t_ablist	*min;
	t_ablist	*temp;
	int			distance;
	int			len;

	while (*a != NULL)
	{
		temp = *a;
		min = temp;
		get_min(a, &len, &distance);
		sort_min_helper(a, b, distance, len);
	}
	while (n-- > 0)
		pa(a, b);
}

void	selection_sort_max(t_ablist **a, t_ablist **b, int n, int check)
{
	int			distance;
	int			len;
	int			n_copy;

	n_copy = n;
	while (n > 0)
	{
		get_max(b, &len, &distance);
		if (check >= 2)
			sort_max_helper(a, b, distance, n);
		else if (check == 1)
			sort_max_helper2(a, b, distance, len);
		n--;
	}
}

void	chunk_selection(t_ablist **a, t_ablist **b, int quantity)
{
	int			*array;
	int			n;

	create_sort_array(a, &array, quantity);
	key_move(a, b, array, quantity);
	free(array);
	n = 4;
	selection_sort_min(a, b, quantity - (quantity / 4) * (n - 1));
	while ((n - 1) > 1)
	{
		selection_sort_max(a, b, quantity / 4, n);
		n--;
	}
	selection_sort_max(a, b, quantity / 4, n);
}

/*test a b
	printf("\na stack\n");
	t_ablist *temp_a;
	temp_a = *a;
	while (temp_a != NULL)
	{
		printf("%d, ", temp_a->value);
		temp_a = temp_a->next;
	}
	printf("\nb stack\n");
	t_ablist *temp_b;
	temp_b = *b;
	while (temp_b != NULL)
	{
		printf("%d, ", temp_b->value);
		temp_b = temp_b->next;
	}*/
