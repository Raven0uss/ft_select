#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 18:53:41 by sbelazou          #+#    #+#              #
#    Updated: 2017/03/26 11:50:42 by sbelazou         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	libft.a
SRC			=	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
				ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c\
				ft_memcpy.c	ft_memdel.c	ft_memmove.c ft_memset.c ft_putchar.c\
				ft_putchar_fd.c	ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c\
				ft_putstr.c	ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c\
				ft_strcpy.c	ft_strdel.c	ft_strdup.c	ft_strequ.c	ft_striter.c ft_striteri.c\
				ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c\
				ft_strncat.c ft_strncmp.c ft_strncmp.c ft_strncpy.c	ft_strnequ.c\
				ft_strnew.c	ft_strnstr.c ft_strrchr.c ft_strsplit.c	ft_strstr.c ft_strsub.c\
				ft_strtrim.c ft_tolower.c ft_toupper.c ft_lstiter.c	ft_lstadd.c\
				ft_lstnew.c	ft_lstdel.c  ft_swap.c ft_sqrt.c ft_pow.c\
				ft_fact.c ft_isblank.c ft_sort_tab.c ft_aff_tab.c ft_strcmp_case.c ft_onlyone.c\
				get_next_line.c ft_sizetab.c ft_rev_tab.c ft_tabfree.c ft_intlen.c\
				ft_whitespaces.c ft_freestr.c

OBJ			=	$(SRC:.c=.o)
CFLAGS		=	-Wall -Wextra -Werror
CC			=	/usr/bin/gcc
RM			=	/bin/rm -f
ECHO		=	echo


$(NAME)	:		$(OBJ)
				-@ar rc $(NAME) $(OBJ)
				@$(ECHO) "\033[32mAll sources has been compiled."
				@$(ECHO) "$(NAME) has been created.\033[0m"

run :
				ranlib $(NAME)
				@$(ECHO) "\033[32mIndex has been generated.\033[0m"

clean	:
				@$(RM) $(OBJ)
				@$(ECHO) "\033[31mObjects of $(NAME) has been removed.\033[0m"

all		:		$(NAME)

fclean	:
				-@$(RM) $(NAME)
				@$(ECHO) "\033[31m$(NAME) has been removed.\033[0m"

re		:		fclean all

.PHONY	:		all clean fclean re
