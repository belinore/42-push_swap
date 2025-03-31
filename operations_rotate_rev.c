/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate_rev.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:55:24 by belinore          #+#    #+#             */
/*   Updated: 2025/02/01 13:58:56 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//reverse rotate a: shifts all elements down by one - last becomes first
void	rra(t_list **tail_a, int print_flag)
{
	if (*tail_a == NULL || *tail_a == (*tail_a)->next)
		return ;
	*tail_a = (*tail_a)->prev;
	if (print_flag == 1)
		ft_putstr_fd("rra\n", 1);
}

//reverse rotate b: shifts all elements down by one - last becomes first
void	rrb(t_list **tail_b, int print_flag)
{
	if (*tail_b == NULL || *tail_b == (*tail_b)->next)
		return ;
	*tail_b = (*tail_b)->prev;
	if (print_flag == 1)
		ft_putstr_fd("rrb\n", 1);
}

//double reverse rotate: rra and rrb at the same time
void	rrr(t_list **tail_a, t_list **tail_b)
{
	rra(tail_a, 0);
	rrb(tail_b, 0);
	ft_putstr_fd("rrr\n", 1);
}
