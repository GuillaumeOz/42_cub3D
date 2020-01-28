# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/28 13:23:39 by gozsertt          #+#    #+#              #
#    Updated: 2020/01/28 20:01:04 by gozsertt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =   libcube3d.a

CC          =   gcc

MLX_DIR		= 	$(shell find lib/mlx -type d)
LIB_DIR		=	$(shell find lib/libft -type d)
SRC_DIR		= 	$(shell find srcs -type d)
INC_DIR		= 	$(shell find includes -type d) $(shell find lib/mlx -type d)	\
	$(shell find lib/libft/includes -type d)
OBJ_DIR		=	obj
MLX_OBJ_DIR =	mlx_obj

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):) $(foreach dir, $(MLX_DIR), $(dir):)
vpath %.m $(foreach dir, $(MLX_DIR), $(dir):)

# List of all of the library linked to the project (the name without the lib part and without the .a)
FRAMEWORK = OpenGL AppKit
LIB = #libft

SRC = $(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.c), $(notdir $(file))))

MLX_SRC 	=	mlx_init_loop.m		\
	mlx_int_str_to_wordtab.c			\
	mlx_mouse.m			\
	mlx_new_image.m		\
	mlx_new_window.m	\
	mlx_png.c			\
	mlx_shaders.c		\
	mlx_xpm.c			\
	#mlx_opengl.m			A SUPPR?	\

MLX_OBJ = $(addprefix $(MLX_OBJ_DIR)/, $(OBJ1:%.m=%.o))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

# Compilation flags

CFLAGS      = -Wall -Wextra -Werror #-fsanitize=address

IFLAGS		=	$(foreach dir, $(INC_DIR), -I$(dir))

LFLAGS		=	$(foreach dir, $(SRC_DIR), -L $(dir)) $(foreach lib, $(LIB), -l $(lib) ) $(foreach framework, $(FRAMEWORK), -framework $(framework) )

# Colors

_GREY=	$'\x1b[30m
_RED=	$'\x1b[31m
_GREEN=	$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=	$'\x1b[34m
_PURPLE=$'\x1b[35m
_CYAN=	$'\x1b[36m
_WHITE=	$'\x1b[37m

# MAIN part --------------------------------------------------------

install:
	@make -C libs/libft && make all

re-install:
	@make -C libs/libft re && make re

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

$(MLX_OBJ_DIR)/%.o : %.c
	@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
	@mkdir -p $(MLX_OBJ_DIR)
	@$(CC) -Wno-deprecated-declarations $(IFLAGS) -o $@ -c $<
	@echo "$(_GREEN)DONE$(_WHITE)"

$(MLX_OBJ_DIR)/%.o : %.m
	@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
	@mkdir -p $(OBJ_DIR)
	@$(CC) -Wno-deprecated-declarations $(IFLAGS) -o $@ -c $<
	@echo "$(_GREEN)DONE$(_WHITE)"

$(NAME):        $(MLX_OBJ) $(OBJ) Makefile
	@echo "-----\nCreating library $(_YELLOW)$@$(_WHITE) ... \c"
	@ar -rc $(NAME) $(OBJ) $(MLX_OBJ)
	@ranlib $(NAME)
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

debug:			$(MLX_OBJ) $(OBJ) $(NAME) cube3d.c
	@echo "Creating Binary File $(_YELLOW)$@$(_WHITE) ... \c"
	@$(CC) $(CFLAGS) $(IFLAGS) cube3d.c -o debug $(LFLAGS) -L . -l cube3d
	@echo "$(_GREEN)DONE$(_WHITE)\n"
	@echo "Execution !\n-----"
	@./debug

re:	fclean all

mlx_clean:
	@echo "$(_WHITE)Deleting MLX Objects $(_YELLOW)$(OBJ_DIR)$(_WHITE) ... \c"
	@$(foreach file, $(MLX_OBJ), rm -rf $(file))
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"
clean:
	@echo "$(_WHITE)Deleting Objects Directory $(_YELLOW)$(OBJ_DIR)$(_WHITE) ... \c"
	@$(foreach file, $(OBJ), rm -rf $(file))
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

fclean:			clean mlx_clean
	@echo "Deleting Binary File $(_YELLOW)$(NAME)$(_WHITE) ... \c"
	@$(shell make fclean -C lib/libft)
	@rm -f $(NAME)
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

nh :
	@echo && echo "$(_GREEN)" "Checking Norme -- Header Files:" && echo "$(_WHITE)";
	@norminette $(shell find includes/ -name '*.h')

nc :
	@echo && echo "$(_GREEN)" "Checking Norme -- Libft Files:" && echo "$(_WHITE)";
	@norminette $(shell find lib/libft/ -name '*.c')
	@echo && echo "$(_GREEN)" "Checking Norme -- Source Files:" && echo "$(_WHITE)";
	@norminette $(shell find srcs/ -name '*.c') cube3d.c

na : nh nc

.PHONY: all clean flcean re show exec nh nc na