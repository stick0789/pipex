/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:53:13 by jaacosta          #+#    #+#             */
/*   Updated: 2024/10/29 16:53:15 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ctrl_hexa(unsigned int nbr, char fs)
{
	int		size;
	char	*base;

	size = 0;
	if (fs == 'x' || fs == 'p')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		size += ctrl_hexa(nbr / 16, fs);
		if (size == -1)
			return (-1);
	}
	if ((ctrl_putchar(base[nbr % 16]) == -1))
		return (-1);
	size++;
	return (size);
}
