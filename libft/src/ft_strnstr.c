/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:19:48 by jaacosta          #+#    #+#             */
/*   Updated: 2024/10/09 15:43:10 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*b;
	const char	*l;
	size_t		lenrestant;

	if (!*little)
		return ((char *)big);
	while (len > 0 && *big)
	{
		b = big;
		l = little;
		lenrestant = len;
		while (*l == *b && lenrestant > 0 && *l)
		{
			b++;
			l++;
			lenrestant--;
		}
		if (!*l)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
