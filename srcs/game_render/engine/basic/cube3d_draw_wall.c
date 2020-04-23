/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 12:52:06 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/23 15:58:36 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void			*multhread_calcul_height(void *ptr)
{
	t_multithread_struct	*object;
	float					act_pixel;
	t_ray					info;
	int						i;
	t_sprites				*lst_sprite;

	object = ((void **)ptr)[1];
	lst_sprite = NULL;
	i = object->nb_to_draw - 1;
	while (i >= 0)
	{
		act_pixel = ((float)object->hero->fov / object->map->size.x) *
														(object->num_pixel + i);
		info.angle = degree_to_radian((float)object->hero->fov / 2 - act_pixel);
		info.ray = create_vector2(object->hero->forward.x * cos(info.angle) -
		object->hero->forward.y * sin(info.angle),
		object->hero->forward.x * sin(info.angle) + object->hero->forward.y *
		cos(info.angle));
		info.column = (object->nb_to_draw - i) + ((1 - object->index - 1) *
		object->nb_to_draw);
		test_check(&info, *(object->hero), *(object->map), &lst_sprite);
		check_ray(info, *(object->hero), *(object->map), &lst_sprite);
		object->lst[object->num_pixel + i--] = info.pos;
	}
	return (NULL);
}

static t_vector2	*calcul_height(t_player hero, t_map *map)
{
	t_vector2				*lst;
	float					nb_to_draw;
	t_multithread_struct	object[1];
	void					*ptr[1][2];
	int						i;

	i = 0;
	lst = (t_vector2*)malloc(sizeof(t_vector2) * map->size.x);//check if we must change x and y
	if (lst == NULL)
		return (NULL);
	nb_to_draw = map->size.x / ((float)1);
	object[i] = create_multithread_struct(&hero, map, lst);
	set_multithread_struct_value(&(object[i]), (int)(i * nb_to_draw),
		nb_to_draw);
	set_multithread_struct_index(&(object[i]), i);
	ptr[i][1] = &(object[i]);
	multhread_calcul_height(ptr);
	return (lst);
}

void				draw_wall(t_player hero, t_map *map)
{
	t_vector2 *lst;

	hero.forward = create_vector2(hero.forward.x - hero.pos.x,
		hero.forward.y - hero.pos.y);
	hero.forward = normalize_vector2(hero.forward);
	hero.right.x = hero.forward.x * cos(PI / 2) - hero.forward.y * sin(PI / 2);
	hero.right.y = hero.forward.x * sin(PI / 2) + hero.forward.y * cos(PI / 2);
	lst = calcul_height(hero, map);
	free(lst);
}
