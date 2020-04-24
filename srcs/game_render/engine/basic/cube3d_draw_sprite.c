/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_draw_sprite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 12:52:14 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/24 16:30:58 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int		check_side(t_draw inf_draw, t_sprites sprite,
												t_texture act, float percent)
{
	int		column;

	column = 0;
	if ((inf_draw.hero.forward.x >= 0 &&
		inf_draw.hero.forward.y >= 0 && sprite.ray.pos.x - sprite.pos.x <= 0 &&
		sprite.ray.pos.y - sprite.pos.y >= 0) ||
		(inf_draw.hero.forward.x <= 0 && inf_draw.hero.forward.y >= 0 &&
		sprite.ray.pos.x - sprite.pos.x <= 0 &&
		sprite.ray.pos.y - sprite.pos.y <= 0) ||
		(inf_draw.hero.forward.x >= 0 && inf_draw.hero.forward.y <= 0 &&
		sprite.ray.pos.x - sprite.pos.x >= 0 &&
		sprite.ray.pos.y - sprite.pos.y >= 0) ||
		(inf_draw.hero.forward.x <= 0 && inf_draw.hero.forward.y <= 0 &&
		sprite.ray.pos.x - sprite.pos.x >= 0 &&
		sprite.ray.pos.y - sprite.pos.y <= 0))
		return (column = (int)((0.5f + percent) * act.width) *
													(act.bits_per_pixel / 8));
	else
		return (column = (int)((0.5f - percent) * act.width) *
													(act.bits_per_pixel / 8));
}

void			draw_many_sprite(t_map map, t_sprites **lst_sprite,
													t_player hero, t_ray info)
{
	float		result;
	float		pixel_b;
	float		pixel_h;
	t_draw		act;
	t_sprites	*next;

	act = create_draw(map, hero, *lst_sprite, 1);
	result = vector2_distance(hero.pos, (*lst_sprite)->ray.pos);
	result *= cos(info.angle);
	result = ((map.resolution.y * 0.4f) * 10.0f) / result;
	pixel_h = (map.resolution.y / 2.0f) - (result / 2.0f);
	pixel_b = (map.resolution.y / 2.0f) + (result / 2.0f);
	set_draw_point(&act, pixel_h, pixel_b, info.column);
	draw_column_sprite(act);
	next = (*lst_sprite)->next;
	free((*lst_sprite));
	(*lst_sprite) = next;
}

static void		loop_draw_sprite(t_sprite_data s_inf, t_draw inf_draw)
{
	while (s_inf.num + inf_draw.start.y < inf_draw.end.y &&
		(inf_draw.end.y - s_inf.num > 0 &&
		inf_draw.start.y + s_inf.num < inf_draw.map.resolution.y))
	{
		s_inf.pos = create_vector2(inf_draw.start.x,
												inf_draw.start.y + s_inf.num);
		if (s_inf.act.tex[s_inf.i + 2] != 0 ||
			s_inf.act.tex[s_inf.i + 1] != 0 || s_inf.act.tex[s_inf.i] != 0)
		{
			s_inf.color = create_color(s_inf.act.tex[s_inf.i + 2],
				s_inf.act.tex[s_inf.i + 1], s_inf.act.tex[s_inf.i],
																inf_draw.alpha);
			s_inf.dark = create_color(0, 0, 0, 255);
			s_inf.color = fuze_color(s_inf.dark, s_inf.color);
			put_pixel(g_app->image, s_inf.pos, s_inf.color);
		}
		s_inf.num++;
		s_inf.i = ((int)((s_inf.num / (inf_draw.end.y - inf_draw.start.y)) *
			s_inf.act.height) * s_inf.act.width *
								(s_inf.act.bits_per_pixel / 8)) + s_inf.column;
	}
}

void			draw_column_sprite(t_draw inf_draw)
{
	t_sprite_data		s_inf;

	s_inf.act = create_texture(NULL);
	s_inf.sprite = *(t_sprites*)inf_draw.info;
	if (s_inf.sprite.type == sprite)
		s_inf.act = inf_draw.map.board[0][0]->sprite;
	else if (s_inf.sprite.type == monster)
		s_inf.act = inf_draw.map.board[0][0]->monster.life;
	else if (s_inf.sprite.type == dead_monster)
		s_inf.act = inf_draw.map.board[0][0]->monster.dead;
	else if (s_inf.sprite.type == medikit)
		s_inf.act = inf_draw.map.board[0][0]->medikit.tex;
	s_inf.percent = vector2_distance(s_inf.sprite.ray.pos, s_inf.sprite.pos)
														/ inf_draw.hero.size;
	s_inf.column = check_side(inf_draw, s_inf.sprite, s_inf.act, s_inf.percent);
	s_inf.num = 0;
	s_inf.i = s_inf.column;
	loop_draw_sprite(s_inf, inf_draw);
}
