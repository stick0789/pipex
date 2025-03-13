# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaacosta <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 18:02:27 by jaacosta          #+#    #+#              #
#    Updated: 2024/11/06 18:46:39 by jaacosta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -rf

SRCS = ft_strlen.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	   ft_isprint.c ft_tolower.c ft_toupper.c ft_strncmp.c ft_strchr.c \
	   ft_strdup.c ft_strrchr.c ft_strnstr.c ft_memset.c ft_bzero.c \
	   ft_memchr.c ft_memcpy.c ft_memcmp.c ft_memmove.c ft_strlcpy.c \
	   ft_atoi.c ft_calloc.c ft_strlcat.c ft_substr.c ft_strjoin.c \
	   ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	   control_basics.c control_hexa.c control_unsignedint.c \
	   control_voidptr.c ft_printf.c \
	   get_next_line.c 
#get_next_line_utils_bonus.c get_next_line_utils.c  get_next_line_bonus.c 
	 
SRC_PATH = ./src/
OBJ_PATH = ./tmp/
H_PATH	 = ../headers

HEADERS  = -I$(H_PATH)

DIRSRC	 = $(addprefix $(SRC_PATH), $(SRCS))
OBJS 	 = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

all:		$(OBJ_PATH) $(NAME)

$(OBJ_PATH):
		mkdir -p $(OBJ_PATH)

$(NAME):	$(OBJS)
		$(AR) $(NAME) $(OBJS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c Makefile $(H_PATH)
		$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
		$(RM) $(OBJ_PATH)

fclean:		
		$(RM) $(NAME) $(OBJ_PATH)

re:
		$(RM) $(NAME) $(OBJS)
		make all --silent

.PHONY: all, clean, fclean, re

