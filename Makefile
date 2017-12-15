# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/09 13:27:26 by dpolosuk          #+#    #+#              #
#    Updated: 2017/12/13 13:18:46 by dpolosuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_LIB =	ft_atoi.c \
			ft_bubsort_intarr.c \
			ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_itoa_base.c \
			ft_lstadd.c \
			ft_lstdel.c \
			ft_lstdelfunc.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstrev.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_merge.c \
			ft_mergesort_intarr.c \
			ft_power.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_sqrt.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strrev.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_swap_i.c \
			ft_swap_s.c \
			ft_tolower.c \
			ft_toupper.c \
			get_next_line.c \

SRC =		ft_printf.c \
			ft_pf_print_unicode.c \

OBJ_PATH = ./lftpf/
OBJ_LIB_PATH = ./lft2.0/

INCLUDE = -I ./lftpf/includes -I ./lft2.0/includes/
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))
OBJ_LIB = $(addprefix $(OBJ_LIB_PATH), $(SRC_LIB:.c=.o))
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(OBJ) $(OBJ_LIB)
	@ar rc $(NAME) $(OBJ) $(OBJ_LIB)
	@ranlib $(NAME)
	@echo made

%.o: %.c
	@gcc -g $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	@/bin/rm -f $(OBJ) $(OBJ_LIB)
	@echo cleaned

fclean: clean
	@/bin/rm -f $(NAME)
	@echo fcleaned


re: fclean all