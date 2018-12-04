# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smakni <smakni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/20 20:30:37 by sabri             #+#    #+#              #
#    Updated: 2018/12/04 19:50:00 by smakni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	libft.a

CC		=	gcc

CFLAGS	+=	-Wall -Werror -Wextra 

CPPFLAGS =	-I include

SRC_PATH =	src

OJB_PATH =	obj

SRCS	 =	./get_next_line/get_next_line.c \
			./printf/ft_printf.c \
			./printf/ft_aux.c \
			./printf/check.c \
			./printf/check_2.c \
			./printf/analyse.c \
			./printf/conversion_c.c \
			./printf/conversion_f.c \
			./printf/conversion_f0.c \
			./printf/conversion_d0.c \
			./printf/conversion_d.c	\
			./printf/conversion_d2.c \
			./printf/conversion_d3.c \
			./printf/conversion_s.c	\
			./printf/conversion_bs.c \
			./printf/conversion_p.c \
			./printf/conversion_x.c \
			./printf/conversion_x1.c \
			./printf/conversion_0.c	\
			./printf/conversion_none.c	\
			./printf/ft_putchar_printf.c \
			./libft/ft_putchar.c \
			./libft/ft_putstr.c \
			./libft/ft_putnbr.c \
			./libft/ft_strlen.c	\
		   	./libft/ft_strdup.c \
			./libft/ft_strcmp.c \
			./libft/ft_strncmp.c \
			./libft/ft_strcpy.c \
			./libft/ft_strncpy.c \
			./libft/ft_strcat.c \
			./libft/ft_strncat.c \
			./libft/ft_memalloc.c \
			./libft/ft_memset.c	\
			./libft/ft_bzero.c \
			./libft/ft_memcpy.c \
			./libft/ft_memccpy.c \
			./libft/ft_memmove.c \
			./libft/ft_memchr.c \
			./libft/ft_memcmp.c \
			./libft/ft_strchr.c \
			./libft/ft_strrchr.c \
			./libft/ft_isdigit.c \
			./libft/ft_isascii.c \
			./libft/ft_isalpha.c \
			./libft/ft_isalnum.c \
			./libft/ft_strstr.c \
			./libft/ft_strnstr.c \
			./libft/ft_toupper.c \
			./libft/ft_tolower.c \
			./libft/ft_isprint.c \
			./libft/ft_memdel.c	\
			./libft/ft_strnew.c	\
			./libft/ft_strdel.c	\
			./libft/ft_strclr.c	\
			./libft/ft_striter.c \
			./libft/ft_striteri.c \
			./libft/ft_strmap.c \
			./libft/ft_strmapi.c \
			./libft/ft_strequ.c \
			./libft/ft_strnequ.c \
			./libft/ft_strsub.c \
			./libft/ft_strjoin.c \
			./libft/ft_strtrim.c \
			./libft/ft_strsplit.c \
			./libft/ft_putendl.c \
			./libft/ft_putchar_fd.c \
			./libft/ft_putstr_fd.c \
			./libft/ft_putendl_fd.c \
			./libft/ft_putnbr_fd.c \
			./libft/ft_itoa.c \
			./libft/ft_power.c \
			./libft/ft_lstnew.c \
			./libft/ft_lstdelone.c \
			./libft/ft_lstdel.c \
			./libft/ft_lstadd.c \
			./libft/ft_lstiter.c \
			./libft/ft_lstmap.c \
			./libft/ft_lstmove_last.c \
			./libft/ft_llast.c \
			./libft/ft_strtoupper.c \
			./libft/ft_atoi.c \
			./libft/ft_strlcat.c \
			./libft/ft_strtolower.c \
			./libft/ft_sqrt.c \
			./libft/ft_factorial.c \
			./libft/ft_print_bits.c \
			./libft/ft_strsub_free.c \
			./libft/ft_strjoin_free.c \
			./libft/ft_strlen_c.c \
			./libft/ft_strlen_from.c \
			./libft/ft_memset_from.c \
			./libft/ft_itoa_li.c \
			./libft/ft_itoa_lli.c \
			./libft/ft_itoa_imax.c \
			./libft/ft_itoa_it.c \
			./libft/ft_itoa_ui.c \
			./libft/ft_itoa_lui.c \
			./libft/ft_itoa_llui.c \
			./libft/ft_itoa_uit.c \
			./libft/ft_itoa_base.c \
			./libft/ft_itoa_base_ui.c \
			./libft/ft_itoa_base_llui.c \
			./libft/ft_itoa_base_lui.c \
			./libft/ft_itoa_base_it.c \
			./libft/ft_itoa_base_uit.c \
			./libft/ft_putchar2.c \
			./libft/ft_putchar1.c \
			./libft/ft_putchar3.c \
			./libft/ft_putchar4.c \
			./libft/ft_memjoin.c \
			./libft/ft_memcpy_from.c \
			./libft/ft_putstr_printf.c \
			./libft/ft_itoa_sit.c \
			./libft/ft_strjoin_2free.c \
			./libft/ft_strjoin_free1.c

OBJS	=	$(SRCS:.c=.o)

LM		=	@ar rc

RM		=	@rm -f

all: $(NAME)

$(NAME): $(OBJS)
		$(LM) $(NAME) $(OBJS)
		ranlib libft.a
		@echo "[LIBFT OK]"

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY : all, clean, fclean, re
