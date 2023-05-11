NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I ./printf -I ./printf/libft
SRCS = stack_a_functions.c utils.c main.c stack_b_functions.c stack_common_functions.c errors.c ft_atol.c \
		utils2.c sort.c push_swap.c utils3.c sort2.c
LIBFT = ./printf/libft/libft.a
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = ./printf/libft/

all: libft printf $(NAME)

$(NAME): $(OBJS)
	$(CC) $(INCLUDE) $(OBJS) -L./printf/ -lftprintf -L./printf/libft -lft -o push_swap

libft:
	${MAKE} -C $(LIBFT_DIR)

printf:
	${MAKE} -C ./printf


clean:
	@rm -f $(OBJS)
	@${MAKE} clean -C ./printf/

fclean: clean
	@rm -f $(NAME)
	@${MAKE} -C ./printf/ fclean

re: fclean all

.PHONY: all re fclean clean libft printf