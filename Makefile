#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/07 20:16:27 by sbelazou          #+#    #+#              #
#    Updated: 2017/04/12 12:04:17 by sbelazou         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	ft_select

DIRSRC		=	./srcs/
DIROBJ		=	./objs/

INC_LIB		=	./includes/libft/libft.a
SRC			=	$(shell find $(DIRSRC)*.c -type f)
OBJ			=	$(patsubst $(DIRSRC)%,$(DIROBJ)%,$(SRC:.c=.o))

FLAGS		=
ifdef FLAGS
	ifeq ($(FLAGS), yes)
CFLAGS		=	-Wall -Wextra -Werror
	endif
	ifeq ($(FLAGS), debug)
CFLAGS		=	-Wall -Wextra -Werror -ansi -pedantic -g
	endif
	else
CFLAGS		=
endif

CC			=	/usr/bin/gcc
RM			=	/bin/rm -rf
ECHO		=	echo

all:			$(NAME)

$(NAME):		$(OBJ)
				-@make -C includes/libft/
				-@$(CC) $(INC_LIB) $(CFLAGS) -o $@ $^ -lncurses
				@$(ECHO) "\033[32mAll sources are compiled. "
				@$(ECHO) "$(NAME) has been created.\033[0m"

clean	:
				-@make clean -C includes/libft/
				@($(RM) $(DIROBJ))
				@$(ECHO) "\033[31mObjects of $(NAME) has been removed.\033[0m"

fclean	:		clean
				-@make fclean -C includes/libft/
				-@$(RM) $(NAME)
				@$(ECHO) "\033[31m$(NAME) has been removed.\033[0m"

re		:		fclean all

zen		:		clean
				-@find . \( -name "*~" -o -name "#*#" \) -delete
				@$(ECHO) "\033[31mBack-up files has been removed.\033[0m"

git		:	zen fclean
			git add -f *
			git commit -am "Push with Makefile"
			git push

.PHONY	:		all clean fclean re zen git

$(DIROBJ)%.o	:	$(DIRSRC)%.c
					@mkdir -p $(dir $@)
					$(CC) $(CFLAGS) -o $@ -c $<
