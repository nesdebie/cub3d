/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo < hubrygo@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:40:16 by nesdebie          #+#    #+#             */
/*   Updated: 2023/11/15 12:30:19 by hubrygo          ###   ########.fr       */
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
			//if (game->player.open == 1 && game->door == 1)
			//{
			//	if (game->map[game->ray.map_y][game->ray.map_x] == 'P')
			//		game->map[game->ray.map_y][game->ray.map_x] = 'p';
			//	else if (game->map[game->ray.map_y][game->ray.map_x] == 'p')
			//		game->map[game->ray.map_y][game->ray.map_x] = 'P';
			//	printf("%c\n", game->map[game->ray.map_y][game->ray.map_x]);
			//	game->player.open = 0;
			//}
			if (game->map[ray->map_y][ray->map_x] == 'P')
				game->door = 1;
			if (game->map[ray->map_y][ray->map_x] != 'p')
				hit = 1;
		}
	}
}
