/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:29:20 by nel-mous          #+#    #+#             */
/*   Updated: 2023/03/16 15:53:24 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *s)
{
	char		*str;
	int			i;
	long long	x;
	int			sign;

	str = (char *)s;
	i = 0;
	x = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9')
		&& ((x * sign) >= -2147483648 && (x * sign) <= 2147483647))
	{
		x = x * 10 + str[i] - '0';
		i++;
	}
	return (x * sign);
}
