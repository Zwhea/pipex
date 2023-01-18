# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twang <twang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 09:33:29 by twang             #+#    #+#              #
#    Updated: 2023/01/18 13:37:14 by twang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				pipex

HEADERS =			mandatory/pipex.h
HEADERS_BONUS =		bonus/pipex_bonus.h

SOURCES =			mandatory/pipex.c					\
					mandatory/process/childs.c			\
					mandatory/process/close.c			\
					mandatory/parsing/arguments.c		\
					mandatory/parsing/commands.c		\
					mandatory/parsing/struct.c			\
					
SOURCES_BONUS =		bonus/pipex_bonus.c					\
					bonus/process/childs_bonus.c		\
					bonus/process/close_bonus.c			\
					bonus/parsing/arguments_bonus.c		\
					bonus/parsing/commands_bonus.c		\
					bonus/parsing/struct_bonus.c		\
					bonus/parsing/here_doc_bonus.c		\

BONUS_CHECK =		0

LIBRARY =			libft/libft.a	
					
OBJECTS =			$(SOURCES:.c=.o)
OBJECTS_BONUS =		$(SOURCES_BONUS:.c=.o)

CFLAGS	= 			-Wall -Wextra -Werror -I mandatory/ -I bonus/
DFLAGS	=			-g3 -fsanitize=address

all :	lib 
	$(MAKE) $(NAME)

%.o : %.c $(HEADERS) $(LIBRARY)
	$(CC) $(CFLAGS) -c $< -o $@

ifeq (${BONUS_CHECK}, 0)
$(NAME): $(OBJECTS)
else
$(NAME): $(OBJECTS_BONUS)
endif

$(NAME): 
	$(CC) $(CFLAGS) $(LIBRARY) $^ -o $@

bonus:
	$(MAKE) BONUS_CHECK=1

lib :
	$(MAKE) -C ./libft

clean :
	$(MAKE) -C libft clean
	$(RM) $(OBJECTS) $(OBJECTS_BONUS)

fclean : clean 
	$(MAKE) -C libft fclean
	$(RM) $(NAME)

re : fclean
	$(MAKE) all

.PHONY: all clean fclean re lib bonus
