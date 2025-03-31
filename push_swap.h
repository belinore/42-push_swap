/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:20:26 by belinore          #+#    #+#             */
/*   Updated: 2025/02/04 18:33:05 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct d_list
{
	int				value;
	int				index;
	int				cost;
	char			stack;
	struct d_list	*prev;
	struct d_list	*next;
}					t_list;

typedef struct d_rotations
{
	int				ra;
	int				rra;
	int				rb;
	int				rrb;
	int				rr;
	int				rrr;
}					t_rot;

// ft_split.c
char				**ft_split(char *str);
int					count_words(char *str);

// general_utils.c
void				free_array(char **str_array, int index);
int					higher_value(int a, int b);
void				ft_putstr_fd(char *s, int fd);

// list_utils.c
t_list				*create_new_node(int value);
t_list				*add_to_front(t_list *tail, t_list *new_node);
int					list_size(t_list *tail);
void				clear_list(t_list **tail);

// sorting_algorithm.c
void				sort_list_simple(t_list **tail);
void				sort_list_long(t_list **stack_a, t_list **stack_b);
void				push_best_option(t_list **tail_a, t_list **tail_b,
						t_rot *ops, char src_stack);
t_list				*get_node_to_push(t_list **tail);
t_list				*get_insertion_target(t_list *src_node, t_list **dst_stack,
						char dst_name);

// sorting_calculation.c
void				assign_cost(t_list **src_stack, t_list **dst_stack,
						t_rot *rotations);
int					evaluate_options(t_list *src_node, t_list *dst_node,
						t_rot *ops, int *cost);
void				update_ops(t_rot *rotate_ops, int lowest_cost_option);
void				set_index(t_list **tail, char stack);

// sorting_utils.c
int					is_sorted(t_list *tail);
void				exec_rotations(t_list **tail_a, t_list **tail_b,
						t_rot *ops);
t_list				*get_min(t_list **tail);
t_list				*get_max(t_list **tail);

// add_args_to_stack.c
long				atol_push_swap(const char *str, t_list **list,
						char **str_array, int mem2free);
void				error_clear_list(t_list **tail_a, t_list **tail_b,
						char **str_array, int mem2free);
t_list				*add_args_to_stack(char **array, int size, int mem2free);

// operations_push.c
void				push(t_list **tail_a, t_list **tail_b, char src_stack);
void				pa(t_list **tail_a, t_list **tail_b);
void				pb(t_list **tail_a, t_list **tail_b);

// operations_rotate_fwd.c
void				ra(t_list **tail_a, int print_flag);
void				rb(t_list **tail_b, int print_flag);
void				rr(t_list **tail_a, t_list **tail_b);

// operations_rotate_rev.c
void				rra(t_list **tail, int print_flag);
void				rrb(t_list **tail, int print_flag);
void				rrr(t_list **tail_a, t_list **tail_b);

// operations_swap.c
void				sa(t_list **tail_a, int print_flag);
void				sb(t_list **tail_b, int print_flag);
void				ss(t_list **tail_a, t_list **tail_b);

#endif