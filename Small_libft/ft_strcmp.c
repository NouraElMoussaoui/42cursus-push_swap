/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:27:23 by nel-mous          #+#    #+#             */
/*   Updated: 2023/03/18 12:03:58 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *S1, const char *S2)
{
	size_t	i;

	i = 0;
	while ((S1[i] || S2[i]))
	{
		if (S1[i] != S2[i])
			return ((unsigned char)S1[i] - (unsigned char)S2[i]);
		else
			i++;
	}
	return (0);
}
