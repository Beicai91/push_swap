/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcai <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:56:35 by bcai              #+#    #+#             */
/*   Updated: 2024/01/26 18:39:10 by bcai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a(char **strs, t_ablist **a, int argc)
{
	int			i;
	t_ablist	*newnode;

	if (argc == 2)
		i = 0;
	else
		i = 1;
	while (strs[i])
	{
		newnode = new (ft_atoi(strs[i]), -1);
		addback(a, newnode);
		i++;
	}
	if (argc == 2)
		ft_free(strs);
}

void	check_args_init(int argc, char **argv, t_ablist **a, int *i)
{
	char	**nums;
	long	num;

	*i = 0;
	if (argc == 2)
		nums = ft_split(argv[1], ' ');
	else
	{
		*i = 1;
		nums = argv;
	}
	while (nums[(*i)])
	{
		if (!ft_isnum(nums[*i]))
			report_error("Error");
		else
		{
			num = ft_atoi(nums[*i]);
			if (is_duplicated(num, nums, *i) || num < -2147483648
				|| num > 2147483647)
				report_error("Error");
		}
		(*i)++;
	}
	init_stack_a(nums, a, argc);
}
