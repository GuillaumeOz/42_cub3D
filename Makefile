# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/28 13:23:39 by gozsertt          #+#    #+#              #
#    Updated: 2020/05/11 12:33:49 by gozsertt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =   cub3D

CC          =   gcc

MLX_DIR		= 	$(shell find lib/guillaume_graphical_lib -type d)
SRC_DIR		= 	$(shell find srcs -type d)
INC_DIR		= 	$(shell find includes -type d) \
				$(shell find lib/guillaume_graphical_lib -type d) \
				$(shell find lib/guillaume_graphical_lib/lib -type d) \
				$(shell find lib/libft/includes -type d)
LIB_DIR		=	lib/libft lib/guillaume_graphical_lib \
				lib/guillaume_graphical_lib/lib/mlx
OBJ_DIR		=	obj

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

# MACOS framework
# FRAMEWORK = OpenGL AppKit
# LINUX Flags
LINUXFLAG	=	-lm -lX11 -lXext -lpthread

# List of all of the library linked to the project (the name without the lib part and without the .a)
LIB			=	ft gg mlx_Linux

SRC			= 	cub3d.c controlers_utils.c controlers.c cub3d_event_manager.c \
		cub3d_catch_error.c cub3d_draw_wall_multi_thread.c \
		cub3d_check_manager_utils.c cub3d_draw_sprite.c cub3d_draw_block.c \
		cub3d_check_manager.c cub3d_draw_wall.c cub3d_draw_2d_map.c \
		cub3d_draw_hud.c cub3d_draw_health.c cub3d_draw_game_over.c \
		cub3d_draw_gun.c game_engine_builder.c map_checker.c \
		parse_game_engine_bonus.c parse_game_engine.c cub3d_parsing.c \
		parse_map.c game_engine_constructors.c tile.c game_engine_destructors.c \
		cub3d_draw_constructor.c cub3d_draw_seter.c cub3d_draw_destructor.c \
		player_behavior.c player_constructors.c monster.c player_destructors.c \
		medikit.c ray_destructors.c ray_constructors.c texture_constructors.c \
		texture_destructors.c map_destructors.c map_constructors.c \
		cub3d_multithread_creators.c cub3d_multithread_destructors.c save.c \
		sprites_constructors.c sprites_destructors.c

OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

# Compilation flags

CFLAGS      =	-Wall -Wextra -Werror #-fsanitize=address -g3

IFLAGS		=	$(foreach dir, $(INC_DIR), -I $(dir))

LFLAGS		=	$(foreach dir, $(LIB_DIR), -L $(dir)) \
				$(foreach lib, $(LIB), -l $(lib)) \
				$(LINUXFLAG)

# MACOS framework	
# $(foreach framework, $(FRAMEWORK), -framework $(framework))

# Colors

_GREY=	$'\e[30m
_RED=	$'\e[31m
_GREEN=	$'\e[32m
_YELLOW=$'\e[33m
_BLUE=	$'\e[34m
_PURPLE=$'\e[35m
_CYAN=	$'\e[36m
_WHITE=	$'\e[37m

# MAIN part --------------------------------------------------------

all:
	@echo "\n$(_BLUE)___$(NAME) Setting___\n$(_WHITE)"
	@make $(NAME)

show:
	@echo "$(_BLUE)SRC :\n$(_YELLOW)$(SRC)$(_WHITE)"
	@echo "$(_BLUE)OBJ :\n$(_YELLOW)$(OBJ)$(_WHITE)"
	@echo "$(_BLUE)CFLAGS :\n$(_YELLOW)$(CFLAGS)$(_WHITE)"
	@echo "$(_BLUE)IFLAGS :\n$(_YELLOW)$(IFLAGS)$(_WHITE)"
	@echo "$(_BLUE)LFLAGS :\n$(_YELLOW)$(LFLAGS)$(_WHITE)"
	@echo "$(_BLUE)LIB_DIR :\n$(_YELLOW)$(LIB_DIR)$(_WHITE)"
	@echo "\n-----\n"
	@echo "$(_BLUE)Compiling : \n$(_YELLOW)$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)$(_WHITE)"

install:
	@$(foreach dir, $(LIB_DIR), make -C $(dir);)

re-install:
	@$(foreach dir, $(LIB_DIR), make -C $(dir) re;)

fclean-install:
	@$(foreach dir, $(LIB_DIR), make -C $(dir) fclean;)

$(NAME): install $(OBJ)
	@echo "-----\nCreating Binary File $(_YELLOW)$@$(_WHITE) ... \c"
	@$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

$(OBJ_DIR)/%.o : %.c
	@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
	@echo "$(_GREEN)DONE$(_WHITE)"

re:	fclean all

clean:
	@echo "$(_WHITE)Deleting Objects Directory $(_YELLOW)$(OBJ_DIR)$(_WHITE) ... \c"
	@$(foreach file, $(OBJ), rm -rf $(file))
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

fclean:	clean
	@echo "Deleting Binary File $(_YELLOW)$(NAME)$(_WHITE) ... \c"
	@rm -f $(NAME)
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

.PHONY: all show install re-install re clean flcean