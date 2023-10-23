/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <nesdebie@marvin.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:05:08 by nesdebie          #+#    #+#             */
/*   Updated: 2023/10/23 09:06:41 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void draw_fc(t_game *game)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while (y < Y / 2)
	{
		while (x < X)
			mlx_pixel_put(game->mlx, game->win, x++, y, game->sprites.c_rgb);
		x = 0;
		y++;
	}
	while (y < Y)
	{
		while (x < X)
			mlx_pixel_put(game->mlx, game->win, x++, y, game->sprites.f_rgb);
		x = 0;
		y++;
	}
}