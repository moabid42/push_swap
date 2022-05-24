# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 14:21:55 by moabid            #+#    #+#              #
#    Updated: 2022/05/24 14:09:21 by moabid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# MAKEFLAGS += --no-builtin-rules
# MAKEFLAGS += --no-builtin-variables

NAME		=	push_swap
FLAGS		=	-Wall -Wextra -g
CC			=	gcc
INCLUDES	= 	-I./include
LIBFT		= 	./libft/libft.a 
SRCS_DIR	=	./src/
SRCS_FILES	=	main.c utils.c parsing.c operations.c \
				init.c
SRCS		= 	$(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJ_DIR		=	./obj/
OBJS	 = $(OBJS_FILES:.c=.o)
OBJS_FILES		=	$(addprefix $(OBJ_DIR), $(SRCS_FILES))

$(OBJ_DIR)%.o : $(SRCS_DIR)%.c
	@$(CC) ${FLAGS} ${INCLUDES} -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) 
	@echo "\033[33m----Compiling ...----"
	@make -C ./libft --silent
	@$(CC) -o $(NAME) $(INCLUDES) $(OBJS) $(LIBFT)
	@echo "\033[32mPUSH_SWAP Compiled! ༺ (\033[31m♥\033[32m_\033[31m♥\033[32m)༻\n"

#$(CC) -o $(NAME) $(INCLUDES) $(OBJS) $(LINK_FLAGS) $(LIBFT) $(MINILIBX)
#$(CC) -o $(NAME) $(INCLUDES) $(OBJS) $(LIBFT)
clean:
	@echo "\033[33m     Cleaning the garbage ..."
	@make clean -C ./libft --silent
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)
	@echo "\033[32mEverything is fcleaned! ✓ (\033[31m>_<\033[32m)\n"

re: fclean all

.PHONY: all clean fclean re