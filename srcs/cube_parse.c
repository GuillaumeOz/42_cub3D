/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 09:36:58 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/31 17:59:27 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	parse_resolution(t_vector *resolution, char *format)
{
	int i;
	int j;

	i = 1;
	j = 0;
	if (format[i] == ' ')
		while (format[i] == ' ')
			i++;
	resolution->x = ft_atoi(format + i);
	while (format[i] != ' ')
		i++;
	while (format[i] == ' ')
		i++;
	resolution->y = ft_atoi(format + i);
	while (format[i] && format[i] != ' ')
		i++;
	j = i;
	while (format[i])
		i++;
	if (i != j)
		catch_error(PARSE_RESOLUTION_1);
}

void	parse_texture(char **texture, char *format)
{
	int i;
	int j;

	i = 2;
	j = 0;
	if (format[i] == ' ')
		while (format[i] == ' ')
			i++;
	while (format[i + j] && format[i + j] != ' ')
		j++;
	*texture = ft_strndup(format + i, j);
	j += i;
	while (format[i])
		i++;
	if (i != j)
		catch_error(PARSE_TEXTURE_1);
}

void	parse_environment(t_color *environment, char *format)
{
	int i;
	int j;

	i = 1;
	j = 0;
	if (format[i] == ' ')
		while (format[i] == ' ')
			i++;
	environment->r = ft_atoi(format + i);
	while (format[i] != ',')
		i++;
	i++;
	environment->g = ft_atoi(format + i);
	while (format[i] != ',')
		i++;
	i++;
	environment->b = ft_atoi(format + i);
	while (format[i] && format[i] != ' ')
		i++;
	j = i;
	while (format[i])
		i++;
	if (i != j)
		catch_error(PARSE_ENVIRONMENT_1);
}
