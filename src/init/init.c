/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <nesdebie@marvin.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 23:39:35 by nesdebie          #+#    #+#             */
/*   Updated: 2023/10/24 23:45:46 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static float	init_dir(char c)
{
	if (c == 'N')
		return (0.25);
	else if (c == 'E')
		return (0.00);
	else if (c == 'S')
		return (0.75);
	return (0.50);
}

void	init_player(t_game *game, int x, int y)
{
	t_player	player;

	player.down = 0;
	player.left = 0;
	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (isinset(game->map[y][x], "NSWE") == 0)
			{
				player.px = x;
				player.py = y;
			}
		}
	}
	player.dir = init_dir(game->map[(int)player.py][(int)player.px]);
	player.px = player.px * (X / x);
	player.py = player.py * (Y / y);
	player.right = 0;
	player.up = 0;
	player.turn_left = 0;
	player.turn_right = 0;
	game->player = player;
}

int init_img(t_game *game)
{
	int	w;
	int	h;

	w = 128;
	h = 128;
	game->sprites.n = mlx_xpm_file_to_image(game->mlx, game->sprites.no, &h, &w);
	if (!game->sprites.n)
		return (mlx_error(MLX_XPM));
	game->sprites.s = mlx_xpm_file_to_image(game->mlx, game->sprites.so, &h, &w);
	if (!game->sprites.s)
		return (mlx_error(MLX_XPM));
	game->sprites.e = mlx_xpm_file_to_image(game->mlx, game->sprites.ea, &h, &w);
	if (!game->sprites.e)
		return (mlx_error(MLX_XPM));
	game->sprites.w = mlx_xpm_file_to_image(game->mlx, game->sprites.we, &h, &w);
	if (!game->sprites.w)
		return (mlx_error(MLX_XPM));
	return (0);
}

void	init_window(t_game *game)
{
	int	width;
	int	height;

	game->mlx = mlx_init();
	if (!game->mlx)
		mlx_error(MLX_INIT);
	width = X;
	height = Y;
	game->win = mlx_new_window(game->mlx, width, height, "cub3d");
	if (!game->win)
		mlx_error(MLX_WIN);
}

void	init_flags(t_game *game)
{
	game->flags.c_flag = 0;
	game->flags.e_flag = 0;
	game->flags.f_flag = 0;
	game->flags.l_flag = 0;
	game->flags.n_flag = 0;
	game->flags.p_flag = 0;
	game->flags.s_flag = 0;
	game->flags.w_flag = 0;
	game->flags.cnt = 0;
	game->map_str = NULL;
	game->map = NULL;
	game->img = NULL;
	game->sprites.n = 0;
	game->sprites.e = 0;
	game->sprites.w = 0;
	game->sprites.s = 0;
	game->player.map = 0;
	game->key_pressed = 0;
}