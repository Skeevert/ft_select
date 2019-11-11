OBJS = srcs/main.o \
	   srcs/arg.o

FLAGS = -Wall -Wextra -Werror

LIB_NAME = srcs/libft/libft.a
NAME = ft_select

all: $(NAME)

$(NAME): $(OBJS)
	make -C srcs/libft
	gcc $(FLAGS) $(OBJS) $(LIB_NAME) -o $@ -ltermcap

$(OBJS): %.o: %.c
	gcc -c $(FLAGS) $< -o $@ -I./includes -I./srcs/libft

clean:
	make -C srcs/libft clean
	rm -f $(OBJS)

fclean: clean
	make -C srcs/libft fclean
	rm -f $(NAME)

re: fclean all
