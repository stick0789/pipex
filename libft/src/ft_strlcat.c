/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:35:05 by jaacosta          #+#    #+#             */
/*   Updated: 2024/10/05 19:48:11 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	lendest;
	size_t	lensrc;

	i = 0;
	lendest = 0;
	lensrc = 0;
	while (dest[lendest])
		lendest++;
	while (src[lensrc])
		lensrc++;
	if (size <= lendest)
		return (size + lensrc);
	else
	{
		while (i < size - lendest -1 && src[i])
		{
			dest[lendest + i] = src[i];
			i++;
		}
		dest[lendest + i] = '\0';
		return (lendest + lensrc);
	}
}
