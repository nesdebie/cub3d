/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 23:39:35 by nesdebie          #+#    #+#             */
/*   Updated: 2023/10/30 11:47:23 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static float	init_dir(char c)
{
	if (c == 'S')
		return (0);
	else if (c == 'W')
		return (3*PI/2);
	else if (c == 'N')
		return (PI);
	return (PI/2);
}

void	init_player(t_game *game, int x, int y)
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
				player.px = x;
				player.py = y;
				player.dir = init_dir(game->map[y][x]);
				player.pos_x = x + 0.5;
				player.pos_y = y + 0.5;
			}
		}
	}
	printf("|%f|\n", player.dir);
	player.px = player.px * (X / x);
	player.py = player.py * (Y / y);
	player.right = 0;
	player.up = 0;
	player.turn_left = 0;
	player.turn_right = 0;
	game->player = player;
}

int init_textures(t_game *game)
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

int	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return(mlx_error(MLX_INIT));
	game->win = mlx_new_window(game->mlx, X, Y, "cub3d");
	if (!game->win)
		return(mlx_error(MLX_WIN));
	return (0);
}

void	init_pov(t_ray *ray)
{
	ray->camera_x = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->sidedist_x = 0;
	ray->sidedist_y = 0;
	ray->deltadist_x = 0;
	ray->deltadist_y = 0;
	ray->wall_dist = 0;
	ray->wall_x = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
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
	game->binary_screen = NULL;
	game->sprites.n = 0;
	game->sprites.e = 0;
	game->sprites.w = 0;
	game->sprites.s = 0;
	game->player.map = 0;
	game->key_pressed = 0;
}