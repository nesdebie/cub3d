/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo < hubrygo@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:05:08 by nesdebie          #+#    #+#             */
/*   Updated: 2023/10/30 14:46:40 by hubrygo          ###   ########.fr       */
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

