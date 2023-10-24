/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <nesdebie@marvin.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:11:22 by nesdebie          #+#    #+#             */
/*   Updated: 2023/10/24 23:50:50 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	close_game(t_game *game)
{
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	clear_args(game);
	exit(EXIT_SUCCESS);
}

static int	cub3d(t_game *game)
{
	static float	pdx = 1;
	static float	pdy = 1;
	char			*addr = NULL;

	
	//if (game->key_pressed == 1)
	//{
		draw_blacked(game, addr);
		draw_pov(game, addr);
		addr = mlx_get_data_addr(game->img, &(int){0}, &(int){0}, &(int){0});
		
		if (game->player.map == 1)
		{
			ft_erase_player(game, pdx, pdy);
			ft_move(game, pdx, pdy);
			draw_map(game);
			ft_draw_player(game, pdx, pdy);
		}
		mlx_put_image_to_window(game->mlx, game->win, game->img, X, Y);
		//draw_sprites(game);
		//TO DO
		//game->key_pressed = 0;
		
	//}
	
	return (0);
}



void	print_params(t_game *game)
{
	int	i;

	i = 0;
	printf("NO: |%s|\nSO: |%s|\nEA: |%s|\nWE: |%s|\nf : |%s|=|%d|\nc : \
			|%s|=|%d|\n", game->sprites.no, game->sprites.so, game->sprites.ea, \
			game->sprites.we, game->sprites.f, game->sprites.f_rgb, \
			game->sprites.c, game->sprites.c_rgb);
	printf("\nMAP (char *):\n%s", game->map_str);
	ft_putendl_fd("\n________________________\nMAP (arr):", 1);
	while (game->map[i] != NULL)
	{
		ft_putendl_fd(game->map[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2 || argc > 2)
		return (args_error(argc, NULL));
	init_flags(&game);
	if (parsing(&game, argv[1], argc))
		return (1);
	print_params(&game);// DEBUG
	init_window(&game);
	if (init_img(&game))
		return (clear_args(&game));
	init_player(&game, 0, 0);
	game.img = mlx_new_image(game.mlx, X, Y);
	if (!game.img)
	{
		mlx_error(MLX_IMG);
		return (clear_args(&game));
	}
	mlx_hook(game.win, PRESS_KEY, 0, &key_press, &game);
	mlx_hook(game.win, RELEASE_KEY, 0, &key_release, &game);
	mlx_hook(game.win, RED_CROSS, 0, &close_game, &game);
	mlx_loop_hook(game.mlx, &cub3d, &game);
	mlx_loop(game.mlx);
	return (0);
}
