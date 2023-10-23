/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:05:08 by nesdebie          #+#    #+#             */
/*   Updated: 2023/10/23 11:45:07 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void draw_fc(t_game *game)
{
	int	x;
	int y;

	x = 0;
	y = 0;
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
