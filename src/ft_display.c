/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo < hubrygo@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:39:09 by hubrygo           #+#    #+#             */
/*   Updated: 2023/10/18 17:45:57 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_draw_player(t_game *game, float pdx, float pdy)
{
	(void)pdx;
	(void)pdy;
	int rgb[3];
	int	x;
	int y;
	float	dx;
	float 	dy;
    int color;

	rgb[0] = 255;
    rgb[1] = 255;
    rgb[2] = 0;
	color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];

	x = -5;
	while (x < 5)
	{
		y = -5;
		while (y < 5)
		{
			mlx_pixel_put(game->mlx, game->win, game->player.px + x, game->player.py + y, color);
			y++;
		}
		x++;
	}
	rgb[0] = 0;
    rgb[1] = 0;
    rgb[2] = 255;
	color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	mlx_pixel_put(game->mlx, game->win, game->player.px, game->player.py, color);
	dx = 0;
	while (dx < pdx)
	{
		dy = 0;
		while (dy < pdy)
		{
			mlx_pixel_put(game->mlx, game->win, game->player.px + x, game->player.py + y, color);
			dy += 0.1;
		}
		dx += 0.1;
	}
}

void	draw_map(t_game *game)
{
	int rgb[3];
	int	x;
	int y;
    int color;

	rgb[0] = 128;
    rgb[1] = 128;
    rgb[2] = 128;
	color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	x = 0;
	while (x < 100)
	{
		y = 0;
		while (y < 60)
		{
			mlx_pixel_put(game->mlx, game->win, x, y, color);
			y++;
		}
		x++;
	}
}

void	ft_erase_player(t_game *game)
{
	int rgb[3];
    int color;
	int	x;
	int	y;
	
	rgb[0] = 0;
	rgb[1] = 0;
	rgb[2] = 0;
	color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	x = -5;
	while (x < 5)
	{
		y = -5;
		while (y < 5)
		{
			mlx_pixel_put(game->mlx, game->win, game->player.px + x, game->player.py + y, color);
			y++;
		}
		x++;
	}
}
