/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_unsignedint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:55:11 by jaacosta          #+#    #+#             */
/*   Updated: 2024/10/22 18:13:57 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

unsigned int	ctrl_uint(unsigned int n)
{
	unsigned int	size;

	size = 0;
	if (n > 9)
	{
		size = ctrl_uint(n / 10);
		n = n % 10;
	}
	if (n <= 9)
	{
		if (ctrl_putchar(n + '0') != -1)
			size++;
	}
	return (size);
}
