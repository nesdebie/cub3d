/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:11:22 by nesdebie          #+#    #+#             */
/*   Updated: 2023/09/21 12:22:46 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	close_game(t_game *game)
{
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
}

static int	deal_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		close_game(game);
	else if (!game->flag.held_keys)
	{
		if (key_code == KEY_W)
			return(0);//ft_move(game, &(game->player.spr), UP);
		else if (key_code == KEY_A)
			return (0);//ft_move(game, &(game->player.spr), LEFT);
		else if (key_code == KEY_S)
			return (0);//ft_move(game, &(game->player.spr), DOWN);
		else if (key_code == KEY_D)
			return (0);//ft_move(game, &(game->player.spr), RIGHT);
	}
	return (0);
}

static int	cub3d(t_game *game)
{
	draw_map(game);
	draw_sprites(game);
    //TO DO
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2)
		ft_error("No argument (min. 1)");
	if (argc > 2)
		ft_error("Too many arguments (max. 1)");
	if (!ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])))
		ft_error("Not a '<name>.cub' file.");
	file_read(&game, argv[1]);
	init_game(&game);
	mlx_hook(game.win, KEYBOARD_CODE, 0, &deal_key, &game);
	mlx_hook(game.win, RED_CROSS, 0, &close_game, &game);
	mlx_loop_hook(game.mlx, &cub3d, &game);
	mlx_loop(game.mlx);
	return (0);
}