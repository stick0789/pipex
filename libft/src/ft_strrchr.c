/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:35:10 by jaacosta          #+#    #+#             */
/*   Updated: 2024/10/08 17:40:39 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*last_occurrence;
	unsigned char	uc;

	last_occurrence = NULL;
	uc = (unsigned char)c;
	while (*s)
	{
		if (*s == uc)
			last_occurrence = s;
		s++;
	}
	if (uc == '\0')
		return ((char *)s);
	return ((char *)last_occurrence);
}
