# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: msotnych <msotnych@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2026/10/23 17:33:59 by msotnych      #+#    #+#                  #
#    Updated: 2026/10/27 15:31:13 by msotnych      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprint.a 
CC = cc
CFLAG = -Wall -Wextra -Werror



SRC = 

OBJ = $(SRC:.c=.o)

all: $(NAME)
AR = ar rcs
RM: rm -f
%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@  
	
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean: 
	$(RM) $(OBJ) 
fclean: 
	$(RM) $(OBJ) $(NAME)

re: fclean all

.PHONY: clean fclean all re