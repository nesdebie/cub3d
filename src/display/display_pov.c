/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_pov.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:06:33 by nesdebie          #+#    #+#             */
/*   Updated: 2023/11/15 14:41:02 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_image_pixel(t_img *image, int x, int y, int color)
{
	int	pixel;

	pixel = y * (image->size_line / 4) + x;
	image->addr[pixel] = color;
}

static void	set_frame_image_pixel(t_game *game, t_img *image, int x, int y)
{
	if (game->pixels[y][x] > 0)
		set_image_pixel(image, x, y, game->pixels[y][x]);
	else if (y < Y / 2)
		set_image_pixel(image, x, y, game->sprites.c_rgb);
	else if (y < Y - 1)
		set_image_pixel(image, x, y, game->sprites.f_rgb);
}

static void	render_frame(t_game *game)
{
	t_img	image;
	int		x;
	int		y;

	image.img = NULL;
	init_img(game, &image, X, Y);
	y = 0;
	while (y < Y)
	{
		x = 0;
		while (x < X)
		{
			set_frame_image_pixel(game, &image, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, image.img, 0, 0);
	mlx_destroy_image(game->mlx, image.img);
}

void	display_pov(t_game *game)
{
	init_pixels(game);
	init_pov(&game->ray);
	raycasting(&game->player, game);
	render_frame(game);
}
