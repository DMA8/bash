# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arashido <arashido@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 12:57:25 by arashido          #+#    #+#              #
#    Updated: 2023/01/24 15:03:08 by arashido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isprint.c			ft_bzero.c 				ft_isalnum.c\
			ft_isascii.c			ft_isdigit.c			ft_isprint.c\
			ft_memchr.c				ft_memcmp.c				ft_memset.c\
			ft_memcpy.c				ft_memmove.c			ft_strlcpy.c\
			ft_strlcat.c			ft_toupper.c			ft_tolower.c\
			ft_strchr.c				ft_strrchr.c			ft_strlen.c\
			ft_isalpha.c			ft_strncmp.c			ft_strnstr.c\
			ft_atoi.c					ft_calloc.c				ft_strdup.c\
			ft_substr.c				ft_putchar_fd.c		ft_putstr_fd.c\
			ft_putendl_fd.c		ft_putnbr_fd.c		ft_strjoin.c\
			ft_strmapi.c			ft_striteri.c			ft_strtrim.c\
			ft_itoa.c					ft_split.c\

BONUS = ft_lstadd_back.c		ft_lstadd_front.c		ft_lstclear.c\
				ft_lstdelone.c			ft_lstiter.c				ft_lstlast.c\
				ft_lstmap.c					ft_lstnew.c					ft_lstsize.c\

OBJ = $(SRC:.c=.o) 

BONUS_OBJ = $(BONUS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = ./libft.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJ) $(BONUS_OBJ) $(HEADER)
	ar -rcs $(NAME) $(OBJ) $(BONUS_OBJ)

.PHONY: clean fclean all re bonus libft