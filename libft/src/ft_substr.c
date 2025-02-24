/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:35:10 by jaacosta          #+#    #+#             */
/*   Updated: 2024/10/09 19:11:17 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	if (i <= start)
		len = 0;
	else if ((len + start) >= i)
		len = i - start;
	i = 0;
	substr = (char *)malloc(sizeof(char) * (len +1));
	if (!substr)
		return (NULL);
	while (i < len)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	char * s = ft_substr("tripouille", 0, 42000);
	if (argc != 4)
	   return (0);
	printf("ft_substr: %s \n", s);
	free(s);
	return (0);
}*/
