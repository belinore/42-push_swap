/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate_fwd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:55:20 by belinore          #+#    #+#             */
/*   Updated: 2025/02/01 14:00:04 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//rotate a: shifts all elements of stack a up by one - first becomes last
void	ra(t_list **tail_a, int print_flag)
{
	if (*tail_a == NULL || *tail_a == (*tail_a)->next)
		return ;
	*tail_a = (*tail_a)->next;
	if (print_flag == 1)
		ft_putstr_fd("ra\n", 1);
}

//rotate b: shifts all elements of stack b up by one - first becomes last
void	rb(t_list **tail_b, int print_flag)
{
	if (*tail_b == NULL || *tail_b == (*tail_b)->next)
		return ;
	*tail_b = (*tail_b)->next;
	if (print_flag == 1)
		ft_putstr_fd("rb\n", 1);
}

//double rotate: ra and rb at the same time
void	rr(t_list **tail_a, t_list **tail_b)
{
	ra(tail_a, 0);
	rb(tail_b, 0);
	ft_putstr_fd("rr\n", 1);
}
