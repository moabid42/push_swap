# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 14:21:55 by moabid            #+#    #+#              #
#    Updated: 2022/05/25 00:57:02 by moabid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# MAKEFLAGS += --no-builtin-rules
# MAKEFLAGS += --no-builtin-variables

NAME		=	push_swap
CHECKER		=	checker

FLAGS		=	-Wall -Wextra -Werror -g
CC			=	gcc
INCLUDES	= 	-I./include
LIBFT		= 	./libft/libft.a

# CHECKER_DIR		=	./src/checker/
# CHECKER_FILES	=	checker.c
# CHECKERS		= 	$(addprefix $(CHECKER_DIR), $(CHECKER_FILES))

SRCS_DIR	=	./src/
SRCS_FILES	=	main.c utils.c parsing.c operations.c init.c
SRCS		= 	$(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJ_DIR		=	./obj/
OBJS1	 	= $(OBJS_FILES:.c=.o)
OBJS_FILES	=	$(addprefix $(OBJ_DIR), $(SRCS_FILES))

# OBJS2		= $(OBJS_CH_FILES:.c=.o)
# OBJS_CH_FILES	=	$(addprefix $(OBJ_DIR), $(CHECKER_FILES))

$(OBJ_DIR)%.o : $(SRCS_DIR)%.c
	@$(CC) ${FLAGS} ${INCLUDES} -c $< -o $@

# $(OBJ_DIR)%.o : $(CHECKER_DIR)%.c
# 	@$(CC) ${FLAGS} ${INCLUDES} -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS1) 
	@echo "\033[33m----Compiling PUSH_SWAP...----"
	@make -C ./libft --silent
	@$(CC) -o $(NAME) $(INCLUDES) $(OBJS1) $(LIBFT)
	@echo "\033[32mPUSH_SWAP Compiled! ༺ (\033[31m♥\033[32m_\033[31m♥\033[32m)༻\n"

# $(CHECKER): $(OBJS2)
# 	@echo "\033[33m----Compiling CHECKER...----"
# 	@make -C ./libft --silent
# 	@$(CC) -o $(NAME) $(INCLUDES) $(OBJS2) $(LIBFT)
# 	@echo "\033[32mCHECKER Compiled! ༺ (\033[31m♥\033[32m_\033[31m♥\033[32m)༻\n"

	
	
clean:
	@echo "\033[33m     Cleaning the garbage ..."
	@make clean -C ./libft --silent
	@rm -f $(OBJS1)
# @rm -f $(OBJS2)

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)
	@echo "\033[32mEverything is fcleaned! ✓ (\033[31m>_<\033[32m)\n"

re: fclean all

.PHONY: all clean fclean re