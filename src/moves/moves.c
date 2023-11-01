/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:36:27 by nesdebie          #+#    #+#             */
/*   Updated: 2023/11/01 13:12:09 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_valid_pos_wall_collision(t_game *data, double x, double y)
{
	if (data->map[(int)y][(int)x] == '0' || data->map[(int)y][(int)x] == 'c') //DEBUG
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
    if (moved == 1 && data->map[(int)new_y][(int)new_x] != '1')
    {
        data->map[old_pos_y][old_pos_x] = '0';
        data->map[(int)new_y][(int)new_x] = 'c';
    }
	return (moved);
}

static int  move_right(t_game *game, float pdx, float pdy)
{
   float new_x;
   float new_y;
   
   new_x = game->player.pos_x - pdy;
   new_y =game->player.pos_y + pdx;
   return (validate_move(game, new_x, new_y));
}

static int  move_left(t_game *game, float pdx, float pdy)
{
   float new_x;
   float new_y;
   
   new_x = game->player.pos_x + pdy;
   new_y =game->player.pos_y - pdx;
   return (validate_move(game, new_x, new_y));    
}

static int  move_down(t_game *game, float pdx, float pdy)
{
   float new_x;
   float new_y;
   
   new_x = game->player.pos_x - pdx;
   new_y =game->player.pos_y - pdy;
   return (validate_move(game, new_x, new_y));
}

static int  move_up(t_game *game, float pdx, float pdy)
{
   float new_x;
   float new_y;
   
   new_x = game->player.pos_x + pdx;
   new_y =game->player.pos_y + pdy;
   return (validate_move(game, new_x, new_y));
}

void	ft_move_player(t_game *game, float pdx, float pdy)
{
	ft_update_dir(game);
	pdx = game->player.dir_x;
	pdy = game->player.dir_y;

	if (game->player.down == 1)
    {
        move_down(game, pdx, pdy);
    }
	if (game->player.up == 1)
	{
        move_up(game, pdx, pdy);
	}
    if (game->player.right == 1)
    {
        move_right(game, pdx, pdy);
    }
    if (game->player.left == 1)
    {
        move_left(game, pdx, pdy);
    }
    if (game->player.down || game->player.up || game->player.left || game->player.right) // DEBUG
    {
        int i = 0;
        while (game->map[i] != NULL)
        {
            ft_putendl_fd(game->map[i], 1);
            i++;
        }
        ft_putchar_fd('\n', 1);
    }
    printf("\n---\npre-rotate:\ndirx: %f\ndiry: %f\n", game->player.dir_x, game->player.dir_y);
    if (game->player.turn_right == 1 || game->player.turn_left == 1)
    {
        rotate(game);
    }
    printf("\n---\npost-rotate:\ndirx: %f\ndiry: %f\n", game->player.dir_x, game->player.dir_y);
}