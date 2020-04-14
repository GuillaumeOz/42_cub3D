/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 15:52:56 by gozsertt          #+#    #+#             */
/*   Updated: 2020/04/13 20:25:08 by gozsertt         ###   ########.fr       */
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

// if (result[i] == image->pixels[j + BLUE_COMP])
// {
// 	printf("%s\n", "SUCESS");
// 	exit(0);
// }
// printf("%d\n", image->pixels[j + BLUE_COMP]);

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
		result[i] |= (int)image->pixels[j + BLUE_COMP];
		result[i] = (result[i] << 8);
		result[i] |= (int)image->pixels[j + GREEN_COMP];
		result[i] = (result[i] << 8);
		result[i] |= (int)image->pixels[j + RED_COMP];
		result[i] = (result[i] << 8);
		result[i] |= (int)image->pixels[j + ALPHA_COMP];
		// printf("%d\n", (char)result[i]);
		// printf("%d\n", (char)result[i] >> 24);
		// printf("%d\n", (char)result[i] >> 16);
		// printf("%d\n", (char)result[i] >> 8);
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

//color = (x*255)/w+((((w-x)*255)/w)<<16)+(((y*255)/h)<<8);
//	  mlx_pixel_put(mlx,win,x,y,color);
// 	image->pixels[pixel_index] = tex_pixel;

	// pixel_index = (pos.y * image->size.x + pos.x) * 4;
    // image->pixels[pixel_index + ALPHA_COMP] |= (char)tex_pixel;
	//printf("%c\n", image->pixels[pixel_index + ALPHA_COMP]);
    // tex_pixel = (tex_pixel >> 8);
    // image->pixels[pixel_index + RED_COMP] |= (char)tex_pixel;
	//printf("%c\n", image->pixels[pixel_index + RED_COMP]);
    // tex_pixel = (tex_pixel >> 8);
    // image->pixels[pixel_index + GREEN_COMP] |= (char)tex_pixel;
	//printf("%c\n", image->pixels[pixel_index + GREEN_COMP]);
    // tex_pixel = (tex_pixel >> 8);
    // image->pixels[pixel_index + BLUE_COMP] |= (char)tex_pixel;
	//printf("%c\n", image->pixels[pixel_index + BLUE_COMP]);
	// exit(0);
    // apply the distance for the fog

void put_tex_pix(t_image *image, t_vector2 pos, t_color tex_pix)
{
	t_color actual;
	t_color tmp;
	int pixel_index;

	if (pos.x < 0 || pos.x >= image->size.x || pos.y < 0 ||
		pos.y >= image->size.y)
		return;
	pixel_index = (pos.y * image->size.x + pos.x) * 4;
	actual = create_color(
		image->pixels[pixel_index + RED_COMP],
		image->pixels[pixel_index + GREEN_COMP],
		image->pixels[pixel_index + BLUE_COMP],
		255
	);
	tmp = fuze_color(actual, tex_pix);
	image->pixels[pixel_index + RED_COMP] = tmp.r;
	image->pixels[pixel_index + GREEN_COMP] = tmp.g;
	image->pixels[pixel_index + BLUE_COMP] = tmp.b;
}
