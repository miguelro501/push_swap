# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miguelro <miguelro@students.42lisboa.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 15:22:05 by miguelro          #+#    #+#              #
#    Updated: 2023/02/06 12:49:38 by miguelro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalnum.c ft_isprint.c ft_strlcat.c ft_memchr.c\
ft_atoi.c ft_isalpha.c ft_strrchr.c ft_memcmp.c ft_putendl_fd.c\
ft_strchr.c ft_strlcpy.c ft_strnstr.c ft_putnbr_fd.c\
ft_tolower.c ft_bzero.c ft_isascii.c ft_memcpy.c ft_split.c\
ft_memmove.c ft_strlen.c ft_strncmp.c ft_calloc.c ft_itoa.c\
ft_toupper.c ft_isdigit.c ft_memset.c ft_strdup.c ft_strmapi.c\
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c\
ft_substr.c ft_strjoin.c ft_strtrim.c\

BONUS =	ft_lstnew.c ft_lstadd_front.c ft_lstclear.c\
ft_lstsize.c ft_lstlast.c ft_lstiter.c\
ft_lstadd_back.c ft_lstdelone.c ft_lstmap.c\

OBJS =	$(SRCS:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o) 

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
				@$(RM) $(OBJS) $(BONUS_OBJS)
				@echo "$(YELLOW)$(NAME).o files are removed$(DEFAULT)"

fclean:			clean
				@$(RM) $(NAME)
				@echo "$(RED)$(NAME) is deleted$(DEFAULT)"

re:				fclean $(NAME)

bonus:			@$(OBJS) $(BONUS_OBJS)
				@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)k