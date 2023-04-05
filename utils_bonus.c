/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 10:13:28 by nel-mous          #+#    #+#             */
/*   Updated: 2023/03/19 08:43:35 by nel-mous         ###   ########.fr       */
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

void	free_stack(t_stack **a)
{
	t_stack	*temp;

	while (*a)
	{
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
}

void	free_arr(char **arr)
{
	int	j;

	j = 0;
	if (arr != NULL)
	{
		while (arr[j] != 0)
			free(arr[j++]);
		free(arr);
	}
}

void	oops(char *s, char **arr)
{
	write(2, "Error\n", 6);
	free(s);
	free_arr(arr);
	exit(0);
}
