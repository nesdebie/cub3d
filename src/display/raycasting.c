/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <nesdebie@marvin.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:05:08 by nesdebie          #+#    #+#             */
/*   Updated: 2023/11/09 14:30:14 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	set_binary_screen(t_game *game, t_ray *ray, int x)
{
	int				y;
	int				i;
	unsigned long	color;

	y = ray->draw_start;
	i = 0;
	while (y < Y - 1 && i < ray->line_height)
	{
		color = set_rgb(128, 128, 128);
		game->binary_screen[y][x] = color;
		y++;
		i++;
	}
}

static void	calculate_line_height(t_ray *ray, t_player *player)
{
	(void) player;
	if (ray->side == 0)
		ray->wall_dist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->wall_dist = (ray->sidedist_y - ray->deltadist_y);
	ray->line_height = (int)(Y / ray->wall_dist);
	ray->draw_start = Y / 2 - ((ray->line_height) / 2);
	if (ray->draw_start < 0)
		ray->draw_start = 0;
}

void	raycasting(t_player *player, t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	ray = game->ray;
	while (x < X)
	{
		init_raycasting(x, &ray, player);
		set_dda(&ray, player);
		dda(game, &ray);
		calculate_line_height(&ray, player);
		set_binary_screen(game, &ray, x);
		x++;
	}
}

