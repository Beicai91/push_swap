/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcai <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:56:35 by bcai              #+#    #+#             */
/*   Updated: 2024/01/26 15:56:44 by bcai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// utils for checking arguments
int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (str[i] == '\0' || (str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicated(long num, char **nums, int index)
{
	index++;
	while (nums[index])
	{
		if (num == ft_atoi(nums[index]))
			return (1);
		index++;
	}
	return (0);
}

void	ft_free(char **nums)
{
	int	i;

	i = 0;
	while (nums[i])
	{
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	report_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}
