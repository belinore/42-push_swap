/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:55:38 by belinore          #+#    #+#             */
/*   Updated: 2025/02/01 13:23:20 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//swap a: swaps the first 2 elements at the top of the stack a
void	sa(t_list **tail_a, int print_flag)
{
	t_list	*elem1;
	t_list	*elem2;

	if (*tail_a == NULL || *tail_a == (*tail_a)->next)
		return ;
	elem1 = (*tail_a)->next;
	elem2 = elem1->next;
	elem2->next->prev = elem1;
	elem1->next = elem2->next;
	elem1->prev = elem2;
	elem2->next = elem1;
	elem2->prev = *tail_a;
	(*tail_a)->next = elem2;
	if (print_flag == 1)
		ft_putstr_fd("sa\n", 1);
}

//swap b: swaps the first 2 elements at the top of the stack b
void	sb(t_list **tail_b, int print_flag)
{
	t_list	*elem1;
	t_list	*elem2;

	if (*tail_b == NULL || *tail_b == (*tail_b)->next)
		return ;
	elem1 = (*tail_b)->next;
	elem2 = elem1->next;
	elem2->next->prev = elem1;
	elem1->next = elem2->next;
	elem1->prev = elem2;
	elem2->next = elem1;
	elem2->prev = *tail_b;
	(*tail_b)->next = elem2;
	if (print_flag == 1)
		ft_putstr_fd("sb\n", 1);
}

//double swap: sa and sb at the same time
void	ss(t_list **tail_a, t_list **tail_b)
{
	sa(tail_a, 0);
	sb(tail_b, 0);
	ft_putstr_fd("ss\n", 1);
}
