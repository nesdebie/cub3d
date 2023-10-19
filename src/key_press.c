/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo < hubrygo@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:16:50 by hubrygo           #+#    #+#             */
/*   Updated: 2023/10/19 15:03:38 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_press(int key_code, t_game *game)
{
	if (key_code == KEY_ESC || key_code == KEY_Q)
		close_game(game);
	if (key_code == KEY_W)
		game->player.up = 1;
	if (key_code == KEY_A)
		game->player.left = 1;
	if (key_code == KEY_S)
		game->player.down = 1;
	if (key_code == KEY_D)
		game->player.right = 1;
	if (key_code == KEY_LEFT)
		game->player.turn_left = 1;
	if (key_code == KEY_RIGHT)
		game->player.turn_right = 1;
	return (0);
}

int	key_release(int key_code, t_game *game)
{
	if (key_code == KEY_W)
		game->player.up = 0;
	if (key_code == KEY_A)
		game->player.left = 0;
	if (key_code == KEY_S)
		game->player.down = 0;
	if (key_code == KEY_D)
		game->player.right = 0;
	if (key_code == KEY_LEFT)
		game->player.turn_left = 0;
	if (key_code == KEY_RIGHT)
		game->player.turn_right = 0;
	return (0);
}

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
