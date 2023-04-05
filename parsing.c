/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:27:23 by nel-mous          #+#    #+#             */
/*   Updated: 2023/03/18 11:50:04 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicate(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (ft_atoi(arr[i]) == ft_atoi(arr[j]))
				oops(NULL, arr);
			else
				j++;
		}
		i++;
	}
}

void	check_space(char *av, char *s)
{
	int	j;
	int	len;

	len = 0;
	j = 0;
	while (av[j])
	{
		if (av[j] != ' ')
			len++;
		j++;
	}
	if (len == 0)
		oops(s, NULL);
}

void	check_args(char **arr)
{
	int	j;
	int	k;

	j = 0;
	while (arr[j])
	{
		k = 0;
		if ((arr[j][k] == '+' || arr[j][k] == '-') && arr[j][k + 1] != '\0')
			k++;
		while (arr[j][k])
		{
			if (!ft_isdigit(arr[j][k])
			|| ft_atoi(arr[j]) > 2147483647 || ft_atoi(arr[j]) < -2147483648)
				oops(NULL, arr);
			k++;
		}
		j++;
	}
}
