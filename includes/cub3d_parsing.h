/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parsing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 19:33:03 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/08 17:50:45 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSING_H
# define CUB3D_PARSING_H

bool	set_thread_option(t_game_engine *engine);
bool	set_monster_image(t_game_engine *engine, char *path);
bool	set_medikit_image(t_game_engine *engine, char *path);
bool	set_door_image(t_game_engine *engine, char *path);
bool	set_level_image(t_game_engine *engine, char *path);
bool	set_texture_image(t_game_engine *engine, t_direction dir, char *path);
bool	set_sprite_image(t_game_engine *engine, char *path);
bool	set_color_type(t_game_engine *engine, int type, char *content);

bool	parse_environement_color(t_game_engine *engine,
			char *descriptor, char *content);
bool	parse_environement_texture(t_game_engine *engine,
			char *descriptor, char *content);
void	parse_game_engine(t_game_engine *engine,
			int fd, t_vector2 *resolution);
void	get_resolution(t_vector2 *resolution);
bool	parse_resolution(char *descriptor,
			char *content, t_vector2 *resolution);
void	parse_map(t_game_engine *engine, int fd);
void	parse_game_engine(t_game_engine *engine, int fd, t_vector2 *resolution);

bool	is_engine_full(t_game_engine *engine, t_vector2 *resolution);
void	**malloc_param_tab(void **param);
void	cub3d_parsing(t_game_engine *engine, int argc,
			char **argv, t_vector2 *resolution);

#endif
