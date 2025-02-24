/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_basics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:13:04 by jaacosta          #+#    #+#             */
/*   Updated: 2024/10/22 17:50:41 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ctrl_putchar(char c)
{
	if (write(1, &c, 1) != -1)
		return (1);
	else
		return (-1);
}

int	ctrl_putstr(char *s)
{
	if (!s)
		return (ctrl_putstr("(null)"));
	if (write(1, s, ft_strlen(s)) != -1)
		return ((int)ft_strlen(s));
	else
		return (-1);
}

int	ctrl_putnbr(int n)
{
	int	size;

	size = 0;
	if (n == 0)
	{
		size += ctrl_putchar('0');
	}
	if (n == -2147483648)
	{
		size += ctrl_putstr("-2147483648");
		return (size);
	}
	if (n < 0)
	{
		size += ctrl_putchar('-');
		n = -n;
	}
	if (n > 0)
		size += ctrl_uint((unsigned int)n);
	return (size);
}
