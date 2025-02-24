/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_voidptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:15:21 by jaacosta          #+#    #+#             */
/*   Updated: 2024/10/22 18:21:40 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ctrl_hexaptr(unsigned long nbr)
{
	int		size;
	char	*base;

	size = 0;
	base = "0123456789abcdef";
	if (nbr >= 16)
	{
		size += ctrl_hexaptr(nbr / 16);
		if (size == -1)
			return (-1);
	}
	if ((ctrl_putchar(base[nbr % 16]) == -1))
		return (-1);
	size++;
	return (size);
}

int	ctrl_ptr(void *ptr)
{
	int				size;
	unsigned long	ptr_hexa;

	ptr_hexa = (unsigned long )ptr;
	size = 0;
	if (ptr == NULL)
		size += ctrl_putstr("(nil)");
	else
	{
		size += ctrl_putstr("0x");
		size += ctrl_hexaptr(ptr_hexa);
	}
	return (size);
}
