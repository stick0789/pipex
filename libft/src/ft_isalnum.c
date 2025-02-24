/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:35:05 by jaacosta          #+#    #+#             */
/*   Updated: 2024/10/05 19:57:03 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_isdigi(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

static int	ft_isupper(int c)
{
	if (c > 64 && c < 91)
		return (1);
	else
		return (0);
}

static int	ft_islower(int c)
{
	if (c > 96 && c < 123)
		return (1);
	else
		return (0);
}

int	ft_isalnum(int c)
{
	if (ft_isdigi(c) || ft_isupper(c) || ft_islower(c))
		return (1);
	else
		return (0);
}
