/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo < hubrygo@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:39:09 by hubrygo           #+#    #+#             */
/*   Updated: 2023/10/19 14:23:35 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_draw_player(t_game *game, float pdx, float pdy)
{
	int	x;
	int	y;
	int	color;

	color = (255 << 16) | (255 << 8) | 0;
	x = -6;
	while (++x < 5)
	{
		y = -6;
		while (++y < 5)
			mlx_pixel_put(game->mlx, game->win, game->player.px + x, \
							game->player.py + y, color);
	}
	mlx_pixel_put(game->mlx, game->win, game->player.px, \
					game->player.py, color);
	while (++x < 16) // longueur
	{
		mlx_pixel_put(game->mlx, game->win, game->player.px + pdy, \
						game->player.py + pdx, color);
		pdx += cos(game->player.dir) * 2; // * 5 = ecart entre les points. *3 = plus rapproche et *6 = plus eloigne
		pdy += sin(game->player.dir) * 2;
	}
}

void	draw_map(t_game *game)
{
	int	rgb[3];
	int	x;
	int	y;
	int	color;

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
	int	x;
	int	y;
	int	color;

	color = (0 << 16) | (0 << 8) | 0;
	x = -6;
	while (++x < 5)
	{
		y = -6;
		while (++y < 5)
			mlx_pixel_put(game->mlx, game->win, game->player.px + x, \
							game->player.py + y, color);
	}
	while (++x < 16) // longueur
	{
		mlx_pixel_put(game->mlx, game->win, game->player.px + pdy, \
						game->player.py + pdx, color);
		pdx += cos(game->player.dir) * 2; // * 5 = ecart entre les points. *3 = plus rapproche et *6 = plus eloigne
		pdy += sin(game->player.dir) * 2;
	}
}
