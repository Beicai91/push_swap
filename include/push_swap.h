/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caibei <caibei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:59:01 by bcai              #+#    #+#             */
/*   Updated: 2026/01/03 21:49:57 by caibei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct stack_list
{
	int					value;
	int					is_chunk;
	int					direction;
	int					index;
	struct stack_list	*next;
}						t_ablist;

t_ablist				*new(int value, int index);
void					addback(t_ablist **list, t_ablist *new);
void					addfront(t_ablist **list, t_ablist *new);
void					ft_free_stack(t_ablist **lst);
int						get_len(t_ablist *lst);

int						ft_isnum(char *str);
int						is_duplicated(long num, char **nums, int index);
void					ft_free(char **nums);
void					report_error(char *str);
void					check_args_init(int argc, char **argv, t_ablist **a,
							int *quantity);
void					check_args(char *nums[], int *i);
void					init_stack_a(char **strs, t_ablist **a, int argc);

void					sa(t_ablist **a);
void					pa(t_ablist **a, t_ablist **b);
void					pb(t_ablist **a, t_ablist **b);
void					ra(t_ablist **a);
void					rb(t_ablist **b);
void					rra(t_ablist **a);
void					rrb(t_ablist **b);

void					selection_sort_min(t_ablist **a, t_ablist **b, int n);
void					sort_min_helper(t_ablist **a, t_ablist **b,
							int distance, int len);
void					selection_sort_max(t_ablist **a, t_ablist **b, int n,
							int check);
void					sort_max_helper(t_ablist **a, t_ablist **b,
							int distance, int n);
void					sort_max_helper2(t_ablist **a, t_ablist **b,
							int distance, int len);
void					get_min(t_ablist **a, int *len, int *distance);
void					get_max(t_ablist **lst, int *len, int *distance);

void					bubble_sort(int *array, int len);
void					create_sort_array(t_ablist **a, int **array,
							int quantity);
int						get_moves(t_ablist **a, t_ablist *target);
void					move_chunk_helper(t_ablist **a, t_ablist **b,
							t_ablist *cheapest);
t_ablist				*find_cheapest(t_ablist **a);
void					move_chunk(t_ablist **a, t_ablist **b, int count);
void					key_move(t_ablist **a, t_ablist **b, int *array,
							int quantity);

void					chunk_selection(t_ablist **a, t_ablist **b,
							int quantity);
void					radix_sort(t_ablist **a, t_ablist **b, int quantity);
void					sort_2(t_ablist **a);
void					sort_3(t_ablist **a);
void					sort_5(t_ablist **a, t_ablist **b);

#endif
