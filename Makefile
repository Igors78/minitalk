# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/19 08:09:21 by ioleinik          #+#    #+#              #
#    Updated: 2021/07/11 19:49:43 by ioleinik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g

RM			= rm -f

NAME		= server
NAME1		= client

LIB_PATH	= ./libft
INCL_PATH	= /includes

LIBRARY		= libft.a

MAKE		= make

SRC			= server.c error.c
SRC1		= client.c terminate.c error.c

OBJ			= ${SRC:.c=.o}
OBJ1		= ${SRC1:.c=.o}

all:		$(LIBRARY) $(NAME) $(NAME1)


$(LIBRARY):
			$(MAKE) -C $(LIB_PATH)

$(NAME):	$(OBJ)
			$(CC) -I $(INCL_PATH) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LIB_PATH) -lft
			
$(NAME1):	$(OBJ1)
			$(CC) -I $(INCL_PATH) $(CFLAGS) -o $(NAME1) $(OBJ1) -L $(LIB_PATH) -lft

clean:		
			$(RM) $(OBJ) $(OBJ1)

fclean:		clean
			$(RM) $(NAME) $(NAME1)
			$(MAKE) -C $(LIB_PATH) fclean

re:			fclean all

.PHONY: all clean fclean re