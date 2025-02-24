# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 17:25:47 by jaacosta          #+#    #+#              #
#    Updated: 2025/02/24 17:25:50 by jaacosta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -g
AR	= ar -rcs
RM	= rm -rf

SRCS 	=  
	  
SRC_PATH = ./src/
OBJ_PATH = ./tmp/
H_PATH	 = ./headers

HEADERS  = -I$(H_PATH)

DIRSRC	 = $(addprefix $(SRC_PATH), $(SRCS))
OBJS 	 = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

all	:	makelib makeminilib $(OBJ_PATH) $(NAME)

makelib	:	
		$(MAKE) -C libft 

$(OBJ_PATH):
		mkdir -p $(OBJ_PATH)
		echo "Directorio $(OBJ_PATH) creado."

$(NAME)	:	$(OBJS) 
		$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

$(OBJ_PATH)%.o	:	$(SRC_PATH)%.c Makefile libft/libft.a 
			mkdir -p $(dir $@)
			$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@


clean	:
		$(RM) $(OBJ_PATH)
		$(MAKE) -C libft clean

fclean	:
		$(RM) $(NAME) $(OBJ_PATH)
		$(MAKE) -C libft fclean

re	:
		make fclean 
		make all 
		
.PHONY	:	makelib all clean fclean re
