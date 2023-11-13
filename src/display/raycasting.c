/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <nesdebie@marvin.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:05:08 by nesdebie          #+#    #+#             */
/*   Updated: 2023/11/13 08:34:42 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


static int	get_texture_pixel(t_game * game, t_ray *ray, int x, int y)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			return (game->sprites.w[SIZE * y + x]);
		else
			return (game->sprites.e[SIZE * y + x]);
	}
	else if (ray->dir_y > 0)
		return (game->sprites.s[SIZE * y + x]);
	return (game->sprites.n[SIZE * y + x]);
}

static void	set_binary_screen(t_game *game, t_ray *ray, int x, int i)
{
	int y;
	int tx;
	int ty;
	float t_step;
	float t_pos;

	tx = (int)(ray->wall_x * SIZE);
	if ((ray->side == 0 && ray->dir_x < 0) || (ray->side == 1 && ray->dir_y > 0))
		tx = SIZE - tx - 1;
	t_step = 1.0 * SIZE / ray->line_height;
	t_pos = (ray->draw_start - Y / 2 + ray->line_height / 2) * t_step;
	y = ray->draw_start - 1;
	while (++y < Y - 1 && ++i < ray->line_height)
	{
		ty = (int)t_pos & (SIZE - 1);
		t_pos += t_step;
		game->binary_screen[y][x] = get_texture_pixel(game, ray, tx, ty);
	}
}

static void	calculate_line_height(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->wall_dist = (ray->sidedist_y - ray->deltadist_y);
	ray->line_height = (int)(Y / ray->wall_dist);
	ray->draw_start = Y / 2 - ((ray->line_height) / 2);
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->side == 0)
		ray->wall_x = game->player.pos_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = game->player.pos_x + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
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
		calculate_line_height(game, &ray);
		set_binary_screen(game, &ray, x, -1);
		x++;
	}
}

