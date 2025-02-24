/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:35:05 by jaacosta          #+#    #+#             */
/*   Updated: 2024/10/05 19:52:05 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

long	ft_atoi(const char *nptr)
{
	long	y;
	long	z;

	y = 1;
	z = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == 45)
		y *= -1;
	if (*nptr == 43 || *nptr == 45)
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		z = (*nptr - '0') + (z * 10);
		nptr++;
	}
	return (z * y);
}
