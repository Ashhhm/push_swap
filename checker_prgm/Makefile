bonus = checker

SRC = \
	utils/cmd_read.c \
	utils/get_next_line.c \
	utils/get_next_line_utils.c \
	src/main.c \
	../push_swap_prgm/utils/check.c \
	../push_swap_prgm/utils/sort.c \
	../push_swap_prgm/utils/error.c \
	../push_swap_prgm/cmd/push_rules.c \
	../push_swap_prgm/cmd/reverse_rotate_rules.c \
	../push_swap_prgm/cmd/rotate_rules.c \
	../push_swap_prgm/cmd/swap_rules.c \
	../push_swap_prgm/utils/init.c \
	../push_swap_prgm/utils/push_swap_algo.c

HDRS = header/checker.h

OBJS = $(SRC:.c=.o)

LIBFT_DIR = ../libft
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)

CC = cc
AR = ar rcs
FLAGS = -Wall -Wextra -Werror -g -I./header -I$(LIBFT_DIR) -I../push_swap_prgm/header

all : $(bonus)

$(LIBFT) :
	@$(MAKE) -C $(LIBFT_DIR)

$(bonus) : $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) -o $(bonus)

%.o: %.c $(HDRS)
	$(CC) $(FLAGS) -c -g $< -o $@
