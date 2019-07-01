# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: vmulder <vmulder@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/15 12:11:34 by vmulder        #+#    #+#                 #
#    Updated: 2019/03/29 19:08:58 by vmulder       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = main.c allocate.c check_valid.c checktet.c checktet2.c\
gridcalc.c sort_tets.c sort_tets2.c sort_tets3.c
HEADER = ./fillit-files/

all: $(NAME)

$(NAME): 
	make -C ./libft/
	gcc -o $(NAME) $(SRCS) -I $(HEADER) -L ./libft/ -lft -Wall -Wextra -Werror
clean:
	make -C ./libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft/ fclean

re: fclean all
