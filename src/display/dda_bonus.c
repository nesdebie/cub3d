/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <nesdebie@marvin.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:40:16 by nesdebie          #+#    #+#             */
/*   Updated: 2023/11/19 20:00:38 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_dda(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (player->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - player->pos_x) * ray->deltadist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (player->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - player->pos_y) * ray->deltadist_y;
	}
}

static double distance(t_game *game, t_ray *ray)
{
	double ret;

	double	x1 = (double)game->player.pos_x;
	double	y1 = (double)game->player.pos_y;
	double x2 = ray->map_x + 0.5;
	double y2 = ray->map_y + 0.5;

	if (((int)x1 - (int)x2) > 1 || ((int)x1 - (int)x2) < -1)
		return (2);
	if (((int)y1 - (int)y2) > 1 || ((int)y1 - (int)y2) < -1)
		return (2);
	ret = sqrt((y1 - y2) + (y1 - y2));
	return (ret);
}

void	dda(t_game *game, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0.25 || ray->map_x < 0.25)
			break ;
		else if (ray->map_y > game->map_height - 0.25)
			break ;
		else if (ray->map_x > game->map_width - 1.25)
			break ;
		else if (game->map[ray->map_y][ray->map_x] > '0')
		{
			if (game->map[ray->map_y][ray->map_x] == 'P')
			{
				if (distance(game, ray) < 0.75 && distance(game, ray) >= -0.75)
					game->map[ray->map_y][ray->map_x] = 'p';
			}
			else if (game->map[ray->map_y][ray->map_x] == 'p')
			{
				if (distance(game, ray) >= 0.75 || distance(game, ray) < -0.75)
					game->map[ray->map_y][ray->map_x] = 'P';
			}
			if (game->map[ray->map_y][ray->map_x] == 'P')
				game->flags.door = 1;
			if (game->map[ray->map_y][ray->map_x] != 'p')
				hit = 1;
		}
	}
}
