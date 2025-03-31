/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:53:50 by belinore          #+#    #+#             */
/*   Updated: 2025/02/04 18:20:48 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// compares 2 ints and returns the one which is higher value
int	higher_value(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

// prints a string to the indicated file descripter
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
}

// frees an array of strings, starting at the index of the last
void	free_array(char **str_array, int index)
{
	if (index <= -1)
		return ;
	while (index >= 0)
	{
		free(str_array[index]);
		index--;
	}
	free(str_array);
}
