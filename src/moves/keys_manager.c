/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:16:50 by hubrygo           #+#    #+#             */
/*   Updated: 2023/10/26 11:47:42 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	if (key_code == KEY_M)
	{
		if (!game->player.map)
			game->player.map = 1;
		else
			game->player.map = 0;
	}
	game->key_pressed = 1;
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