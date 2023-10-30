/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo < hubrygo@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:39:09 by hubrygo           #+#    #+#             */
/*   Updated: 2023/10/30 16:05:00 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_draw_player(t_game *game, float pdx, float pdy)
{
	int	x;
	int	y;
	int	color;

	color = (100 << 24) | (255 << 16) | (255 << 8) | 0;
	x = -6;
	while (++x < 5)
	{
		y = -6;
		while (++y < 5)
			mlx_pixel_put(game->img, game->win, game->player.px + x, \
							game->player.py + y, color);
	}
	mlx_pixel_put(game->img, game->win, game->player.px, \
					game->player.py, color);
	while (++x < 16) // longueur
	{
		mlx_pixel_put(game->img, game->win, game->player.px + pdy, \
						game->player.py + pdx, color);
		pdx += cos(game->player.dir) * 2;
		pdy += sin(game->player.dir) * 2;
	}
}

void	set_image_pixel2(t_img *image, int x, int y)
{
	int	pixel;
	int	color;
	
	color = (200 << 24 ) | (0 << 16) | (0 << 8) | 0;
	pixel = y * (image->size_line / 4) + x;
	image->addr[pixel] = color;
}

void	create_wall(t_game *game)
{
	t_img	wall;
	int		y;
	int		x;
	int		i;
	int		j;

	y = 19;
	x = 19;
	wall.img = NULL;
	init_img(game, &wall, x, y);
	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			set_image_pixel2(&wall, i, j);
			j++;
		}
		i++;
	}
	game->wall = wall;
}

void	draw_map(t_game *game)
{
	int		i;
	int		j;
	static int	start = 0;

	if (start == 0)
	{
		create_wall(game);
		start++;
	}
	//printf("test\n");
	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall.img, (i * 20) + 250, (j * 20) + 200);
			j++;
		}
		i++;
	}
}
