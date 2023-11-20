/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wall_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo < hubrygo@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:18:46 by nesdebie          #+#    #+#             */
/*   Updated: 2023/11/20 12:02:02 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_img_clean(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->pixel_bits = 0;
	img->size_line = 0;
	img->endian = 0;
}

static int	init_texture_img(t_game *game, t_img *image, char *path)
{
	int	size;

	size = SIZE;
	init_img_clean(image);
	image->img = mlx_xpm_file_to_image(game->mlx, path, &size, &size);
	if (image->img == NULL)
		return (error_msg(MLX_XPM));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return (0);
}

static int	*xpm_to_img(t_game *game, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	if (init_texture_img(game, &tmp, path))
		return (NULL);
	buffer = ft_calloc(1, sizeof * buffer * SIZE * SIZE);
	if (!buffer)
	{
		error_msg(MALLOC_ERROR);
		return (NULL);
	}
	y = -1;
	while (++y < SIZE)
	{
		x = -1;
		while (++x < SIZE)
			buffer[y * SIZE + x] = tmp.addr[y * SIZE + x];
	}
	mlx_destroy_image(game->mlx, tmp.img);
	return (buffer);
}

int	init_wall_textures(t_game *game)
{
	game->sprites.n = xpm_to_img(game, game->sprites.no);
	if (!game->sprites.n)
		return (1);
	game->sprites.s = xpm_to_img(game, game->sprites.so);
	if (!game->sprites.s)
		return (1);
	game->sprites.e = xpm_to_img(game, game->sprites.ea);
	if (!game->sprites.e)
		return (1);
	game->sprites.w = xpm_to_img(game, game->sprites.we);
	if (!game->sprites.w)
		return (1);
	game->sprites.d = xpm_to_img(game, "./img/porte-bleu.xpm");
	if (!game->sprites.d)
		return (1);
	return (0);
}
