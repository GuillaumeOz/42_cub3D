# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 14:46:10 by gozsertt          #+#    #+#              #
#    Updated: 2021/06/21 16:09:43 by gozsertt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        	=   cub3D

CC          	=   gcc

SRC_DIR			= 	$(shell find srcs -type d)
INC_DIR			= 	$(shell find includes -type d) \
					$(shell find lib/mlx -type d) \
					$(shell find lib/libft/includes -type d)
LIB_DIR			=	lib/libft lib/mlx
OBJ_DIR			=	obj

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

LINUXFLAG	=	-lm -lX11 -lXext

# library -----------------------------------------------------------

LIB			=	ft mlx_Linux

SRC			= 	cub3d.c   cub3d_application.c  cub3d_application_handler.c cub3d_application_pixels.c   cub3d_error.c   cub3d_save_bmp.c			\
				cub3d_put_diamond_block_bonus.c cub3d_find_diamond_block_bonus.c cub3d_secret_door_render_bonus.c									\
				cub3d_draw_minimap_square_bonus.c cub3d_put_minimap_pixel_bonus.c  cub3d_draw_minimap_player.c										\
				cub3d_set_minimap_circle_informations_bonus.c cub3d_minimap_secret_door_color_selector_bonus.c										\
				cub3d_set_minimap_background_bonus.c  cub3d_minimap_render_bonus.c cub3d_sprite_casting.c cub3d_sprite_calculation.c				\
				cub3d_sprite_drawing.c cub3d_set_dist_order.c  cub3d_set_sprite_pos_compared_to_player.c											\
				cub3d_set_sprite_screen_x.c  cub3d_set_inv_camera_matrice_transformation.c cub3d_sprite_display_limit.c								\
				cub3d_apply_sprite_axis_transformation.c cub3d_set_sprite_axis_transformation_bonus.c  cub3d_stripe_drawing.c						\
				cub3d_time_casting.c   cub3d_floor_texture_render_bonus.c cub3d_ceiling_texture_render_bonus.c										\
				cub3d_floor_ceiling_texture_render_bonus.c cub3d_floor_color_render.c  cub3d_floor_ceiling_casting.c								\
				cub3d_ceiling_color_render.c cub3d_set_tex_coord_from_wall_x.c  cub3d_set_delta_dist.c  cub3d_set_euclidean_wall_dist.c				\
				cub3d_set_tex_step.c  cub3d_set_update_tex_pos.c  cub3d_set_side_dist.c  cub3d_set_wall_x.c											\
				cub3d_set_ray_dir.c  cub3d_set_draw_start_end.c  cub3d_set_camera_x.c  cub3d_set_tex_y_limit.c										\
				cub3d_set_tex_pos.c  cub3d_set_line_height.c  cub3d_wall_casting.c  cub3d_wall_drawing.c											\
				cub3d_set_wall_color.c  cub3d_set_dda_calc.c  cub3d_set_map_pos.c     cub3d_texture.c												\
				cub3d_floor_calc.c   cub3d_image.c   cub3d_sprite_list.c  cub3d_sprite_calc.c  cub3d_sprite.c										\
				cub3d_sprite_list_getter.c  cub3d_sprite_list_setter.c   cub3d_time_getter.c  cub3d_time.c											\
				cub3d_time_setter.c   cub3d_color.c  cub3d_color_manipulation.c   cub3d_bmp_bitmap.c												\
				cub3d_wall_calc.c   cub3d_player.c   cub3d_engine.c   cub3d_engine_setter.c															\
				cub3d_camera_mouse_move_bonus.c  cub3d_camera_keyboard_move.c  cub3d_sprite_transformation_bonus.c									\
				cub3d_key_press.c  cub3d_player_move.c  cub3d_event_manager.c  cub3d_hitbox.c  cub3d_camera_move.c									\
				cub3d_key_release.c   cub3d_routine.c   cub3d_parse_texture.c  cub3d_double_id_checker_bonus.c										\
				cub3d_id_checker.c  cub3d_load_secret_door_bonus.c  cub3d_parse_bonus.c  cub3d_id_checker_bonus.c									\
				cub3d_analyse_map.c  cub3d_parse_ceiling_floor_texture_bonus.c  cub3d_parse_map.c  cub3d_parse_color.c								\
				cub3d_check_arguments.c  cub3d_parse_secret_door_bonus.c  cub3d_load_player.c  cub3d_parse_sprite_basic_bonus.c						\
				cub3d_parsing.c  cub3d_parse_engine.c  cub3d_parse_resolution_bonus.c  cub3d_load_map_informations.c  cub3d_load_sprite_basic.c		\

OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

OBJ_BONUS	=	$(addprefix $(OBJ_DIR_BONUS)/, $(SRC:%.c=%.o))

# Compilation flags -------------------------------------------------

CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address -g3

D_NO_BONUS  =	-DBONUS=0

D_BONUS		=	-DBONUS=1

IFLAGS		=	$(foreach dir, $(INC_DIR), -I $(dir))

LFLAGS		=	$(foreach dir, $(LIB_DIR), -L $(dir)) \
				$(foreach lib, $(LIB), -l $(lib)) \
				$(LINUXFLAG)

# Colors ------------------------------------------------------------

_GREY	=	$'\e[30m
_RED	=	$'\e[31m
_GREEN	=	$'\e[32m
_YELLOW	=	$'\e[33m
_BLUE	=	$'\e[34m
_PURPLE	=	$'\e[35m
_CYAN	=	$'\e[36m
_WHITE	=	$'\e[37m

# main part ---------------------------------------------------------

all:
	@echo "\n$(_BLUE)___$(NAME) Setting___\n$(_WHITE)"
	@make BONUS=$(D_NO_BONUS) $(NAME)

bonus: fclean
	@echo "\n$(_BLUE)___$(NAME) Setting___\n$(_WHITE)"
	@make BONUS=$(D_BONUS) $(NAME)

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
	@$(CC) $(CFLAGS) $(BONUS) $(OBJ) $(LFLAGS) -o $(NAME)
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

$(OBJ_DIR)/%.o : %.c
	@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(BONUS) $(IFLAGS) -o $@ -c $<
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

.PHONY: all bonus show install re-install re clean flcean