/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_t_wall_calc.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:12:53 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/17 19:28:57 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_T_WALL_CALC_H
# define CUB3D_T_WALL_CALC_H

typedef struct s_wall_calc
{
	char				*map;
	double				camera_x;
	t_int_vector2		map_pos;
	t_double_vector2	ray_dir;
	t_double_vector2	side_dist;
	t_double_vector2	delta_dist;
	t_int_vector2		step;
	t_texture_id		id;
	double				wall_dist;
	int					line_height;
	int					draw_start;
	int					draw_end;
	double				wall_x;
	t_int_vector2		tex;
	double				tex_step;
	double				tex_pos;
	float				fog_war;
	bool				hit;
	char				hit_char;
}				t_wall_calc;

t_wall_calc		*malloc_wall_calc(void);
t_wall_calc		create_wall_calc(void);
void			destroy_wall_calc(t_wall_calc to_destroy);
void			free_wall_calc(t_wall_calc *to_free);

#endif
