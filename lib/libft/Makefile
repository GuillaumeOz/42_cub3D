# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/06 15:28:16 by gozsertt          #+#    #+#              #
#    Updated: 2020/05/10 20:20:52 by gozsertt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC 		=	gcc

SRC_DIR = 	$(shell find srcs -type d)
INC_DIR = 	$(shell find includes -type d)
OBJ_DIR = 	obj

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

# List de toute les library a linker au projet (le nom - le lib et - le .a)

SRC		= ft_f_floor.c ft_isdigit.c ft_strnew.c ft_strdup.c ft_strchr.c \
	ft_memdel.c ft_strcmp.c ft_strcut.c ft_strmap.c ft_itoa.c ft_ischar.c \
	ft_putchar.c ft_isonlycharset.c ft_strpbrk.c ft_strdupfree.c \
	ft_putstr.c ft_error.c ft_strprepend.c ft_strcspn.c ft_striteri.c \
	ft_memccpy.c ft_substr.c ft_tolower.c ft_strdup_no_c.c ft_strequ.c \
	ft_strcut_free.c ft_strlen.c ft_memcpy.c ft_strtrim.c ft_itoa_hexa.c \
	ft_strlen_without.c ft_memchr.c ft_count_elems.c ft_calloc.c ft_putnbr.c \
	ft_strdel.c ft_intlen.c ft_isalpha.c ft_isascii.c ft_strnstr.c ft_strjoin.c \
	ft_memalloc.c ft_memset.c ft_putendl_fd.c ft_i_abs.c ft_isalnum.c \
	ft_strisdigit.c ft_strrchr.c ft_itoa_octa.c ft_strclr.c ft_f_abs.c ft_strncmp.c \
	ft_strjoinfre.c ft_f_roof.c ft_is_white_space.c ft_split.c ft_toupper.c ft_memcmp.c \
	ft_utoa_base.c ft_strappend.c ft_atoi.c ft_putchar_fd.c ft_putstr_fd.c ft_valid_base.c \
	ft_itoa_unsigned_deci.c ft_strlcpy.c ft_strcat.c ft_tab_free.c ft_strcpy.c ft_bzero.c \
	ft_memmove.c ft_strndup.c ft_strnequ.c ft_f_round.c ft_itoa_base.c ft_seglen.c ft_strncpy.c \
	ft_putendl.c ft_strlcat.c ft_putnbr_fd.c ft_striter.c ft_i_roof.c ft_padding.c ft_get_leaks.c \
	ft_strndupfree.c ft_isnotonlycharset.c ft_strnlen.c ft_uintmaxlen_base.c ft_tab_len.c ft_strstr.c \
	ft_strncat.c ft_isprint.c ft_strrev.c ft_strmapi.c get_next_line.c get_next_line_utils.c \
	s_handler.c p_handler.c mod_handler.c i_handler.c o_handler.c u_handler.c x_handler.c \
	style_handler.c c_handler.c v_handler.c d_handler.c xx_handler.c ft_vdprintf.c \
	ft_printf.c formatter.c parser.c

OBJ		= $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

# Compilation flag
CFLAGS = -Wall -Wextra -Werror

IFLAGS = $(foreach dir, $(INC_DIR), -I$(dir))

LFLAGS		=	$(foreach dir, $(LIB_DIR), -L $(dir)) \
				$(foreach lib, $(LIB), -l $(lib))
# Colors

_GREY=	$'\e[30m
_RED=	$'\e[31m
_GREEN=	$'\e[32m
_YELLOW=$'\e[33m
_BLUE=	$'\e[34m
_PURPLE=$'\e[35m
_CYAN=	$'\e[36m
_WHITE=	$'\e[37m

all:
				@echo "\n$(_BLUE)___$(NAME) Setting___\n$(_WHITE)"
				@make $(NAME)

show:
				@echo "$(_BLUE)SRC :\n$(_YELLOW)$(SRC)$(_WHITE)"
				@echo "$(_BLUE)OBJ :\n$(_YELLOW)$(OBJ)$(_WHITE)"
				@echo "$(_BLUE)CFLAGS :\n$(_YELLOW)$(CFLAGS)$(_WHITE)"
				@echo "$(_BLUE)IFLAGS :\n$(_YELLOW)$(IFLAGS)$(_WHITE)"
				@echo "$(_BLUE)LFLAGS :\n$(_YELLOW)$(LFLAGS)$(_WHITE)"

$(OBJ_DIR)/%.o : %.c
				@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
				@echo "$(_GREEN)DONE$(_WHITE)"

$(NAME): 		$(OBJ)
				@echo "-----\nCreating library $(_YELLOW)$@$(_WHITE) ... \c"
				@ar -rc $(NAME) $(OBJ)
				@ranlib $(NAME)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

re:				fclean all

clean:
				@echo "$(_WHITE)Deleting Objects Directory $(_YELLOW)$(OBJ_DIR)$(_WHITE) ... \c"
				@$(foreach file, $(OBJ), rm -rf $(file))
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

fclean:			clean
				@echo "Deleting Binary File $(_YELLOW)$(NAME)$(_WHITE) ... \c"
				@rm -f $(NAME)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

.PHONY: all clean flcean re show