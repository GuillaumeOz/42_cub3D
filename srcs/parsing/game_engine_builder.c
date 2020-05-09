/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_engine_builder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:41:26 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/09 20:36:09 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_resolution(t_vector2 *res)
{
	int			test_size_x;
	int			test_size_y;

	test_size_x = 0;
	test_size_y = 0;
	mlx_get_screen_size(g_app->mlx_ptr, &test_size_x, &test_size_y);
	res->y = (res->y > test_size_y) ? test_size_y : res->y;
	res->y = (res->y < 1) ? 1 : res->y;
	res->x = (res->x > test_size_x) ? test_size_x : res->x;
	res->x = (res->x < 1) ? 1 : res->x;
}

bool	set_texture_image(t_game_engine *engine, t_direction dir, char *path)
{
	int i;

	i = 0;
	if ((dir == west && engine->texture[west] != NULL) ||
		(dir == north && engine->texture[north] != NULL) ||
		(dir == east && engine->texture[east] != NULL) ||
		(dir == south && engine->texture[south] != NULL))
		catch_error(SET_TEXTURE_IMAGE_1);
	while (path[i] && path[i] == ' ')
		i++;
	if (path[i] == '\0')
		catch_error(SET_TEXTURE_IMAGE_2);
	engine->texture[(int)(dir)] = malloc_texture(path + i);
	return (true);
}

bool	set_sprite_image(t_game_engine *engine, char *path)
{
	int i;

	i = 0;
	if (engine->sprite != NULL)
		catch_error(SET_SPRITE_IMAGE_1);
	while (path[i] && path[i] == ' ')
		i++;
	if (path[i] == '\0')
		catch_error(SET_SPRITE_IMAGE_2);
	engine->sprite = malloc_texture(path + i);
	return (true);
}

static void	color_checker(char *r_str, char *g_str, char *b_str)
{
	int	r_color;
	int	g_color;
	int	b_color;

	if (ft_strisdigit(r_str) == false || ft_strisdigit(g_str) == false ||
	ft_strisdigit(b_str) == false)
		catch_error(COLOR_CHECKER_1);
	if (ft_strlen(r_str) >= 10 || ft_strlen(g_str) >= 10 ||
	ft_strlen(b_str) >= 10)
		catch_error(COLOR_CHECKER_1);
	r_color = ft_atoi(r_str);
	g_color = ft_atoi(g_str);
	b_color = ft_atoi(b_str);
	if (r_color < 0 || g_color < 0 || b_color < 0)
		catch_error(COLOR_CHECKER_1);
	if (r_color > 255 || g_color > 255 || b_color > 255)
		catch_error(COLOR_CHECKER_1);
}

bool	set_color_type(t_game_engine *engine, int type, char *content)
{
	char	**tab;
	t_color *color;
	int		i;

	if ((type == CEILING && engine->ceiling != NULL) ||
		(type == FLOOR && engine->floor != NULL))
		catch_error(SET_COLOR_TYPE_1);
	tab = ft_split(content, ',');
	if (ft_tab_len(tab) != 3)
		catch_error(SET_COLOR_TYPE_2);
	i = -1;
	while (tab[++i] != NULL)
		if ((ft_strisdigit(tab[i])) == false)
			catch_error(SET_COLOR_TYPE_3);
	color_checker(tab[0], tab[1], tab[2]);
	color = malloc_color(ft_atoi(tab[0]), ft_atoi(tab[1]),
	ft_atoi(tab[2]), 255);
	ft_tab_free(tab);
	if (type == CEILING)
		engine->ceiling = color;
	else if (type == FLOOR)
		engine->floor = color;
	return (true);
}
