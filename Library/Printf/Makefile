# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miguelro <miguelro@students.42lisboa.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 15:22:05 by miguelro          #+#    #+#              #
#    Updated: 2023/02/06 12:54:35 by miguelro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_check_format.c ft_printf.c ft_put.c ft_putnbrs.c \

OBJS =	$(SRCS:.c=.o)

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

DEFAULT = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m

all: $(NAME)

$(NAME): $(SRCS:.c=.o)
				@ar rcs $(NAME) $(SRCS:.c=.o)
				@echo "$(GREEN)$(NAME) compiled $(DEFAULT)"
clean:
				@$(RM) $(OBJS)
				@echo "$(YELLOW)$(NAME).o files are removed$(DEFAULT)"

fclean:			clean
				@$(RM) $(NAME)
				@echo "$(RED)$(NAME) is deleted$(DEFAULT)"
				
re:				fclean $(NAME)