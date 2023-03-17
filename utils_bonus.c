/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 10:13:28 by nel-mous          #+#    #+#             */
/*   Updated: 2023/03/16 15:59:22 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	if (arr)
	{
		while (arr[j] != 0)
			free(arr[j++]);
		free(arr[j]);
		free(arr);
	}
	free_stack(a);
	free_stack(b);
}
