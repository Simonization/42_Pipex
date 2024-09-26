# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slangero <slangero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/05 11:00:32 by slangero          #+#    #+#              #
#    Updated: 2024/09/25 17:43:46 by slangero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


PIPEX_SRCS =	main.c \
				process.c \
				fork_pipe.c \
				execute_command.c \
				extract_env.c \
				create_exec_path.c \
				error_free.c \

PRINTF_SRCS =	ft_printf/ft_printf.c \
				ft_printf/print_charstr.c \
				ft_printf/print_nbr.c \
				ft_printf/print_pointer.c \

LIBFT_SRCS =	libft/ft_strlen.c \
				libft/ft_split.c libft/ft_strjoin.c libft/ft_strncmp.c \
				libft/ft_substr.c \
				libft/ft_strdup.c \
				libft/ft_putstr_fd.c

SRCS = $(PIPEX_SRCS) $(PRINTF_SRCS) $(LIBFT_SRCS) 

OBJS = $(SRCS:.c=.o)

NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

INC = -I. -Ift_printf -Ilibft

RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re