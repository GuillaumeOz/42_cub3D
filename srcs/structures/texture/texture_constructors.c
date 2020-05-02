/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_constructors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 14:48:15 by gozsertt          #+#    #+#             */
/*   Updated: 2020/05/01 16:12:31 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_texture			create_texture(char *path)
{
	t_texture	result;
	void		*img_tmp;

	result.tex = NULL;
	result.path = NULL;
	if (path != NULL)
	{
		if ((img_tmp = mlx_xpm_file_to_image(g_app->mlx_ptr,
			path, &result.width, &result.height)) == NULL)
			catch_error(CREATE_TEXTURE_1);
		result.tex = mlx_get_data_addr(img_tmp, &result.bits_per_pixel,
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
