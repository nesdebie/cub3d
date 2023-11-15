/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:36:27 by nesdebie          #+#    #+#             */
/*   Updated: 2023/11/15 14:28:39 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	move_right(t_game *game, float pdx, float pdy)
{
	float	new_x;
	float	new_y;

	new_x = game->player.pos_x - pdy;
	new_y = game->player.pos_y + pdx;
	return (validate_move(game, new_x, new_y));
}

static int	move_left(t_game *game, float pdx, float pdy)
{
	float	new_x;
	float	new_y;

	new_x = game->player.pos_x + pdy;
	new_y = game->player.pos_y - pdx;
	return (validate_move(game, new_x, new_y));
}

static int	move_down(t_game *game, float pdx, float pdy)
{
	float	new_x;
	float	new_y;

	new_x = game->player.pos_x - pdx;
	new_y = game->player.pos_y - pdy;
	return (validate_move(game, new_x, new_y));
}

static int	move_up(t_game *game, float pdx, float pdy)
{
	float	new_x;
	float	new_y;

	new_x = game->player.pos_x + pdx;
	new_y = game->player.pos_y + pdy;
	return (validate_move(game, new_x, new_y));
}

void	ft_move_player(t_game *game)
{
	if (game->player.speed_up == 1)
		if (game->player.speed > -2)
			game->player.speed--;
	if (game->player.speed_down == 1)
		if (game->player.speed < 9)
			game->player.speed++;
	game->player.pdx = game->player.dir_x / (SPEED + game->player.speed);
	game->player.pdy = game->player.dir_y / (SPEED + game->player.speed);
	if (game->player.down == 1)
		move_down(game, game->player.pdx, game->player.pdy);
	if (game->player.up == 1)
		move_up(game, game->player.pdx, game->player.pdy);
	if (game->player.right == 1)
		move_right(game, game->player.pdx, game->player.pdy);
	if (game->player.left == 1)
		move_left(game, game->player.pdx, game->player.pdy);
	if (game->player.turn_right == 1 || game->player.turn_left == 1)
		rotate(game);
}
