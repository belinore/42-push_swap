/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:53:18 by belinore          #+#    #+#             */
/*   Updated: 2025/02/04 18:16:45 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sorting driver
void	sort_list_ascending(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	else if (list_size(*stack_a) <= 3)
		sort_list_simple(stack_a);
	else
		sort_list_long(stack_a, stack_b);
}

// main, allows nbr list to be received via multiple args or single string
int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**string_array;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
	{
		string_array = ft_split(argv[1]);
		if (string_array == NULL)
			return (1);
		stack_a = add_args_to_stack(string_array, count_words(argv[1]), 1);
		free_array(string_array, count_words(argv[1]) - 1);
	}
	else
		stack_a = add_args_to_stack(&argv[1], argc - 1, 0);
	stack_b = NULL;
	sort_list_ascending(&stack_a, &stack_b);
	clear_list(&stack_a);
	return (0);
}
