/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo < hubrygo@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:39:09 by hubrygo           #+#    #+#             */
/*   Updated: 2023/10/19 12:44:08 by hubrygo          ###   ########.fr       */
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
	int	i;
	int	j;
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
	j = pdx;
	i = pdy;
	mlx_pixel_put(game->mlx, game->win, game->player.px, game->player.py, color);
	while (x < 20) // longueur
	{
		mlx_pixel_put(game->mlx, game->win, game->player.px + i, game->player.py + j, color);
		j += cos(game->player.dir) * 5; // * 5 = ecart entre les points. *3 = plus rapproche et *6 = plus eloigne
		i += sin(game->player.dir) * 5;
		x++;
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

void	ft_erase_player(t_game *game, float pdx, float pdy)
{
	int rgb[3];
    int color;
	int	x;
	int	i;
	int	j;
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
	j = pdx;
	i = pdy;
	while (x < 30)
	{
		mlx_pixel_put(game->mlx, game->win, game->player.px + i, game->player.py + j, color);
		j += cos(game->player.dir) * 5;
		i += sin(game->player.dir) * 5;
		x++;
	}
}
