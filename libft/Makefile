# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-hayy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 10:02:56 by ael-hayy          #+#    #+#              #
#    Updated: 2021/11/27 13:57:47 by ael-hayy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
NAME = libft.a
FILES = ft_bzero.c \
      ft_memset.c \
      ft_memcpy.c \
      ft_memchr.c \
      ft_memcmp.c \
      ft_memmove.c \
      ft_strlen.c \
      ft_isalpha.c \
      ft_isdigit.c \
      ft_isalnum.c \
      ft_isascii.c \
      ft_isprint.c \
      ft_toupper.c \
      ft_tolower.c \
      ft_strchr.c \
      ft_strrchr.c \
      ft_strncmp.c \
      ft_strlcpy.c \
      ft_strlcat.c \
      ft_strnstr.c \
      ft_atoi.c \
      ft_calloc.c \
      ft_strdup.c \
      ft_substr.c \
      ft_strjoin.c \
      ft_strtrim.c \
      ft_split.c \
      ft_striteri.c\
      ft_itoa.c \
      ft_strmapi.c \
      ft_putchar_fd.c \
      ft_putstr_fd.c \
      ft_putendl_fd.c \
      ft_putnbr_fd.c

B_FILES = ft_lstnew_bonus.c \
      ft_lstadd_front_bonus.c \
      ft_lstsize_bonus.c \
      ft_lstlast_bonus.c \
      ft_lstadd_back_bonus.c \
      ft_lstdelone_bonus.c \
      ft_lstclear_bonus.c \
      ft_lstiter_bonus.c \
      ft_lstmap_bonus.c

OBJECTS = $(FILES:.c=.o)

B_OBJECTS = $(B_FILES:.c=.o)

%.o : %.c
	cc -c -Wall -Wextra -Werror $<
	ar -rcs $(NAME) $@

all:  $(NAME)

$(NAME): $(OBJECTS)

bonus: $(B_OBJECTS)

clean:
	$(RM) $(B_OBJECTS) $(OBJECTS)

fclean: clean
	$(RM) libft.a

re: fclean all

.PHONY: all clean fclean re bonus
