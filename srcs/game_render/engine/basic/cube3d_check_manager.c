/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_check_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 12:52:28 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/24 12:44:50 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int			condition5(t_ray info, t_map map, t_sprites **lst_sprite,
																t_player hero)
{
	int			x;
	int			y;
	t_vector2	position;
	t_sprites	*new;

	type_initializer(&x, &y, info, hero);
	if (map.board[x][y]->type == sprite)
	{
		position = create_vector2((x + 0.5) * hero.size, (y + 0.5) * hero.size);
		info.pos = calc_inter(hero.pos, info.ray, position, hero.right);
		if (vector2_distance(info.pos, position) > hero.size / 2)
			return (0);
		new = malloc_sprites(info, position, sprite);
		new->next = *lst_sprite;
		*lst_sprite = new;
		return (0);
	}
	else if (map.board[x][y]->type == door)
		return (3);
	else if (map.board[x][y]->type == level)
		return (4);
	return (0);
}

static int			condition4(t_ray info, t_map map, t_sprites **lst_sprite,
																t_player hero)
{
	int			x;
	int			y;
	t_vector2	position;
	t_sprites	*new;

	type_initializer(&x, &y, info, hero);
	if (map.board[x][y]->type == monster)
	{
		position = create_vector2((x + 0.5) * hero.size, (y + 0.5) * hero.size);
		info.pos = calc_inter(hero.pos, info.ray, position, hero.right);
		if (vector2_distance(info.pos, position) > hero.size / 2)
			return (0);
		new = malloc_sprites(info, position, monster);
		new->next = *lst_sprite;
		*lst_sprite = new;
		return (0);
	}
	else
		return (condition5(info, map, lst_sprite, hero));
	return (0);
}

static int			condition3(t_ray info, t_map map, t_sprites **lst_sprite,
																t_player hero)
{
	int			x;
	int			y;
	t_vector2	position;
	t_sprites	*new;

	type_initializer(&x, &y, info, hero);
	if (map.board[x][y]->type == medikit)
	{
		position = create_vector2((x + 0.5) * hero.size, (y + 0.5) * hero.size);
		info.pos = calc_inter(hero.pos, info.ray, position, hero.right);
		if (vector2_distance(info.pos, position) > hero.size / 2)
			return (0);
		new = malloc_sprites(info, position, medikit);
		new->next = *lst_sprite;
		*lst_sprite = new;
		return (0);
	}
	else
		return (condition4(info, map, lst_sprite, hero));
	return (0);
}

static int			condition2(t_ray info, t_map map, t_sprites **lst_sprite,
																t_player hero)
{
	int			x;
	int			y;
	t_vector2	position;
	t_sprites	*new;

	type_initializer(&x, &y, info, hero);
	if (map.board[x][y]->type == dead_monster)
	{
		position = create_vector2((x + 0.5) * hero.size, (y + 0.5) * hero.size);
		info.pos = calc_inter(hero.pos, info.ray, position, hero.right);
		if (vector2_distance(info.pos, position) > hero.size / 2)
			return (0);
		new = malloc_sprites(info, position, dead_monster);
		new->next = *lst_sprite;
		*lst_sprite = new;
		return (0);
	}
	else
		return (condition3(info, map, lst_sprite, hero));
	return (0);
}

int					type_condition(t_ray info, t_map map,
										t_sprites **lst_sprite, t_player hero)
{
	int			x;
	int			y;

	type_initializer(&x, &y, info, hero);
	if (map.board[x][y]->type == wall)
		return (1);
	else
		return (condition2(info, map, lst_sprite, hero));
	return (0);
}
