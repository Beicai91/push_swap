/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caibei <caibei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:57:58 by bcai              #+#    #+#             */
/*   Updated: 2026/01/03 23:24:34 by caibei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_sorted(t_ablist **a, t_ablist **b, int quantity)
{
	if (quantity == 2)
		sort_2(a);
	else if (quantity == 3)
		sort_3(a);
	else if (quantity == 5)
		sort_5(a, b);
	else if (quantity <= 100)
		chunk_selction(a, b, quantity);
	else
		radix_sort(a, b, quantity);
}

static int	is_sorted(t_ablist **a)
{
	t_ablist	*temp;
	int			indicator;

	indicator = 1;
	temp = *a;
	while (temp->next != NULL)
	{
		if (temp->value > (temp->next)->value)
			indicator = 0;
		temp = temp->next;
	}
	return (indicator);
}

int	main(int argc, char *argv[])
{
	t_ablist	*a;
	t_ablist	*b;
	int			quantity;

	if (argc < 2)
		return (0);
	if (argc == 2 && argv[1][0] == '\0')
		report_error("Error");
	a = NULL;
	b = NULL;
	check_args_init(argc, argv, &a, &quantity);
	if (argc != 2)
		quantity -= 1;
	if (is_sorted(&a))
	{
		ft_free_stack(&a);
		ft_free_stack(&b);
		return (0);
	}
	get_sorted(&a, &b, quantity);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}

/*/test
t_ablist		*temp;
temp = a;
while (temp != NULL)
{
	printf("%d, ", temp->value);
	temp = temp->next;
}*/
