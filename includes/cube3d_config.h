/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_config.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 10:40:05 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/09 17:48:16 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_CONFIG
# define CUBE3D_CONFIG

typedef struct	s_config
{
	char		*title;
	t_vector	*resolution_size;
	
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;

	char		*sprite_texture;

	t_color		*floor;
	t_color		*ceiling;

	char		**map;
}				t_config;

t_config	*malloc_map_data(void);
t_config	create_map_data(void);
void		destroy_map_data(t_config to_destroy);
void		free_map_data(t_config *to_free);

t_config	*formatter(char *title);



#endif