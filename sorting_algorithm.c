/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:55:49 by belinore          #+#    #+#             */
/*   Updated: 2025/03/31 12:11:15 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sorts a list of 2-3 elements in ascending order
void	sort_list_simple(t_list **tail)
{
	t_list	*max;

	max = get_max(tail);
	if (max == (*tail)->next)
		ra(tail, 1);
	else if (max == (*tail)->prev)
		rra(tail, 1);
	if ((*tail)->next->value > (*tail)->next->next->value)
		sa(tail, 1);
}

//sorts stack_a in ascending order, with stack_b as temporary storage
void	sort_list_long(t_list **stack_a, t_list **stack_b)
{
	t_rot	*rotation_ops;

	rotation_ops = malloc(sizeof(t_rot));
	if (rotation_ops == NULL)
		error_clear_list(stack_a, stack_b, NULL, 0);
	while (list_size(*stack_b) < 2)
		pb(stack_a, stack_b);
	while (list_size(*stack_a) > 3)
		push_best_option(stack_a, stack_b, rotation_ops, 'a');
	sort_list_simple(stack_a);
	while (list_size(*stack_b) > 0)
		push_best_option(stack_a, stack_b, rotation_ops, 'b');
	set_index(stack_a, 'a');
	if (get_min(stack_a)->index < list_size(*stack_a) / 2)
	{
		while ((*stack_a)->next != get_min(stack_a))
			ra(stack_a, 1);
	}
	else
	{
		while ((*stack_a)->next != get_min(stack_a))
			rra(stack_a, 1);
	}
	free(rotation_ops);
}

//identifies and pushes lowest cost move
void	push_best_option(t_list **tail_a, t_list **tail_b, t_rot *ops,
		char src_stack)
{
	t_list	*node_to_push;
	t_list	*insertion_target;
	int		best_option;

	set_index(tail_a, 'a');
	set_index(tail_b, 'b');
	if (src_stack == 'a')
	{
		assign_cost(tail_a, tail_b, ops);
		node_to_push = get_node_to_push(tail_a);
		insertion_target = get_insertion_target(node_to_push, tail_b,
				src_stack);
	}
	else
	{
		node_to_push = (*tail_b)->next;
		insertion_target = get_insertion_target(node_to_push, tail_a,
				src_stack);
	}
	best_option = evaluate_options(node_to_push, insertion_target, ops, NULL);
	update_ops(ops, best_option);
	exec_rotations(tail_a, tail_b, ops);
	push(tail_a, tail_b, src_stack);
}

//returns node from src stack with the lowest nbr of moves to push to dst stack
t_list	*get_node_to_push(t_list **tail)
{
	t_list	*node_to_push;
	t_list	*current_node;
	int		started;

	node_to_push = *tail;
	current_node = (*tail)->next;
	started = 0;
	while (current_node != (*tail)->next || started == 0)
	{
		started = 1;
		if (current_node->cost < node_to_push->cost)
		{
			node_to_push = current_node;
		}
		if (node_to_push->cost == 0)
			break ;
		current_node = current_node->next;
	}
	return (node_to_push);
}

//returns node in dst_stack that src_node should be added before
t_list	*get_insertion_target(t_list *src_node, t_list **dst_stack,
		char src_name)
{
	t_list	*dst_node;

	if (src_name == 'a')
	{
		if (src_node->value < get_min(dst_stack)->value)
			return (get_max(dst_stack));
		dst_node = get_max(dst_stack);
		while (src_node->value < dst_node->value)
			dst_node = dst_node->next;
		return (dst_node);
	}
	else
	{
		if (src_node->value > get_max(dst_stack)->value)
			return (get_min(dst_stack));
		dst_node = get_min(dst_stack);
		while (src_node->value > dst_node->value)
			dst_node = dst_node->next;
		return (dst_node);
	}
}
