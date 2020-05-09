/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_constructors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 14:48:15 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/09 17:42:47 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture			create_texture(char *path)
{
	t_texture	result;

	result.tex = NULL;
	result.path = NULL;
	if (path != NULL)
	{
		if ((result.img_ptr = mlx_xpm_file_to_image(g_app->mlx_ptr,
			path, &result.width, &result.height)) == NULL)
			catch_error(CREATE_TEXTURE_1);
		result.tex = mlx_get_data_addr(result.img_ptr, &result.bits_per_pixel,
										&result.size_line, &result.endian);
		result.path = ft_strdup(path);
	}
	return (result);
}

t_texture			*malloc_texture(char *path)
{
	t_texture *result;

	result = (t_texture*)malloc(sizeof(t_texture));
	if (result == NULL)
		catch_error(MALLOC_TEXTURE_1);
	*result = create_texture(path);
	return (result);
}
