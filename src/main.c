/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:11:22 by nesdebie          #+#    #+#             */
/*   Updated: 2023/10/23 11:43:37 by nesdebie         ###   ########.fr       */
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

	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	game->img = mlx_new_image(game->mlx, X, Y);
	draw_fc(game);
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
	return (0);
}

void	init_flags(t_game *game)
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
	game->sprites.n = 0;
	game->sprites.e = 0;
	game->sprites.w = 0;
	game->sprites.s = 0;
	game->player.map = 0;
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

static void	init_window(t_game *game)
{
	int	width;
	int	height;

	game->mlx = mlx_init();
	if (!game->mlx)
		mlx_error(MLX_INIT);
	width = X;
	height = Y;
	game->win = mlx_new_window(game->mlx, width, height, "cub3d");
	if (!game->win)
		mlx_error(MLX_WIN);
}

float	ft_dir(char c)
{
	if (c == 'N')
		return (0.25);
	else if (c == 'E')
		return (0.00);
	else if (c == 'S')
		return (0.75);
	return (0.50);
}

void	ft_init_player(t_game *game, int x, int y)
{
	t_player	player;

	player.down = 0;
	player.left = 0;
	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (isinset(game->map[y][x], "NSWE") == 0)
			{
				player.px = x;
				player.py = y;
			}
		}
	}
	player.dir = ft_dir(game->map[(int)player.py][(int)player.px]);
	player.px = player.px * (1000 / x);
	player.py = player.py * (600 / y);
	player.right = 0;
	player.up = 0;
	player.turn_left = 0;
	player.turn_right = 0;
	game->player = player;
}

int ft_init_img(t_game *game)
{
	int	w;
	int	h;

	w = 128;
	h = 128;
	game->sprites.n = mlx_xpm_file_to_image(game->mlx, game->sprites.no, &h, &w);
	if (!game->sprites.n)
		return (mlx_error(MLX_XPM));
	game->sprites.s = mlx_xpm_file_to_image(game->mlx, game->sprites.so, &h, &w);
	if (!game->sprites.s)
		return (mlx_error(MLX_XPM));
	game->sprites.e = mlx_xpm_file_to_image(game->mlx, game->sprites.ea, &h, &w);
	if (!game->sprites.e)
		return (mlx_error(MLX_XPM));
	game->sprites.w = mlx_xpm_file_to_image(game->mlx, game->sprites.we, &h, &w);
	if (!game->sprites.w)
		return (mlx_error(MLX_XPM));
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2 || argc > 2)
		return (args_error(argc, NULL));
	if (check_extension(argv[1], ".cub"))
		return (args_error(argc, argv[1]));
	init_flags(&game);
	if (read_file(&game, argv[1], 0, NULL))
		return (clear_args(&game));
	if (check_params(&game))
		return (clear_args(&game));
	print_params(&game); // DEBUG
	init_window(&game);
	if (ft_init_img(&game))
		return (clear_args(&game));
	ft_init_player(&game, 0, 0);
	
	mlx_hook(game.win, PRESS_KEY, 0, &key_press, &game);
	mlx_hook(game.win, RELEASE_KEY, 0, &key_release, &game);
	mlx_hook(game.win, RED_CROSS, 0, &close_game, &game);
	mlx_loop_hook(game.mlx, &cub3d, &game);
	mlx_loop(game.mlx);
	return (0);
}
