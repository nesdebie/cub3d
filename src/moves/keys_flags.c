/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:16:50 by hubrygo           #+#    #+#             */
/*   Updated: 2023/11/13 12:43:23 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	key_features(int key_code, t_game *game)
{
	if (key_code == KEY_M)
	{
		if (game->player.map == 0)
			game->player.map = 1;
		else
			game->player.map = 0;
	}
	if (key_code == KEY_SPACE)
	{
		if (game->spacebar == 0)
			game->spacebar = 1;
		else
			game->spacebar = 0;
	}	
}

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
	if (key_code == KEY_UP)
		game->player.speed_up = 1;
	if (key_code == KEY_DOWN)
		game->player.speed_down = 1;
	key_features(key_code, game);
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
	if (key_code == KEY_UP)
		game->player.speed_up = 0;
	if (key_code == KEY_DOWN)
		game->player.speed_down = 0;
	return (0);
}
