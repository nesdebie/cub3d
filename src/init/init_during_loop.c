/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_during_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:41:36 by nesdebie          #+#    #+#             */
/*   Updated: 2023/11/13 13:28:25 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void set_zero(unsigned long **arr)
{
	int y;
	int x;

	y = 0;
	while (y < Y)
	{
		x = 0;
		while (x < X)
		{
			arr[y][x] = 0;
			x++;
		}
		y++;
	}
}

void	init_binary_screen(t_game *game)
{
	int	i;

	if (game->binary_screen)
		set_zero(game->binary_screen);
	else
	{
		game->binary_screen = ft_calloc(Y + 1, sizeof * game->binary_screen);
		if (!game->binary_screen)
		{
			clear_args(game);
			exit (EXIT_FAILURE);
		}
		i = 0;
		while (i < Y)
		{
			game->binary_screen[i] = ft_calloc(X + 1, sizeof * game->binary_screen);
			if (!game->binary_screen[i])
			{
				free_failed_tab((void **)game->binary_screen, i);
				clear_args(game);
				exit (EXIT_FAILURE);
			}
			i++;
		}
	}
}

void	init_img(t_game *game, t_img *image, int width, int height)
{
	init_img_clean(image);
	image->img = mlx_new_image(game->mlx, width, height);
	if (image->img == NULL)
	{
			clear_args(game);
			exit (EXIT_FAILURE);
	}
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
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

void	init_raycasting(int x, t_ray *ray, t_player *player)
{
	init_pov(ray);
	ray->camera_x = 2 * x / (double)X - 1;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->deltadist_x = fabs(1 / ray->dir_x);
	ray->deltadist_y = fabs(1 / ray->dir_y);
}