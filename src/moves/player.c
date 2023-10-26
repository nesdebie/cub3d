/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:47:26 by nesdebie          #+#    #+#             */
/*   Updated: 2023/10/26 11:47:52 by nesdebie         ###   ########.fr       */
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

void	ft_move(t_game *game, float pdx, float pdy)
{
	ft_update_dir(game);
	pdx = cos(game->player.dir) * 5;
	pdy = sin(game->player.dir) * 5;
	if (game->player.down == 1 && game->player.py < 600 && game->player.py > 0)
	{
		game->player.py -= pdx;
		game->player.px -= pdy;
	}
	if (game->player.up == 1 && game->player.py < 600 && game->player.py > 0)
	{
		game->player.py += pdx;
		game->player.px += pdy;
	}
	if (game->player.left == 1 && game->player.px > 0)
	{
		game->player.py -= pdy;
		game->player.px += pdx;
	}
	if (game->player.right == 1 && game->player.px < 1000)
	{
		game->player.py += pdy;
		game->player.px -= pdx;
	}
}