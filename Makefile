# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roberodr <roberodr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 12:42:17 by roberodr          #+#    #+#              #
#    Updated: 2023/04/14 13:11:34 by roberodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = ft_split_cmd_arg.c ft_split.c ft_strchr.c ft_strjoin.c ft_strlcpy.c ft_strlen.c \
	ft_strncmp.c ft_substr.c ft_get_path.c pipex.c ft_unioncmd.c ft_strcpy.c ft_child.c \
	ft_father.c	ft_error.c

OBJS = $(SRCS:.c=.o)

FLAGS	+=	-Wall -Werror -Wextra

INCLUDE = -I ./

DEPS = $(SRCS:.c=.d)
%.o: %.c
	@$(CC) $(CFLAGS) -MMD $(INCLUDE) -c $< -o $@
	@echo "compiling: $<"

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
-include $(DEPS)


clean:
	rm -f $(OBJS) $(DEPS)

fclean:		clean
	@rm -f $(NAME) 

re:	fclean all

.PHONY:	all clean fclean re bonus