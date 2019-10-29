# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshawand <hshawand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 16:37:05 by hshawand          #+#    #+#              #
#    Updated: 2019/09/26 15:18:38 by hshawand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJECTS = ft_memset.o \
ft_bzero.o \
ft_memcpy.o \
ft_memccpy.o \
ft_memmove.o \
ft_memchr.o \
ft_memcmp.o \
ft_strlen.o \
ft_strdup.o \
ft_strcpy.o \
ft_strncpy.o \
ft_strcat.o \
ft_strncat.o \
ft_strlcat.o \
ft_strchr.o \
ft_strrchr.o \
ft_strstr.o \
ft_strnstr.o \
ft_strcmp.o \
ft_strncmp.o \
ft_atoi.o \
ft_isalpha.o \
ft_isalnum.o \
ft_isascii.o \
ft_isdigit.o \
ft_isprint.o \
ft_tolower.o \
ft_toupper.o \
ft_itoa.o \
ft_stoa.o \
ft_memalloc.o \
ft_memdel.o \
ft_putchar_fd.o \
ft_putchar.o \
ft_putendl_fd.o \
ft_putendl.o \
ft_putnbr.o \
ft_putstr_fd.o \
ft_putstr.o \
ft_strclr.o \
ft_strdel.o \
ft_strequ.o \
ft_striter.o \
ft_striteri.o \
ft_strjoin.o \
ft_strmap.o \
ft_strmapi.o \
ft_strnequ.o \
ft_strnew.o \
ft_strsplit.o \
ft_splitspctab.o \
ft_strsub.o \
ft_strtrim.o \
ft_putnbr_fd.o \
ft_lstadd.o \
ft_lstdel.o \
ft_lstdelone.o \
ft_lstiter.o \
ft_lstmap.o \
ft_lstnew.o \
ft_stroffcat.o

LIB_NAME = libft.a

all: $(LIB_NAME)

$(LIB_NAME): $(OBJECTS)
	ar rc $@ $(OBJECTS)

$(OBJECTS): %.o: %.c
	gcc -c -Wall -Wextra -Werror $< -o $@ -Iincludes

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(LIB_NAME)
re: fclean all
