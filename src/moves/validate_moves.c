/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <nesdebie@marvin.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:25:56 by nesdebie          #+#    #+#             */
/*   Updated: 2023/11/09 13:28:41 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_valid_pos_wall_collision(t_game *data, double x, double y)
{
	if (data->map[(int)y][(int)x] == '0')
		return (0);
	return (1);
}

static int	is_valid_pos_in_map(t_game *data, double x, double y)
{
	if (x < 0.25 || x >= data->map_width - 1.25)
		return (1);
	if (y < 0.25 || y >= data->map_height -0.25)
		return (1);
	return (0);
}

static int	is_valid_pos(t_game *data, double x, double y)
{
	if (is_valid_pos_in_map(data, x, y))
		return (0);
	if (is_valid_pos_wall_collision(data, x, y))
		return (0);
	return (1);
}

int	validate_move(t_game *data, double new_x, double new_y)
{
	int	moved;
    int old_pos_x;
    int old_pos_y;
    
    old_pos_x = (int)data->player.pos_x;
    old_pos_y = (int)data->player.pos_y;
	moved = 0;
	if (is_valid_pos(data, new_x, data->player.pos_y))
	{
		data->player.pos_x = new_x;
		moved = 1;
	}
	if (is_valid_pos(data, data->player.pos_x, new_y))
	{
		data->player.pos_y = new_y;
		moved = 1;
	}
    data->map[old_pos_y][old_pos_x] = '0';
	return (moved);
}