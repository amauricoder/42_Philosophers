# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 18:47:33 by aconceic          #+#    #+#              #
#    Updated: 2024/04/10 19:08:09 by aconceic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##############################################
#                 COMPILATION                #
##############################################
CFLACGS = -Wall -Wextra -Werror
GCC = cc -g
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
SRC = ft_utils.c \

##############################################
#                    RULES                      #
##############################################
all : $(NAME)

$(OBJ) : | $(OBJ_DIR)

$(OBJ_DIR) :
	mkdir $@

$(NAME) : $(OBJ)
	$(GCC) $(CFLACGS) $(OBJ) $(SRC_DIR)main.c -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(GCC) $(CFLACGS) -c $< -o $@

clean :
	$(RM) $(OBJ_DIR)
	
fclean : 
	$(RM) $(OBJ_DIR) $(NAME)
	
re: fclean all