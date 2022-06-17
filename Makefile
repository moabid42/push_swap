# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 14:21:55 by moabid            #+#    #+#              #
#    Updated: 2022/06/17 20:46:52 by moabid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# MAKEFLAGS += --no-builtin-rules
# MAKEFLAGS += --no-builtin-variables

NAME		=	push_swap
CHECKER		=	checker

FLAGS		=	-Wall -Wextra -g
CC			=	gcc
INCLUDES	= 	-I./include
LIBFT		= 	./libft/libft.a

CHECKER_DIR		=	./src/
CHECKER_FILES	=	checker.c parsing.c \
					operations_p.c operations_r.c \
					operations_rr.c operations_s.c \
					presort.c shunking.c solve.c  \
					sorting_utils.c unshunking.c \
					utils.c utils2.c utils3.c \
					stack_utils.c utils_free.c
CHECKERS		= 	$(addprefix $(CHECKER_DIR), $(CHECKER_FILES))

SRCS_DIR		=	./src/
SRCS_FILES		=	main.c parsing.c \
					operations_p.c operations_r.c \
					operations_rr.c operations_s.c \
					presort.c shunking.c solve.c  \
					sorting_utils.c unshunking.c \
					utils.c utils2.c utils3.c \
					stack_utils.c utils_free.c
SRCS			= 	$(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJ_DIR			=	./obj_mnd/
OBJ_DIR_2		=	./obj_bonus/
OBJS1	 		= 	$(OBJS_FILES:.c=.o)
OBJS_FILES		=	$(addprefix $(OBJ_DIR), $(SRCS_FILES))
OBJS2			= 	$(OBJS_CH_FILES:.c=.o)
OBJS_CH_FILES	=	$(addprefix $(OBJ_DIR_2), $(CHECKER_FILES))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR_2):
	@mkdir -p $(OBJ_DIR_2)


$(OBJ_DIR)%.o : $(SRCS_DIR)%.c
	@$(CC) ${FLAGS} ${INCLUDES} -c $< -o $@

$(OBJ_DIR_2)%.o : $(CHECKER_DIR)%.c
	@$(CC) ${FLAGS} ${INCLUDES} -c $< -o $@


$(NAME): $(OBJ_DIR) $(OBJS1) 
	@echo "\033[33m----Compiling PUSH_SWAP...----"
	@make -C ./libft --silent
	@$(CC) -o $(NAME) $(INCLUDES) $(OBJS1) $(LIBFT)
	@echo "\033[32mPUSH_SWAP Compiled! ༺ (\033[31m♥\033[32m_\033[31m♥\033[32m)༻\n\033[0m"

$(CHECKER): $(OBJ_DIR_2) $(OBJS2)
	@echo "\033[33m----Compiling CHECKER...----"
	@make -C ./libft --silent
	@$(CC) -o $(CHECKER) $(INCLUDES) $(OBJS2) $(LIBFT)
	@echo "\033[32mCHECKER Compiled! ༺ (\033[31m♥\033[32m_\033[31m♥\033[32m)༻\n\033[0m"

bonus: $(CHECKER)

clean:
	@echo "\033[33m     Cleaning the garbage ..."
	@make clean -C ./libft --silent
	@rm -rf $(OBJ_DIR)  $(OBJ_DIR_2)
	@rm -f $(OBJS1)
	@rm -f $(OBJS2)

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)
	@rm -f $(CHECKER)
	@echo "\033[32mEverything is fcleaned! ✓ (\033[31m>_<\033[32m)\n\033[0m"

re: fclean all

.PHONY: all clean fclean re bonus