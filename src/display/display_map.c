/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:39:09 by hubrygo           #+#    #+#             */
/*   Updated: 2023/11/15 14:48:56 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	create_player(t_game *game, int color)
{
	t_img	player;
	int		i;
	int		j;

	color = (100 << 24) | (255 << 16) | (255 << 8) | 0;
	player.img = NULL;
	init_img(game, &player, 5, 5);
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			set_image_pixel(&player, i, j, color);
			j++;
		}
		i++;
	}
	game->player.img_player = player;
}

void	display_player(t_game *game, int x)
{
	int		color;
	float	pdx;
	float	pdy;
	int		pl_y;
	int		pl_x;

	pl_y = (Y / 2) - (game->map_height * 19) / 2;
	pl_x = (X / 2) - (game->map_width * 19) / 2;
	pdx = game->player.pdx;
	pdy = game->player.pdy;
	color = (100 << 24) | (255 << 16) | (255 << 8) | 0;
	create_player(game, color);
	mlx_put_image_to_window(game->mlx, game->win, game->player.img_player.img, \
			(game->player.pos_x * 20) + pl_x, (game->player.pos_y * 20) + pl_y);
	mlx_destroy_image(game->mlx, game->player.img_player.img);
	while (++x < 7)
	{
		mlx_pixel_put(game->img, game->win, \
				game->player.pos_x * 20 + pdx + pl_x, \
				game->player.pos_y * 20 + pl_y + pdy, color);
		pdy += game->player.dir_y * 2;
		pdx += game->player.dir_x * 2;
	}
}

void	create_wall(t_game *game, int color)
{
	t_img	wall;
	int		y;
	int		x;
	int		i;
	int		j;

	color = (140 << 24) | (0 << 16) | (0 << 8) | 0;
	y = 19;
	x = 19;
	wall.img = NULL;
	init_img(game, &wall, x, y);
	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			set_image_pixel(&wall, i, j, color);
			j++;
		}
		i++;
	}
	game->wall = wall;
}

void	display_map(t_game *game, int color)
{
	int			i;
	int			j;
	int			pl_x;
	int			pl_y;
	static int	start = 0;

	pl_y = (Y / 2) - (game->map_height * 19) / 2;
	pl_x = (X / 2) - (game->map_width * 19) / 2;
	if (start == 0)
	{
		create_wall(game, color);
		start++;
	}
	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall.img, \
						(j * 20) + (pl_x), (i * 20) + pl_y);
		}
	}
}
