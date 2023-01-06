# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/10 13:46:37 by aelsiddi          #+#    #+#              #
#    Updated: 2023/01/06 10:03:20 by aelsiddi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	= 	vail.c\
			init.c\
			error.c\
			print.c\
			movment.c\
			path.c\
			so_long.c\
			ft_itoa.c\
			misc.c\
			ft_strjoin.c

OBJS			= $(SRCS:.c=.o)
CC				= gcc
RM				= rm -f
CFLAGS			= -g -Wall -Wextra -Werror -I.

NAME			= so_long

MLX				= minilibx/libmlx.a

all:			$(NAME)

$(MLX)			: 
					make -C minilibx

$(NAME):		$(OBJS) $(MLX)
				cc $(MLX) -framework OpenGL -framework AppKit  $(OBJS) -o $(NAME)

clean:
				$(RM) $(OBJS) 
				make -C minilibx clean

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
