/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:35:05 by jaacosta          #+#    #+#             */
/*   Updated: 2024/10/09 20:08:29 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_len(long int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_putn_save(long int n, char *s, int *i)
{
	if (n > 9)
	{
		ft_putn_save(n / 10, s, i);
		ft_putn_save(n % 10, s, i);
	}
	else
		s[(*i)++] = n + '0';
}

char	*ft_itoa(int n)
{
	char		*s;
	int			i;
	int			len;
	long int	nbr;

	nbr = (long int)n;
	len = ft_len(nbr);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	i = 0;
	if (nbr < 0)
	{
		s[i++] = '-';
		nbr *= -1;
	}
	ft_putn_save(nbr, s, &i);
	s[i] = '\0';
	return (s);
}
