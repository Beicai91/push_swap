/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_selection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcai <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:57:41 by bcai              #+#    #+#             */
/*   Updated: 2024/01/26 18:37:33 by bcai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *array, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (array[j] < array[i])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	create_sort_array(t_ablist **a, int **array, int quantity)
{
	int			i;
	t_ablist	*temp;

	*array = malloc(sizeof(int) * quantity);
	if (*array)
	{
		i = 0;
		temp = *a;
		while (temp != NULL)
		{
			(*array)[i] = temp->value;
			i++;
			temp = temp->next;
		}
	}
	else
		return ;
	bubble_sort(*array, quantity);
}
