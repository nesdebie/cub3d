/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:11:22 by nesdebie          #+#    #+#             */
/*   Updated: 2023/11/13 12:42:56 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

unsigned long	set_rgb(int red, int green, int blue)
{
	return ((red) << 16) | ((green) << 8) | (blue);
}

static int	cub3d(t_game *game)
{
	if (game->spacebar == 1)
	{
		mlx_mouse_hide();
		mlx_mouse_get_pos(game->win, &game->mouse_x, &game->mouse_y);
		mlx_mouse_move(game->win, X / 2, Y / 2);
		if (game->mouse_x != X / 2)
			rotate(game);
	}
	ft_move_player(game);
	if (game->spacebar == 0)
		mlx_mouse_show();
	display_pov(game);
	if (game->player.map == 1)
	{
		display_map(game);
		display_player(game);
	}
	return (0);
}

static void	init_flags(t_game *game)
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
	game->spacebar = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2 || argc > 2)
		return (args_error(argc, NULL));
	init_flags(&game);
	if (parsing(&game, argv[1], argc))
		return (1);
	if (init_pre_loop(&game))
		return (1);
	display_pov(&game);
	mlx_hook(game.win, PRESS_KEY, 0, &key_press, &game);
	mlx_hook(game.win, RELEASE_KEY, 0, &key_release, &game);
	mlx_hook(game.win, RED_CROSS, 0, &close_game, &game);
	mlx_loop_hook(game.mlx, &cub3d, &game);
	mlx_loop(game.mlx);
	return (0);
}
