/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse_resolution_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:02:03 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/20 17:33:33 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	resize_to_min(int *res_x, int *res_y)
{
	int	min_x;
	int	min_y;

	min_x = 300;
	min_y = 300;
	if (*res_x < min_x)
	{
		ft_warning("The width resolution was \
			too small, for better consistency, it will \
			be adjusted width to 300 pxl.");
		*res_x = min_x;
	}
	if (*res_y < min_y)
	{
		ft_warning("The height resolution was \
			too small, for better consistency, it will \
			be adjusted height to 300 pxl.");
		*res_y = min_y;
	}
}

static void	resize_to_max(t_application *app, int *res_x, int *res_y)
{
	int	screen_x;
	int	screen_y;

	mlx_get_screen_size(app->mlx_ptr, &screen_x, &screen_y);
	if (*res_x > screen_x)
	{
		ft_warning("The width resolution was \
			too large, so it will be adjusted to the screen width.");
		*res_x = screen_x;
	}
	if (*res_y > screen_y)
	{
		ft_warning("The height resolution was \
			too large, so it will be adjusted to the screen height.");
		*res_y = screen_y;
	}
}

static void	get_resolution_size(t_application *app, char **tab,
		int *res_x, int *res_y)
{
	size_t	res_x_len;
	size_t	res_y_len;

	res_x_len = ft_strlen(tab[0]);
	if (res_x_len >= 10)
		*res_x = INT_MAX;
	else
		*res_x = ft_atoi(tab[0]);
	res_y_len = ft_strlen(tab[1]);
	if (res_y_len >= 10)
		*res_y = INT_MAX;
	else
		*res_y = ft_atoi(tab[1]);
	resize_to_max(app, res_x, res_y);
	resize_to_min(res_x, res_y);
}

static void	count_space(char *line, int i)
{
	int	count;

	count = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			count++;
		i++;
	}
	if (count > 1)
		cub3d_error(ERROR_PARSING19,
			"Too many space between width and height resolution");
}

void	parse_resolution_bonus(t_engine *engine, char *line)
{
	char	**tab;
	int		res_x;
	int		res_y;
	size_t	i;

	tab = ft_split(line, ' ');
	if (ft_tab_len(tab) != 2)
		cub3d_error(ERROR_PARSING15, "Bad number of parameter for Resolution");
	i = -1;
	while (tab[++i] != NULL)
		if (ft_strisdigit(tab[i]) == false)
			cub3d_error(ERROR_PARSING16, "Resolution must be only digits");
	get_resolution_size(engine->app, tab, &res_x, &res_y);
	engine->resolution = create_int_vector2(res_x, res_y);
	ft_tab_free(tab);
	i = ft_strskip(line, ' ');
	count_space(line, i);
	set_engine_wall_limit(engine);
	engine->bonus |= RESOLUTION_BONUS;
}
