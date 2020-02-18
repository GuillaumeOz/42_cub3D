/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_parsing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 19:33:03 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/18 15:42:34 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_PARSING_H
# define CUBE3D_PARSING_H

bool    set_texture_image(t_game_engine *engine, t_direction dir, char *path);
bool    set_sprite_image(t_game_engine *engine, char *path);
bool    set_color_type(t_game_engine *engine, int type, char *content);

bool    parse_resolution(char *descriptor, char *content, t_vector2 *resolution);
bool    parse_environement_color(t_game_engine *engine, char *descriptor, char *content);
bool    parse_environement_texture(t_game_engine *engine, char *descriptor, char *content);
bool    is_engine_full(t_game_engine *engine);
void    parse_game_engine(t_game_engine *engine, int fd, t_vector2 *resolution);

void    parse_map(t_game_engine *engine, int fd);
void    parse_game_engine(t_game_engine *engine, int fd, t_vector2 *resolution);

void    cube3d_parsing(t_game_engine *engine, char *map_name, t_vector2 *resolution);
#endif
