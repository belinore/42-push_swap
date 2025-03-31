/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:55:04 by belinore          #+#    #+#             */
/*   Updated: 2025/02/01 13:22:48 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// creates a new node of a circular doubly linked list
t_list	*create_new_node(int value)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	new_node->next = new_node;
	new_node->prev = new_node;
	return (new_node);
}

// creates new node and adds to front of list (circular, doubly linked)
t_list	*add_to_front(t_list *tail, t_list *new_node)
{
	t_list	*current_first;

	if (tail == NULL)
		return (new_node);
	current_first = tail->next;
	new_node->prev = tail;
	new_node->next = current_first;
	current_first->prev = new_node;
	tail->next = new_node;
	return (tail);
}

// returns size of circular list
int	list_size(t_list *tail)
{
	t_list	*current_node;
	int		count;

	if (tail == NULL)
		return (0);
	current_node = tail->next;
	count = 1;
	while (current_node != tail)
	{
		count++;
		current_node = current_node->next;
	}
	return (count);
}

// free list
void	clear_list(t_list **tail)
{
	int		size;
	t_list	*current_node;
	t_list	*next_node;

	if (tail == NULL)
		return ;
	size = list_size(*tail);
	current_node = *tail;
	while (size > 0)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
		size--;
	}
	*tail = NULL;
}
