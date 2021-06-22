/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_t_sprite.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:36:31 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/20 15:44:55 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_T_SPRITE_H
# define CUB3D_T_SPRITE_H

typedef enum e_sprite_id
{
	BASIC,
}				t_sprite_id;

typedef struct s_sprite_list
{
	t_sprite_id		id;
	t_float_vector2	coord;
	double			dist;
	double			sprite_width_axis;
	double			sprite_height_axis;
	double			sprite_z_axis;
	int				sprite_width;
	int				sprite_height;
	int				sprite_z;
	float			fog_war;
	int				animation;
	bool			enable;
}					t_sprite_list;

typedef struct s_sprite
{
	t_application	*app;
	char			*path;
	t_sprite_id		sprite_id;
	t_int_vector2	tex_resolution;
	void			*img_ptr;
	int				*pixels;
	int				bits_per_pixels;
	int				size_line;
	int				endian;
}					t_sprite;

t_sprite_list	*malloc_sprite_list(t_sprite_id id, t_double_vector2 coord);
t_sprite_list	create_sprite_list(t_sprite_id id, t_double_vector2 coord);
void			free_sprite_list(t_list *to_free);

t_sprite_id		get_sprite_list_id(t_list *sprite_list, int i);
t_float_vector2	get_sprite_list_coord(t_list *sprite_list, int i);
double			get_sprite_list_dist(t_list *sprite_list, int i);
bool			get_sprite_list_enable(t_list *sprite_list, int i);

void			set_sprite_list_width_axis(t_list *sprite_list,
					int i, double value);
void			set_sprite_list_height_axis(t_list *sprite_list,
					int i, double value);
void			set_sprite_list_z_axis(t_list *sprite_list,
					int i, double value);
void			set_sprite_list_id(t_list *sprite_list, int i, bool value);
void			set_sprite_list_dist(t_list *sprite_list, int i, double value);

t_sprite		*malloc_sprite(t_application *app,
					char *path, t_sprite_id sprite_id);
t_sprite		create_sprite(t_application *app,
					char *path, t_sprite_id sprite_id);
void			destroy_sprite(t_sprite to_destroy);
void			free_sprite(t_sprite *to_free);

#endif
