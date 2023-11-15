/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pre_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 23:39:35 by nesdebie          #+#    #+#             */
/*   Updated: 2023/11/15 14:34:59 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_dir(t_game *game)
{
	if (game->player.first_dir == 'N' || game->player.first_dir == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
		game->player.plane_x = 0.66;
		game->player.plane_y = 0;
	}
	if (game->player.first_dir == 'S')
	{
		game->player.dir_y = 1;
		game->player.plane_x = -0.66;
	}
	if (game->player.first_dir == 'E' || game->player.first_dir == 'W')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
	}
	if (game->player.first_dir == 'W')
	{
		game->player.dir_x = -1;
		game->player.plane_y = -0.66;
	}
}

static void	init_player(t_game *game, int x, int y)
{
	t_player	player;

	player.down = 0;
	player.left = 0;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (isinset(game->map[y][x], "NSWE") == 0)
			{
				player.first_dir = game->map[y][x];
				player.pos_x = x + 0.5;
				player.pos_y = y + 0.5;
			}
		}
	}
	player.right = 0;
	player.up = 0;
	player.pdx = 1;
	player.pdy = 1;
	player.turn_left = 0;
	player.turn_right = 0;
	player.speed = 0;
	game->player = player;
}

static int	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (mlx_error(MLX_INIT));
	game->win = mlx_new_window(game->mlx, X, Y, "cub3d");
	if (!game->win)
		return (mlx_error(MLX_WIN));
	return (0);
}

int	init_pre_loop(t_game *game)
{
	if (init_window(game))
		return (clear_args(game));
	if (init_wall_textures(game))
		return (clear_args(game));
	init_player(game, 0, -1);
	init_dir(game);
	return (0);
}
