# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 11:44:58 by jyriarte          #+#    #+#              #
#    Updated: 2025/02/03 15:52:10 by jyriarte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo

CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

SOURCES = philo.c print_usage.c philo_utils.c

OBJECTS = $(SOURCES:.c=.o)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) -o $@ $^ 
	@echo "$(NAME) OK!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@  

all: $(NAME)

clean:
	@$(RM) $(OBJECTS) 
	@echo "object files cleaned!"

fclean:
	@$(RM) $(OBJECTS) 
	@$(RM) $(NAME) 
	@echo "$(NAME) cleaned!"

re: fclean all

.PHONY: all re clean fclean
