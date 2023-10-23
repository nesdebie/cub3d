/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:05:08 by nesdebie          #+#    #+#             */
/*   Updated: 2023/10/23 15:57:46 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void draw_pov(t_game *game, char *addr)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	(void)addr;
	while (y < Y)
	{
		while (x < X)
		{
			if (y < Y / 2)
				mlx_pixel_put(game->img, game->win, x, y, game->sprites.c_rgb);
			else
				mlx_pixel_put(game->img, game->win, x, y, game->sprites.f_rgb);
			x++;
		}
		x = 0;
		y++;
	}
}

void draw_blacked(t_game *game, char *addr)
{
	int	x;
	int y;
	int black;

	x = 0;
	y = 0;
	black = 0 << 16 | 0 << 8 | 0;
	(void)addr;
	while (y < Y)
	{
		while (x < X)
		{
				mlx_pixel_put(game->img, game->win, x, y, black);
			x++;
		}
		x = 0;
		y++;
	}
}
