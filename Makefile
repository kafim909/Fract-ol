# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/07 16:33:45 by mtournay          #+#    #+#              #
#    Updated: 2021/09/09 17:10:15 by mtournay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIRSRC		= ./srcs/

LIBFT		= ./libft/

NAMELFT		= ./libft/libft.a

DYLIB		= ./libmlx.dylib

SRC			= help_screen.c hooks.c init.c julia_set.c main.c mandel_set.c tools.c matrixes.c

SRCS		= $(addprefix ${DIRSRC}, ${SRC})

OBJS		= ${SRCS:.c=.o}

NAME		= fractol

CC			= gcc
RM			= rm -f
RN			= ranlib

CFLAGS		= -Wall -Wextra -Werror -O3

MLX			= -lmlx -framework OpenGL -framework AppKit -lm -O3 -I.

.c.o:
			${CC} ${CFLAGS} -c -I${LIBFT} $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			@make -s -C ./libft
			@make -s -C ./mlx
			mv ./mlx/libmlx.dylib .
			${CC} ${CFLAGS} ${OBJS} ${NAMELFT} ${DYLIB} ${MLX} -o ${NAME}

all:		$(NAME)

clean:
			${RM} ${OBJS} ${DYLIB}

fclean:		clean
			${RM} $(NAME)
			@make fclean -s -C ./libft
			@make clean -s -C ./mlx

re:			fclean all

.PHONY:		all clean fclean re