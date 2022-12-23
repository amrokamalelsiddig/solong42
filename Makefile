# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelsiddi <aelsiddi@student.42.ae>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/10 13:46:37 by aelsiddi          #+#    #+#              #
#    Updated: 2022/12/23 18:34:47 by aelsiddi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	= 	vail.c\
			init.c\
			error.c\
			print.c\
			color.c\
			movment.c\
			path.c\
			so_long.c\
			ft_itoa.c\
			desposlable.c\
			ft_strjoin.c

RM				= rm -f
CFLAGS			= -g -Wall -Wextra -Werror.

NAME			= so_long

ifeq ($(shell uname -s), Darwin)
	CFLAGS += -Imlx
	MLX = -Lminilibx_macos -lmlx -framework OpenGl -framework APPKit
#MLX_LIB = minilibx_macos
else ifeq ($(shell uname -s), Linux)
	CFLAGS += -Imlx
	MLX =  -Imlx_Linux -lmlx -L/usr/lib -Imlx_linux -lmlx -lXext -lX11  -o
# 	MLX_LIB = minilibx-linux
endif

# SUBDIRS = $(MLX_LIB)

CC = gcc

OBJS = $(SRC:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFALGS) $(SRCS) $(MLX) -Imlx_linux -lXext -lX11  -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: clean fclean all re
