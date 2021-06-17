# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrochet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/25 14:23:35 by mrochet           #+#    #+#              #
#    Updated: 2021/06/16 16:48:40 by mrochet          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

ERASE		=	\033[2K\r
GREY		=	\033[30m
RED			=	\033[31m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
PINK		=	\033[35m
CYAN		=	\033[36m
WHITE		=	\033[37m
BOLD		=	\033[1m
UNDER		=	\033[4m
SUR			=	\033[7m
END			=	\033[0m

NAME = pipex

SRCS_NAME = pipex.c \
			pipex_second.c

LIB_NAME = pipex.h

OBJS_NAME = $(SRCS_NAME:.c=.o)

SRCS_PATH = srcs
LIB_PATH = ./includes
OBJS_PATH = .objs

SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))
LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

RM		=	rm -f
CC		=	gcc
#FSAN	=	-g3 -fsanitize=address
#CFLAGS	=	-Wall -Werror -Wextra
#leaks --atExit -q -- ./a.out
	

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c $(LIB) libft/libft.a
			@mkdir -p $(OBJS_PATH)
			@$(CC) $(CFLAGS) -c $< -o $@ -I $(LIB_PATH)
			@printf "$(ERASE)$(YELLOW)$@$(END)"

all:	compil_lib
		@$(MAKE) $(NAME)

compil_lib :	
			@$(MAKE) -C ./libft

$(NAME): $(OBJS)
	@printf "$(ERASE)"
	@$(CC)  $(FSAN) $(CFLAGS) $(OBJS) -o $(NAME) -I $(LIB_PATH) -Llibft -lft
	@echo "$(BOLD)$(GREEN)Compilation $(NAME) Succes !$(END)"



clean :
		@rm -rf $(OBJS_PATH)
		@echo "$(RED)Clean $(NAME) Succes !$(END)"

fclean :	clean
			@rm -f $(NAME)
			@$(MAKE) fclean -C ./libft
			@echo "$(RED)Fclean $(NAME) Succes !$(END)"


re:		fclean all clean compil_lib
