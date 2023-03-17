/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:23:41 by nel-mous          #+#    #+#             */
/*   Updated: 2023/03/17 09:05:37 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_putstr(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		write(1, &str[i], 1);
// 		i++;
// 	}
// }

void	free_stack(t_stack **a)
{
	t_stack	*temp;

	while (*a)
	{
		temp = (*a)->next;
		(*a)->content = 0;
		free(*a);
		*a = temp;
	}
}

void	free_all(char *s, char **arr, t_stack **a, t_stack **b)
{
	int	j;

	j = 0;
	if (s)
		free(s);
	if (arr != NULL)
	{
		while (arr[j] != 0)
			free(arr[j++]);
		free(arr[j]);
		free(arr);
	}
	free_stack(a);
	free_stack(b);
}

void	oops(char *s, char **arr)
{
	int	j;

	j = 0;
	write(2, "Error\n", 6);
	if (s)
		free(s);
	if (arr != NULL)
	{
		while (arr[j] != 0)
			free(arr[j++]);
		free(arr[j]);
		free(arr);
	}
	exit(0);
}

int	if_sorted(t_stack *a)
{
	while (a)
	{
		while (a->next)
		{
			if (a->content > a->next->content)
				return (0);
			a = a->next;
		}
		a = a->next;
	}
	return (1);
}
