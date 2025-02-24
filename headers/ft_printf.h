/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:43:01 by jaacosta          #+#    #+#             */
/*   Updated: 2024/10/22 20:34:28 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

unsigned int	ctrl_uint(unsigned int n);
int				ft_printf(const char *format, ...);
int				ctrl_putchar(char c);
int				ctrl_putstr(char *s);
int				ctrl_putnbr(int n);
int				ctrl_ptr(void *ptr);
int				ctrl_hexa(unsigned int nbr, char fs);

#endif
