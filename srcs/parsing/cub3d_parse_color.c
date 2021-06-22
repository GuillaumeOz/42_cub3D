/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:06:46 by gozsertt          #+#    #+#             */
/*   Updated: 2021/06/20 19:14:07 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	count_comma(char *line, size_t i)
{
	int	count;

	count = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ',')
			count++;
		i++;
	}
	if (count > 2)
		cub3d_error(ERROR_PARSING24,
			"Too many comma between some color");
}

static t_color	*get_color(char *red, char *green, char *blue)
{
	t_color	*color;
	int		r_color;
	int		g_color;
	int		b_color;

	if (ft_strlen(red) > 3 || ft_strlen(green) > 3
		|| ft_strlen(blue) > 3)
		cub3d_error(ERROR_PARSING21, "Each Color must be composed by 3 digit");
	r_color = ft_atoi(red);
	g_color = ft_atoi(green);
	b_color = ft_atoi(blue);
	if (r_color < 0 || g_color < 0 || b_color < 0)
		cub3d_error(ERROR_PARSING22, "A Color cannot be negative");
	if (r_color > 255 || g_color > 255 || b_color > 255)
		cub3d_error(ERROR_PARSING23, "A Color cannot be grater than 255");
	color = malloc_color(r_color, g_color, b_color, 255);
	return (color);
}

static	void	parse_ceiling_color(t_engine *engine, char *line)
{
	char	**tab;
	size_t	i;

	i = ft_strskip(line, ' ');
	if (line[i] == '\0')
		cub3d_error(ERROR_PARSING25, "C informations is missing");
	tab = ft_split(line + i, ',');
	if (ft_tab_len(tab) != 3)
		cub3d_error(ERROR_PARSING20, "Bad number of parameter for C Color");
	i = -1;
	while (tab[++i] != NULL)
		if (ft_strisdigit(tab[i]) == false)
			cub3d_error(ERROR_PARSING21, "C Color must be only digits");
	engine->ceiling = get_color(tab[0], tab[1], tab[2]);
	ft_tab_free(tab);
}

static	void	parse_floor_color(t_engine *engine, char *line)
{
	char	**tab;
	size_t	i;

	i = ft_strskip(line, ' ');
	if (line[i] == '\0')
		cub3d_error(ERROR_PARSING25, "F informations is missing");
	tab = ft_split(line + i, ',');
	if (ft_tab_len(tab) != 3)
		cub3d_error(ERROR_PARSING20, "Bad number of parameter for F Color");
	i = -1;
	while (tab[++i] != NULL)
		if (ft_strisdigit(tab[i]) == false)
			cub3d_error(ERROR_PARSING21, "F Color must be only digits");
	engine->floor = get_color(tab[0], tab[1], tab[2]);
	ft_tab_free(tab);
}

void	parse_color(t_engine *engine, char *line, char *id)
{
	size_t	i;

	if (ft_strcmp(id, "F") == true)
		parse_floor_color(engine, line);
	else if (ft_strcmp(id, "C") == true)
		parse_ceiling_color(engine, line);
	i = ft_strskip(line, ' ');
	count_comma(line, i);
}
