/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:11:28 by jaacosta          #+#    #+#             */
/*   Updated: 2025/03/12 17:13:38 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define MAX_FD 1024

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

//int		ft_strlen(const char *s);
//char	*ft_strchr(const char *s, int c);
//char	*ft_strdup(const char *s);
//char	*ft_substr(char const *s, unsigned int start, int len);
//char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);

#endif
