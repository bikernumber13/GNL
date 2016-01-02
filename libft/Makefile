# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouhier <mbouhier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 10:53:48 by mbouhier          #+#    #+#              #
#    Updated: 2016/01/02 11:16:21 by mbouhier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Werror -Wextra -Wall

SRCS_NAME = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		   ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c \
		   ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c \
		   ft_memccpy.c ft_memchr.c ft_memcpy.c ft_memdel.c ft_memmove.c \
		   ft_memcmp.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
		   ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
		   ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c \
		   ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c \
		   ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c \
		   ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c \
		   ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c \
		   ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c

SRCO = $(SRCS_NAME:.c=.o)

all : $(NAME)

$(NAME) :
		@echo "\033[2J"
		@echo "\033[100A"
		@echo "\033[32m   __    ____ ___   ____ ______"
		@echo "  / /   /  _// _ ) / __//_  __/"
		@echo " / /__ _/ / / _  |/ _/   / /   "
		@echo "/____//___//____//_/    /_/    "
		@echo "                               "
		@echo " MAKE ALL \033[0m"
		@gcc $(FLAGS) -I. -c $(SRCS_NAME)
		@ar rc $(NAME) $(SRCO)
		@ranlib $(NAME)

clean :
		@echo "\033[2J"
		@echo "\033[100A"
		@echo "\033[31m   __    ____ ___   ____ ______"
		@echo "  / /   /  _// _ ) / __//_  __/"
		@echo " / /__ _/ / / _  |/ _/   / /   "
		@echo "/____//___//____//_/    /_/    "
		@echo "                               "
		@echo " MAKE CLEAN \033[0m"
		@rm -f $(SRCO)

fclean : clean
		@echo "\033[2J"
		@echo "\033[100A"
		@echo "\033[34m   __    ____ ___   ____ ______"
		@echo "  / /   /  _// _ ) / __//_  __/"
		@echo " / /__ _/ / / _  |/ _/   / /   "
		@echo "/____//___//____//_/    /_/    "
		@echo "                               "
		@echo " MAKE FCLEAN \033[0m"
		@rm -f $(NAME)

re : fclean all
		@echo "\033[2J"
		@echo "\033[100A"
		@echo "\033[36m   __    ____ ___   ____ ______"
		@echo "  / /   /  _// _ ) / __//_  __/"
		@echo " / /__ _/ / / _  |/ _/   / /   "
		@echo "/____//___//____//_/    /_/    "
		@echo "                               "
		@echo " MAKE RE \033[0m"


.PHONY : all re fclean clean
