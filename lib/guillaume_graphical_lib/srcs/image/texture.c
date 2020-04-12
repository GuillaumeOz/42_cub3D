/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 15:52:56 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/12 22:23:37 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ggl.h"

int **malloc_tex_tab(t_image *image)
{
	int	**result;
	size_t i;

	i = 0;
    result = (int**)malloc(sizeof(int*) * image->size.y + 1);
		if (result == NULL)
			ggl_error("Error 1\n Can't malloc int** in malloc_tex_tab");
    result[(int)image->size.y] = NULL;
    while (i < image->size.y)
	{
		result[i] = create_tex_tab(image);
		i++;
	}
	return (result);
}

int	*create_tex_tab(t_image *image)
{
	int		*result;
	size_t	i;
	size_t	j;

	result = (int*)malloc(sizeof(int) * (image->size.x + 1));
	if (result == NULL)
		ggl_error("Error 1\n Can't malloc int** in malloc_tex_tab");
	result[(int)image->size.x] = '\0';
	i = 0;
	j = 0;
	while (i < image->size.x)
	{
		result[i] |= image->pixels[j + BLUE_COMP];
		result[i] = (result[i] << 8);
		result[i] |= image->pixels[j + GREEN_COMP];
		result[i] = (result[i] << 8);
		result[i] |= image->pixels[j + RED_COMP];
		result[i] = (result[i] << 8);
		result[i] |= image->pixels[j + ALPHA_COMP];
		i++;
		j += 4;
	}
	return (result);
}

void    destroy_tex_tab(int **to_destroy)
{
    (void)to_destroy;
}

void    free_tax_tab(t_image *to_free)
{
    size_t i;
    
    i = 0;
    destroy_tex_tab(to_free->tex_tab);
    while (i < to_free->size.y)
    {
        free(to_free->tex_tab[i]);
    }
    free(to_free->tex_tab);
}

void put_tex_pix(t_image *image, t_vector2 pos, int tex_pixel)
{
    int pixel_index;

    if (pos.x < 0 || pos.x >= image->size.x || pos.y < 0 ||
		pos.y >= image->size.y)
        return;
    pixel_index = (pos.y * image->size.x + pos.x) * 4;
    image->pixels[pixel_index + ALPHA_COMP] |= tex_pixel;
    tex_pixel = (tex_pixel >> 8);
    image->pixels[pixel_index + RED_COMP] |= tex_pixel;
    tex_pixel = (tex_pixel >> 8);
    image->pixels[pixel_index + GREEN_COMP] |= tex_pixel;
    tex_pixel = (tex_pixel >> 8);
    image->pixels[pixel_index + BLUE_COMP] |= tex_pixel;
    // apply the distance for the fog
}
