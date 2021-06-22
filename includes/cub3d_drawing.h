/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_drawing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:49:44 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/21 19:58:24 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DRAWING_H
# define CUB3D_DRAWING_H

/*
** Floor functions
*/

void	floor_texture_render_bonus(t_floor_calc floor_calc,
			t_engine *engine, int x, int y);
void	ceiling_texture_render_bonus(t_floor_calc floor_calc,
			t_engine *engine, int x, int y);
void	floor_ceiling_texture_render_bonus(t_engine *engine,
			t_player *player, t_floor_calc floor_calc);
void	ceiling_color_render(t_engine *engine);
void	floor_color_render(t_engine *engine);

void	floor_ceiling_render(t_engine *engine, t_player *player);

/*
** Wall functions
*/

void	set_wall_color(t_engine *engine, t_wall_calc *wall_calc,
			t_color *color);
void	set_update_tex_pos(t_wall_calc *wall_calc);
void	set_tex_y_limit(t_wall_calc *wall_calc, t_engine *engine);
void	set_tex_pos(t_wall_calc *wall_calc, t_engine *engine);
void	set_tex_step(t_wall_calc *wall_calc, t_engine *engine);
void	set_tex_x_from_wall_x(t_wall_calc *wall_calc, t_engine *engine);
void	set_wall_x(t_wall_calc *wall_calc, t_player *player);
void	set_draw_start_end(t_wall_calc *wall_calc, t_engine *engine);
void	set_line_height(t_wall_calc *wall_calc, t_engine *engine);

void	wall_drawing(t_wall_calc *wall_calc, t_engine *engine,
			t_player *player, int x);

void	set_euclidean_wall_dist(t_wall_calc *wall_calc, t_player *player);
bool	set_dda_calc(t_wall_calc *wall_calc, t_engine *engine);
void	set_side_dist(t_wall_calc *wall_calc, t_player *player);
void	set_delta_dist(t_wall_calc *wall_calc);
void	set_map_pos(t_wall_calc *wall_calc, t_player *player);
void	set_ray_dir(t_wall_calc *wall_calc, t_player *player);
void	set_camera_x(t_wall_calc *wall_calc, t_engine *engine, int x);

void	wall_render(t_engine *engine, t_player *player);

/*
** Sprite functions
*/

bool	apply_z_axis_limit(t_sprite_calc *sprite_calc,
			t_sprite_list *current_sprite, float value);
bool	it_is_z_axis_limit(t_sprite_calc *sprite_calc,
			t_sprite_list *current_sprite);
bool	texel_is_displayable(t_sprite_calc *sprite_calc,
			t_sprite_list *current_sprite, t_sprite *sprite_tex);
void	stripe_drawing(t_sprite_calc *sprite_calc, t_engine *engine,
			t_sprite_list *current_sprite, t_sprite *sprite_tex);
void	sprite_drawing(t_sprite_calc *sprite_calc, t_engine *engine,
			t_sprite_list *current_sprite, t_sprite	*sprite_tex);

void	set_sprite_axis_transformation(t_sprite_calc *sprite_calc,
			t_engine *engine, t_sprite_list *current_sprite);
void	set_sprite_screen_x(t_sprite_calc *sprite_calc, t_engine *engine);
void	set_inv_camera_matrice_transformation(t_sprite_calc *sprite_calc,
			t_player *player);
void	set_sprite_pos_compared_to_player(t_sprite_calc *sprite_calc,
			t_engine *engine, t_player *player, int i);

void	sprite_calculation(t_sprite_calc *sprite_calc,
			t_engine *engine, t_player *player, int i);

void	apply_sprite_height_transformation(t_engine *engine,
			t_player *player, int i);
void	apply_sprite_width_transformation(t_engine *engine,
			t_player *player, int i);
void	apply_sprite_z_transformation(t_engine *engine,
			t_player *player, int i);
void	apply_sprite_axis_transformation(t_engine *engine,
			t_player *player, int i);

void	swap_order(t_sprite_calc *sprite_calc, int i);
void	swap_dist(t_sprite_calc *sprite_calc, int i);
void	sort_dist_order(t_sprite_calc *sprite_calc, t_engine *engine);
void	set_dist_order(t_sprite_calc *sprite_calc, t_engine *engine);

void	sprite_render_bonus(t_engine *engine, t_player *player);

/*
** Time functions
*/

void	time_render(t_engine *engine, t_player *player);

/*
** Minimap functions
*/

void	put_minimap_pixel_bonus(t_application *app,
			 int x, int y, t_color color);

void	minimap_secret_door_color_selector_bonus(t_color *color, char c);

void	set_minimap_circle_informations_bonus(t_application *app,
			float *radius, t_float_vector2 *circle);

void	draw_minimap_player_bonus(t_application *app);

void	draw_minimap_square_bonus(t_engine *engine, t_color color,
			int x, int y);

void	set_minimap_background_bonus(t_engine *engine);

void	minimap_render_bonus(t_engine *engine, t_player *player);

/*
** Secret Door functions
*/

bool	put_diamond_block_bonus(t_wall_calc *secret_door, t_engine *engine);

bool	find_diamond_block_bonus(t_wall_calc *secret_door, t_engine *engine);

void	secret_door_render_bonus(t_engine *engine, t_player *player);

#endif
