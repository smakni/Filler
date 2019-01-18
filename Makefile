# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smakni <smakni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 13:20:28 by smakni            #+#    #+#              #
#    Updated: 2019/01/18 15:17:12 by smakni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	smakni.filler

CC			=	gcc

CFLAGS		+=	-Wall -Werror -Wextra -g3 

CPPFLAGS	=	-I include -I libft/include
				
SRC_PATH	=	src

OBJ_PATH	=	obj

LDFLAGS		=	-L libft

LDLIBS		=	-lft

SRC_NAME	=	filler.c \
				algo.c \
				save_data.c \
				read_data.c \
				print_data.c \
				heatmap.c

OBJ_NAME	=	$(SRC_NAME:.c=.o)

SRC 		= 	$(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ 		= 	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ) 
		make -C libft
		$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

sanitize: 
		make -C libft
		$(CC) -fsanitize=address -g3 $(LDFLAGS) $(LDLIBS) $(OBJ) -o smakni.filler

resanitize: fclean $(OBJ) 
		make -C libft
		$(CC) -fsanitize=address -g3 $(LDFLAGS) $(LDLIBS) $(OBJ) -o smakni.filler

clean:
	rm -fv $(OBJ)
	rmdir $(OBJ_PATH) 2> /dev/null || true
	make clean -C libft

fclean: clean
	rm -fv $(NAME)
	make fclean -C libft

re:
	make fclean
	make

.PHONY: all, clean, fclean, re

norme:
	norminette $(SRC)
	norminette ./include
