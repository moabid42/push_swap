# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 14:21:55 by moabid            #+#    #+#              #
#    Updated: 2022/05/21 20:59:58 by moabid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
FLAGS		=	-Wall -Wextra -g
CC			=	gcc
INCLUDES	= 	-I./include
LIBFT		= 	./libft/libft.a 
SRCS		=	./src/main.c ./src/utils.c ./src/parsing.c ./src/operations.c \
				./src/init.c

OBJS	=	${SRCS:.c=.o}

%.o : %.c
		gcc -g ${FLAGS} ${INCLUDES} -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
		@echo "\033[33m----Compiling ...----"
		@make -C ./libft
		@$(CC) -o $(NAME) $(INCLUDES) $(OBJS) $(LIBFT) $(LINK_FLAGS) $(MINILIBX)
		@echo "\033[32mPUSH_SWAP Compiled! ༺ (\033[31m♥\033[32m_\033[31m♥\033[32m)༻\n"

#$(CC) -o $(NAME) $(INCLUDES) $(OBJS) $(LINK_FLAGS) $(LIBFT) $(MINILIBX)
#$(CC) -o $(NAME) $(INCLUDES) $(OBJS) $(LIBFT)
clean:
	@echo "\033[33m     Cleaning the garbage ..."
	@make clean -C ./libft
	@rm -f $(OBJS)
	@echo "\033[32mEverything is cleaned!  ✓ (\033[31m>_<\033[32m)\033[33m\n"

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)
	@echo "\033[32mEverything is fcleaned! ✓ (\033[31m>_<\033[32m)\n"

re: fclean all

.PHONY: all clean fclean re