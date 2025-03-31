/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_calculation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:55:55 by belinore          #+#    #+#             */
/*   Updated: 2025/02/04 18:27:26 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//assigns for every a node the number of moves needed to push to b
void	assign_cost(t_list **tail_a, t_list **tail_b, t_rot *rotations)
{
	t_list	*a_node;
	t_list	*b_node;
	int		*cost;
	int		started;

	cost = malloc(sizeof(int));
	if (cost == NULL)
		error_clear_list(tail_a, tail_b, NULL, 0);
	a_node = (*tail_a)->next;
	(*tail_a)->cost = 0;
	started = 0;
	while (a_node != (*tail_a)->next || started == 0)
	{
		started = 1;
		b_node = get_insertion_target(a_node, tail_b,
				a_node->stack);
		evaluate_options(a_node, b_node, rotations, cost);
		a_node->cost = *cost;
		a_node = a_node->next;
	}
	free(cost);
}

//returns option # to evaluate_options + updates cost ptr for assign_cost
static int	best_option(t_rot *operations, int *moves_needed)
{
	int	options[4];
	int	i;
	int	lowest_cost;

	i = 0;
	options[0] = higher_value(operations->ra, operations->rb);
	options[1] = higher_value(operations->rra, operations->rrb);
	options[2] = operations->ra + operations->rrb;
	options[3] = operations->rra + operations->rb;
	lowest_cost = i;
	while (i < 4)
	{
		if (options[i] < options[lowest_cost])
		{
			lowest_cost = i;
		}
		i++;
	}
	if (moves_needed != NULL)
		*moves_needed = options[lowest_cost];
	return (lowest_cost);
}

//calculates moves for each rotation scenario and returns lowest-moves option
int	evaluate_options(t_list *src_node, t_list *dst_node, t_rot *ops, int *cost)
{
	if (src_node->stack == 'a')
	{
		ops->ra = src_node->index;
		ops->rra = list_size(src_node) - src_node->index;
		if (src_node->index == 0)
			ops->rra = 0;
		ops->rb = dst_node->index;
		ops->rrb = list_size(dst_node) - dst_node->index;
		if (dst_node->index == 0)
			ops->rrb = 0;
	}
	else
	{
		ops->rb = src_node->index;
		ops->rrb = list_size(src_node) - src_node->index;
		if (src_node->index == 0)
			ops->rrb = 0;
		ops->ra = dst_node->index;
		ops->rra = list_size(dst_node) - dst_node->index;
		if (dst_node->index == 0)
			ops->rra = 0;
	}
	return (best_option(ops, cost));
}

//sets the non-relevant rotations to 0, according to cheapest option code
void	update_ops(t_rot *rotate_ops, int lowest_cost_option)
{
	if (lowest_cost_option == 0)
	{
		rotate_ops->rra = 0;
		rotate_ops->rrb = 0;
	}
	else if (lowest_cost_option == 1)
	{
		rotate_ops->ra = 0;
		rotate_ops->rb = 0;
	}
	else if (lowest_cost_option == 2)
	{
		rotate_ops->rb = 0;
		rotate_ops->rra = 0;
	}
	else
	{
		rotate_ops->ra = 0;
		rotate_ops->rrb = 0;
	}
}

// sets index of list starting with 0 at list head ((*tail)->next)
void	set_index(t_list **tail, char stack)
{
	t_list	*current_node;
	int		i;
	int		flag;

	if (*tail == NULL)
		return ;
	current_node = (*tail)->next;
	flag = 0;
	i = 0;
	while (current_node != (*tail)->next || flag == 0)
	{
		flag = 1;
		current_node->index = i;
		current_node->cost = 0;
		current_node->stack = stack;
		current_node = current_node->next;
		i++;
	}
}
