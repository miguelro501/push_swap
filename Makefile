# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miguelro <miguelro@students.42lisboa.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 17:00:30 by marvin            #+#    #+#              #
#    Updated: 2023/02/06 13:54:30 by miguelro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap


CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

LIBFT = ./Library/Libft/libft.a
LIBFT_PATH = ./Library/Libft

FT_PRINTF = ./Library/Printf/libftprintf.a
FT_PRINTF_PATH = ./Library/Printf

INC = -I ./Library -I ./Library/Libft  -I ./Library/Printf

SRC_PATH = ./sources

OBJ_PATH = ./objects

SRC_NAME = push_swap.c operations.c utils.c sort_3.c sort_5.c sort_100.c sort_500.c\

OBJS = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

DEFAULT = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m


all: $(NAME)

$(NAME) : $(OBJS)
	@make -C $(LIBFT_PATH)
	@make -C $(FT_PRINTF_PATH)
	@$(CC) $(CFLAGS) $(OBJS) $(INC) $(LIBFT) $(FT_PRINTF) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled $(DEFAULT)"

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p objects
	@$(CC) -c $(CFLAGS) $(Library) $< -o $@

clean:
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(FT_PRINTF_PATH)
	@rm -rf objects/
	@echo "$(YELLOW)$(NAME).o files are removed$(DEFAULT)"

fclean:
	@rm -rf objects/
	@make fclean -C $(LIBFT_PATH)
	@make fclean -C $(FT_PRINTF_PATH)
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) is deleted$(DEFAULT)"


re: fclean all
