/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:56:02 by belinore          #+#    #+#             */
/*   Updated: 2025/02/04 16:54:19 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checks if stack is sorted in ascending order (used by stack a)
int	is_sorted(t_list *tail)
{
	t_list	*current_node;

	current_node = tail->next;
	while (current_node != tail)
	{
		if (current_node->value > current_node->next->value)
			return (0);
		current_node = current_node->next;
	}
	return (1);
}

// helper of exec_rotations to add rr and rrr ops
static void	adjust_for_double_rotates(t_rot *ops)
{
	ops->rr = 0;
	ops->rrr = 0;
	while (ops->ra > 0 && ops->rb > 0)
	{
		ops->rr++;
		ops->ra--;
		ops->rb--;
	}
	while (ops->rra > 0 && ops->rrb > 0)
	{
		ops->rrr++;
		ops->rra--;
		ops->rrb--;
	}
}

// executes rotations as per instruction passed in "ops"
void	exec_rotations(t_list **tail_a, t_list **tail_b, t_rot *ops)
{
	adjust_for_double_rotates(ops);
	while (ops->rr-- > 0)
		rr(tail_a, tail_b);
	while (ops->ra-- > 0)
		ra(tail_a, 1);
	while (ops->rb-- > 0)
		rb(tail_b, 1);
	while (ops->rrr-- > 0)
		rrr(tail_a, tail_b);
	while (ops->rra-- > 0)
		rra(tail_a, 1);
	while (ops->rrb-- > 0)
		rrb(tail_b, 1);
}

// returns node with the lowest value
t_list	*get_min(t_list **tail)
{
	t_list	*current_node;
	t_list	*min;

	min = *tail;
	current_node = (*tail)->next;
	while (current_node != *tail)
	{
		if (current_node->value < min->value)
			min = current_node;
		current_node = current_node->next;
	}
	return (min);
}

// returns node with the highest value
t_list	*get_max(t_list **tail)
{
	t_list	*current_node;
	t_list	*max;

	max = *tail;
	current_node = (*tail)->next;
	while (current_node != *tail)
	{
		if (current_node->value > max->value)
			max = current_node;
		current_node = current_node->next;
	}
	return (max);
}
