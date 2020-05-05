/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_wall_multi_thread.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 12:51:59 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/05 17:01:39 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void				*multhread_calcul_height(void *ptr)
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
		act_pixel = ((float)object->hero->fov / object->map->resolution.x) *
			(object->num_pixel + i);
		info.angle = degree_to_radian((float)object->hero->fov /
			2.0f - act_pixel);
		info.ray = create_vector2(object->hero->forward.x * cos(info.angle) -
			object->hero->forward.y * sin(info.angle), object->hero->forward.x *
			sin(info.angle) + object->hero->forward.y * cos(info.angle));
		info.column = (object->nb_to_draw - i) +
			((NB_THREAD - object->index - 1) * object->nb_to_draw);
		test_check(&info, *(object->hero), *(object->map), &lst_sprite);
		check_ray(info, *(object->hero), *(object->map), &lst_sprite);
		object->lst[object->num_pixel + i--] = info.pos;
	}
	return (NULL);
}

static t_vector2		*calcul_height(t_player hero, t_map *map)
{
	t_calcul_h_data			c_inf;

	c_inf.lst = malloc(sizeof(t_vector2) * map->resolution.x);
	if (c_inf.lst == NULL)
		return (NULL);
	c_inf.nb_to_draw = map->resolution.x / ((float)NB_THREAD);
	c_inf.i = 0;
	while (c_inf.i < NB_THREAD)
	{
		c_inf.object[c_inf.i] = create_multithread_struct(&hero, map,
			c_inf.lst);
		set_multithread_struct_value(&(c_inf.object[c_inf.i]),
			(int)(c_inf.i * c_inf.nb_to_draw), c_inf.nb_to_draw);
		set_multithread_struct_index(&(c_inf.object[c_inf.i]), c_inf.i);
		c_inf.ptr[c_inf.i][1] = &(c_inf.object[c_inf.i]);
		pthread_create(&(c_inf.thread_list[c_inf.i]), NULL,
			multhread_calcul_height, &(c_inf.ptr[c_inf.i]));
		c_inf.i++;
	}
	c_inf.i = 0;
	while (c_inf.i < NB_THREAD)
		pthread_join(c_inf.thread_list[c_inf.i++], NULL);
	return (c_inf.lst);
}

void					draw_wall_multi_thread(t_player hero, t_map *map)
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
