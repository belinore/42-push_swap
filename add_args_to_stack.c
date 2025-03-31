/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_args_to_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:53:40 by belinore          #+#    #+#             */
/*   Updated: 2025/02/04 18:37:40 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// clears both stacks (when existing) and prints "Error" to stderr
void	error_clear_list(t_list **tail_a, t_list **tail_b, char **str_array,
			int mem2free)
{
	clear_list(tail_a);
	clear_list(tail_b);
	if (str_array != NULL)
		free_array(str_array, mem2free - 1);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

// converts numeric ascii to long int and clears list in case of invalid format
long	atol_push_swap(const char *str, t_list **list, char **str_array,
			int mem2free)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	if (str[i] != '\0')
		error_clear_list(list, NULL, str_array, mem2free);
	return (sign * num);
}

// initial check that args are within the strlen of an int
static int	is_valid_str_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i > 11)
		return (-1);
	return (1);
}

// duplicates check comparing each new arg (num) against values already in list
static int	is_duplicate(int num, t_list *tail)
{
	t_list	*current_node;

	if (tail == NULL)
		return (0);
	if (num == tail->value)
		return (1);
	current_node = tail->next;
	while (current_node != tail)
	{
		if (num == current_node->value)
			return (1);
		current_node = current_node->next;
	}
	return (0);
}

// converts each argument to an int and adds to stack, with error checking
t_list	*add_args_to_stack(char **array, int size, int mem2free)
{
	t_list	*tail;
	t_list	*new_node;
	long	num;

	if (mem2free == 1)
		mem2free = size;
	tail = NULL;
	if (array == NULL || *array == NULL)
		exit(1);
	while (size > 0 && is_valid_str_arg(array[size - 1]))
	{
		num = atol_push_swap(array[size - 1], &tail, array, mem2free);
		if (num > INT_MAX || num < INT_MIN)
			error_clear_list(&tail, NULL, array, mem2free);
		if (is_duplicate((int)num, tail))
			error_clear_list(&tail, NULL, array, mem2free);
		new_node = create_new_node(num);
		if (new_node == NULL)
			error_clear_list(&tail, NULL, array, mem2free);
		tail = add_to_front(tail, new_node);
		size--;
	}
	if (size > 0)
		error_clear_list(&tail, NULL, array, mem2free);
	return (tail);
}
