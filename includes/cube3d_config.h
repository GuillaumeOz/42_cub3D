/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_config.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 10:40:05 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/03 11:31:24 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_CONFIG_H
# define CUBE3D_CONFIG_H

typedef struct	s_config
{
	char		*title;
	t_vector	*resolution_size;
	t_player	*player;

	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;

	char		*sprite_texture;

	t_color		*floor;
	t_color		*ceiling;

	char		**map;
}				t_config;

t_config	*malloc_config(void);
t_config	create_config(void);
void		destroy_config(t_config to_destroy);
void		free_config(t_config *to_free);

void		parse_resolution(t_vector *resolution_size, char *format);
void		parse_texture(char **texture, char *format);
void		parse_environment(t_color *environment, char *format);
void		check_border_player(t_config *data);

char		*cube_map_parse(t_config *data, char *line, int line_counter);
t_config	*cube_formatter(char *title, char *map_name);

#endif