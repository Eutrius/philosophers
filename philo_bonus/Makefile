# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 11:44:58 by jyriarte          #+#    #+#              #
#    Updated: 2025/02/13 21:28:52 by jyriarte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo_bonus

CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

SOURCES = main_bonus.c check_args_bonus.c philosophers_bonus.c \
		  utils_bonus.c table_bonus.c ft_utils_bonus.c\
		  ph_states_bonus.c simulate_bonus.c monitor_bonus.c

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
