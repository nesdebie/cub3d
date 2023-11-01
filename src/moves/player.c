/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:47:26 by nesdebie          #+#    #+#             */
/*   Updated: 2023/11/01 14:01:29 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_update_dir(t_game *game)
{
	if (game->player.turn_right == 1)
	{
		game->player.dir -= 0.1;
		if (game->player.dir < 0)
			game->player.dir += 2 * PI;
	}
	if (game->player.turn_left == 1)
	{
		game->player.dir += 0.1;
		if (game->player.dir > (2 * PI))
			game->player.dir -= 2 * PI;
	}
}

void	ft_move_pixels(t_game *game, float pdx, float pdy)
{
	ft_update_dir(game);
	pdx = cos(game->player.dir) * SPEED;
	pdy = sin(game->player.dir) * SPEED;
	if (game->player.down == 1 && game->player.py < Y && game->player.py > 0)
	{
		game->player.py -= pdx;
		game->player.px -= pdy;
	}
	if (game->player.up == 1 && game->player.py < Y && game->player.py > 0)
	{
		game->player.py += pdx;
		game->player.px += pdy;
	}
	if (game->player.left == 1 && game->player.px > 0)
	{
		game->player.py -= pdy;
		game->player.px += pdx;
	}
	if (game->player.right == 1 && game->player.px < X)
	{
		game->player.py += pdy;
		game->player.px -= pdx;
	}
}