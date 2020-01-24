/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_config.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 10:40:05 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/24 13:59:48 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_CONFIG
# define CUBE3D_CONFIG

typedef struct	s_config
{
	char		*title;
	t_vector	*resolution_size;

	char		player_stance;
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

void		parse_resolution(t_vector **resolution_size, char *format);
void		parse_texture(char **texture, char *format);
void		parse_environment(t_color **environment, char *format);

t_config	*formatter(char *title);

#endif