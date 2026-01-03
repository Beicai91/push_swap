NAME = push_swap
CC = cc
CFLAGS = -Wextra -Werror -Wall
LIBFT_PATH = ./lib/libft
LIBRARY = $(LIBFT_PATH)/libft.a

SRCS = src/main.c \
	   src/operation_a.c \
	   src/operation_b.c \
	   src/lst_utils.c \
	   src/check_init_utils.c \
	   src/check_init.c \
	   src/chunksort_utils.c \
	   src/chunk_utils.c \
	   src/array_utils.c \
	   src/chunk_selection.c \
	   src/simple_sort.c \
	   src/radix_sort.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME):$(OBJS) $(LIBRARY)
	$(CC) $(CFLAGS) -L $(LIBFT_PATH) -lft $(OBJS) -o $@

$(LIBRARY):
	make -C $(LIBFT_PATH) all

%.o: %.c
	$(CC) $(CFLAGS) -I ./include -I $(LIBFT_PATH) -c $< -o $@

clean:
	make -C $(LIBFT_PATH) fclean
	rm -rf $(OBJS)

fclean:clean
	rm -rf $(NAME)

re:fclean all

.PHONY: all, clean, fclean, re
