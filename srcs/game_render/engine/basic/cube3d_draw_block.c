/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d_draw_block.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 12:52:21 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/24 16:28:58 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void		loop_draw_column(t_block_data b_inf, t_draw inf_draw)
{
	b_inf.x = b_inf.info.pos.x / inf_draw.hero.size;
	b_inf.y = b_inf.info.pos.y / inf_draw.hero.size;
	if (b_inf.info.fuck_float == 'x')
		b_inf.column = (int)((b_inf.y - (int)b_inf.y) * b_inf.act.width) *
												(b_inf.act.bits_per_pixel / 8);
	else
		b_inf.column = (int)((b_inf.x - (int)b_inf.x) * b_inf.act.width) *
												(b_inf.act.bits_per_pixel / 8);
	b_inf.num = 0;
	b_inf.i = b_inf.column;
	while (b_inf.num + inf_draw.start.y < inf_draw.end.y &&
		(inf_draw.end.y - b_inf.num >= 0 &&
		inf_draw.start.y + b_inf.num <= inf_draw.map.resolution.y))
	{
		b_inf.pos = create_vector2(inf_draw.start.x, inf_draw.start.y +
																	b_inf.num);
		b_inf.color = create_color(b_inf.act.tex[b_inf.i + 2],
			b_inf.act.tex[b_inf.i + 1], b_inf.act.tex[b_inf.i], inf_draw.alpha);
		put_pixel(g_app->image, b_inf.pos, b_inf.color);
		b_inf.num++;
		b_inf.i = ((int)((b_inf.num / (inf_draw.end.y - inf_draw.start.y)) *
				b_inf.act.height) * b_inf.act.width *
				(b_inf.act.bits_per_pixel / 8)) + b_inf.column;
	}
}

static void		its_a_wall(t_block_data *b_inf, t_draw inf_draw)
{
	if (b_inf->info.fuck_float == 'x')
	{
		if (b_inf->info.ray.x > 0)
			b_inf->act = *(inf_draw.map.board[0][0]->texture[west]);
		else
			b_inf->act = *(inf_draw.map.board[0][0]->texture[east]);
	}
	else
	{
		if (b_inf->info.ray.y > 0)
			b_inf->act = *(inf_draw.map.board[0][0]->texture[north]);
		else
			b_inf->act = *(inf_draw.map.board[0][0]->texture[south]);
	}
}

void			draw_column_block(t_draw inf_draw, t_tile_type type)
{
	static t_texture	end;
	static int			first = 1;
	t_block_data		b_inf;

	b_inf.info = *(t_ray*)(inf_draw.info);
	if (first == 1)
	{
		end = create_texture("./textures/end.xpm");
		first = 0;
	}
	if (type == wall)
		its_a_wall(&b_inf, inf_draw);
	else if (type == door)
		b_inf.act = inf_draw.map.board[0][0]->door;
	else if (type == level)
		b_inf.act = end;
	loop_draw_column(b_inf, inf_draw);
}
