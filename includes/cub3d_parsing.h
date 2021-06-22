/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parsing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:24:19 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/17 19:31:12 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSING_H
# define CUB3D_PARSING_H

void	parse_secret_door_bonus(t_engine *engine, char *line);
void	parse_floor_texture_bonus(t_engine *engine, char *line);
void	parse_ceiling_texture_bonus(t_engine *engine, char *line);
void	parse_sprite_basic_bonus(t_engine *engine, char *line);
void	parse_resolution_bonus(t_engine *engine, char *line);

bool	it_is_secret_door_bonus(t_engine *engine, char *id);
bool	it_is_floor_texture_bonus(t_engine *engine, char *id);
bool	it_is_ceiling_texture_bonus(t_engine *engine, char *id);
bool	it_is_sprite_basic_bonus(t_engine *engine, char *id);
bool	it_is_resolution_bonus(t_engine *engine, char *id);

bool	it_is_bonus(char *id);

void	parse_bonus(t_engine *engine, char *line, char *id, int i);

void	load_secret_door_bonus(t_engine *engine);
void	load_sprite_basic(t_engine *engine, t_sprite_id id, int x, int y);
void	load_player(t_engine *engine, char direction, int x, int y);

void	load_map_informations(t_engine *engine, int size_x, int size_y);

void	analyse_map(t_engine *engine, int size_x, int size_y);

void	parse_map(t_engine *engine, int fd);

void	parse_texture(t_engine *engine, char *line, t_texture_id direction);
void	parse_color(t_engine *engine, char *line, char *id);

bool	it_is_texture(t_engine *engine, char *id, t_texture_id *direction);
bool	it_is_color(t_engine *engine, char *id);

void	parse_engine(t_engine *engine, int fd);

void	check_arguments(t_engine *engine, int argc, char **argv);
void	parsing(t_engine *engine, int argc, char **argv);

#endif
