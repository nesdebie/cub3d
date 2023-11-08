/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo <hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:33:33 by nesdebie          #+#    #+#             */
/*   Updated: 2023/11/08 19:39:16 by hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	rotate_left_right(t_game *game, double rotspeed)
{
	t_player	*p;
	double		tmp_x;

	p = &game->player;
	tmp_x = p->dir_x;
	p->dir_x = p->dir_x * cos(rotspeed) - p->dir_y * sin(rotspeed);
	p->dir_y = tmp_x * sin(rotspeed) + p->dir_y * cos(rotspeed);
	tmp_x = p->plane_x;
	p->plane_x = p->plane_x * cos(rotspeed) - p->plane_y * sin(rotspeed);
	p->plane_y = tmp_x * sin(rotspeed) + p->plane_y * cos(rotspeed);
	return (1);
}

int	rotate(t_game *game)
{
	int		moved;
	double	rotspeed;

	moved = 0;
    rotspeed = ROTSPEED;
    if (game->player.turn_left == 1)
	    rotspeed *= -1;
	if (game->key_pressed == 1 && game->mouse_x < X / 2)
		rotspeed *= -1;
	moved += rotate_left_right(game, rotspeed);
	return (moved);
}