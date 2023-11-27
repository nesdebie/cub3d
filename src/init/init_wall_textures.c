/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wall_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:18:46 by nesdebie          #+#    #+#             */
/*   Updated: 2023/11/27 11:18:54 by nesdebie         ###   ########.fr       */
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
	game->tx.n = xpm_to_img(game, game->tx.no);
	if (!game->tx.n)
		return (1);
	game->tx.s = xpm_to_img(game, game->tx.so);
	if (!game->tx.s)
		return (1);
	game->tx.e = xpm_to_img(game, game->tx.ea);
	if (!game->tx.e)
		return (1);
	game->tx.w = xpm_to_img(game, game->tx.we);
	if (!game->tx.w)
		return (1);
	game->tx.d = xpm_to_img(game, "./img/porte-bleu.xpm");
	if (!game->tx.d)
		return (1);
	return (0);
}
