/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:55:16 by belinore          #+#    #+#             */
/*   Updated: 2025/02/01 13:59:53 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//executes pa or pb depending on stack 'a' or 'b' indicated in src_stack
void	push(t_list **tail_a, t_list **tail_b, char src_stack)
{
	if (src_stack == 'a')
		pb(tail_a, tail_b);
	else
		pa(tail_a, tail_b);
}

//push to a: takes the first element on top of stack b and puts it on stack a
void	pa(t_list **tail_a, t_list **tail_b)
{
	t_list	*node_to_push;
	t_list	*new_head_b;

	if (*tail_b == NULL)
		return ;
	node_to_push = (*tail_b)->next;
	if (node_to_push == *tail_b)
		*tail_b = NULL;
	else
	{
		new_head_b = node_to_push->next;
		new_head_b->prev = *tail_b;
		(*tail_b)->next = new_head_b;
	}
	node_to_push->next = node_to_push;
	node_to_push->prev = node_to_push;
	*tail_a = add_to_front(*tail_a, node_to_push);
	ft_putstr_fd("pa\n", 1);
}

//push to b: takes the first element on top of stack a and puts it on stack b
void	pb(t_list **tail_a, t_list **tail_b)
{
	t_list	*node_to_push;
	t_list	*new_head_a;

	if (*tail_a == NULL)
		return ;
	node_to_push = (*tail_a)->next;
	if (node_to_push == *tail_a)
		*tail_a = NULL;
	else
	{
		new_head_a = node_to_push->next;
		new_head_a->prev = *tail_a;
		(*tail_a)->next = new_head_a;
	}
	node_to_push->next = node_to_push;
	node_to_push->prev = node_to_push;
	*tail_b = add_to_front(*tail_b, node_to_push);
	ft_putstr_fd("pb\n", 1);
}
