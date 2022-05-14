NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar crs

FILES = ft_isalpha \
		ft_isdigit \
		ft_isascii \
		ft_isalnum \
		ft_isprint \
		ft_strlen \
		ft_memset \
		ft_bzero \
		ft_memcpy \
		ft_memmove \
		ft_strlcpy \
		ft_strlcat \
		ft_toupper \
		ft_tolower \
		ft_strchr \
		ft_strrchr \
		ft_strncmp \
		ft_memchr \
		ft_memcmp \
		ft_strnstr \
		ft_atoi \
		ft_calloc \
		ft_strdup \
		\
		ft_substr \
		ft_strjoin \
		ft_strtrim \
		ft_split \
		ft_itoa \
		ft_strmapi \
		ft_striteri \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putnbr_fd \
		ft_putendl_fd \

BONUS = 	ft_lstnew \
	  		ft_lstadd_front \
	  		ft_lstsize \
	  		ft_lstlast \
	  		ft_lstadd_back \
	  		ft_lstdelone \
	  		ft_lstclear \
			ft_lstiter \
			ft_lstmap

all: $(NAME)

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_B = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(BONUS)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
OBJS_B = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(BONUS)))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus: $(OBJS_B)
	$(AR) $(NAME) $^

norm:
	@norminette -R CheckForbiddenSourceHeader *.c *.h)

ifdef norm
	@echo "\n\033[31mNorminette is Sad ⌐(ಠ۾ಠ)¬\n"
else
	@echo "\033[32mNorminette is Happy! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"
endif

clean:
	@rm -f $(OBJS)
	@echo "OBJ deleted"
	@rm -f $(OBJS_B)
	@echo "BONUS deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all


.PHONY: all clean fclean re bonus norm





