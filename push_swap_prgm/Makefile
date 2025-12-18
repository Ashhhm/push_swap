NAME = push_swap

SRC = \
	utils/check.c \
	utils/error.c \
	utils/init.c \
	utils/push_swap_algo.c \
	utils/push_swap_algo_suite.c \
	utils/sort.c \
	cmd/push_rules.c \
	cmd/reverse_rotate_rules.c \
	cmd/rotate_rules.c \
	cmd/swap_rules.c \
	src/main.c

HDRS = header/push_swap.h

OBJS = $(SRC:.c=.o)

LIBFT_DIR = ../libft
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)

CC = cc
AR = ar rcs
FLAGS = -Wall -Wextra -Werror -I./header -I$(LIBFT_DIR)

all : $(NAME)

$(LIBFT) :
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c $(HDRS)
	$(CC) $(FLAGS) -c -g $< -o $@

clean :
	/bin/rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean : clean
	/bin/rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY : all clean fclean re