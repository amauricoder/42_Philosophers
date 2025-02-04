# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 18:47:33 by aconceic          #+#    #+#              #
#    Updated: 2024/05/08 15:55:28 by aconceic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##############################################
#                 COMPILATION                #
##############################################
CFLACGS = -Wall -Wextra -Werror -g -pthread #-fsanitize=thread #-fsanitize=address
GCC = gcc
CC = cc

##############################################
#                  COMMANDS                  #
##############################################
RM = rm -rf

##############################################
#                 MAIN SOURCES               #
##############################################
NAME = philo
OBJ_DIR = ./objs/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
SRC_DIR = ./source/
SRC = ft_utils.c input_valid.c error.c frees.c \
		init_value.c dinner_table.c \
		threads.c dinner_utils.c ft_utils2.c \

##############################################
#                    RULES                   #
##############################################
all : $(NAME)

$(OBJ) : | $(OBJ_DIR)

$(OBJ_DIR) :
	mkdir $@

$(NAME) : $(OBJ)
	$(CC) $(CFLACGS) $(OBJ) $(SRC_DIR)main.c -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLACGS) -c $< -o $@

clean :
	$(RM) $(OBJ_DIR)
	
fclean : 
	$(RM) $(OBJ_DIR) $(NAME)
	
re: fclean all