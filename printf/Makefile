CC = cc
CFLAGS  = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT = libft/ft_itoa.c  libft/ft_memset.c libft/ft_toupper.c libft/ft_strlen.c
MAKE = make
cd = ft_printf.c ft_itoa_u.c ft_print_null.c ft_type_c.c ft_type_d.c ft_type_perc.c ft_type_s.c ft_type_u.c ft_dec_to_hex_ui.c ft_dec_to_hex.c

obj = $(cd:.c=.o)
libft_obj = ${LIBFT:.c=.o}

all: $(NAME)

$(NAME): $(obj) $(libft_obj)
	ar rcs $(NAME) $(obj) $(libft_obj)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) -f $(NAME)

clean:
	$(MAKE) -C libft clean
	$(RM) -f $(obj) $(bobj)

re: fclean all
