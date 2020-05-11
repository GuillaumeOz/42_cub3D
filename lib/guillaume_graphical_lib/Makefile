# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/09 13:12:46 by gozsertt          #+#    #+#              #
#    Updated: 2020/05/10 19:30:34 by gozsertt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libgg.a
MLXNAME	= libmlx_Linux.a

CC		= gcc

SRC_DIR = $(shell find srcs -type d)
INC_DIR = $(shell find includes -type d)
LIB_DIR = mlx
OBJ_DIR = obj

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

# List de toute les library a linker au projet (le nom - le lib et - le .a)

SRC		= color.c vector2_list_destructors.c vector4.c vector2.c vector3.c \
		vector2_list_creators.c vector2_list_behavior.c vector2_handling.c \
		vector2_normalize.c ggl_error.c application_handling.c application_behavior.c \
		application.c draw_rectangle.c draw_line.c draw_circle.c calc_line.c angle_functions.c \
		images_destructors.c image.c images_constructors.c ggl_list2.c ggl_list.c ggl_putchar.c \
		ggl_strcat.c ggl_strdup.c ggl_get_leaks.c ggl_putstr.c ggl_strlen.c ggl_strjoin.c \
		ggl_strnew.c basic_convert.c

# MACOS change MLX .m file into .o
# OBJ2	= $(OBJ1:%.m=%.o)

OBJ		= $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

# Compilation flag
CFLAGS	=	-Wall -Wextra -Werror

IFLAGS	=	$(foreach dir, $(INC_DIR), -I$(dir))

LFLAGS	= 	$(foreach dir, $(LIB_DIR), -L $(dir)) \
			$(foreach lib, $(LIB), -l $(lib))
			#$(foreach framework, $(FRAMEWORK), -framework $(framework))

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

$(NAME): 		$(OBJ)
				@echo "-----\nCreating Graphical library $(_YELLOW)$@$(_WHITE) ... \c"
				@ar -rcs $(NAME) $(OBJ)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"
				@echo "\n-----\nCreating MLX library $(_YELLOW)$(MLXNAME)$(_WHITE) ... \n"
				@make -C lib/mlx all
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

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

$(MLX_OBJ_DIR)/%.o : %.c
				@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
				@mkdir -p $(MLX_OBJ_DIR)
				@$(CC) -Wno-deprecated-declarations $(IFLAGS) -o $@ -c $<
				@echo "$(_GREEN)DONE$(_WHITE)"

# MACOS rule for change MLX .m file into .o
#$(OBJ_DIR)/%.o : %.m
#				@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
#				@mkdir -p $(OBJ_DIR)
#				@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
#				@echo "$(_GREEN)DONE$(_WHITE)"

re:				fclean all

clean:
				@echo "$(_WHITE)Deleting Objects Directory $(_YELLOW)$(OBJ_DIR)$(_WHITE) ... \c"
				@$(foreach file, $(OBJ), rm -rf $(file))
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

fclean:			clean
				@echo "Deleting Graphical Binary File $(_YELLOW)$(NAME)$(_WHITE) ... \n"
				@rm -f $(NAME)
				@echo "Deleting Graphical MLX Binary File $(_YELLOW)$(MLXNAME)$(_WHITE) ... \n"
				@make -C lib/mlx clean
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

.PHONY: all re show clean flcean
