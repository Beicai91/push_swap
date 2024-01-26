NAME = push_swap
CC = cc
CFLAGS = -Wextra -Werror -Wall
LIBFT_PATH = ./libft
LIBRARY = $(LIBFT_PATH)/libft.a

SRCS = main.c \
	   operation_a.c \
	   operation_b.c \
	   lst_utils.c \
	   check_init_utils.c \
	   check_init.c \
	   chunksort_utils.c \
	   chunk_utils.c \
	   array_utils.c \
	   chunk_selection.c \
	   simple_sort.c \
	   radix_sort.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME):$(OBJS) $(LIBRARY)
	$(CC) $(CFLAGS) -L $(LIBFT_PATH) -lft $(OBJS) -o $@

$(LIBRARY):
	make -C $(LIBFT_PATH) all

%.o: %.c
	$(CC) $(CFLAGS) -I $(LIBFT_PATH) -c $< -o $@

clean:
	make -C $(LIBFT_PATH) fclean
	rm -rf $(OBJS)

fclean:clean
	rm -rf $(NAME)

re:fclean all

.PHONY: all, clean, fclean, re
