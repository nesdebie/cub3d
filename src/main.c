/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:11:22 by nesdebie          #+#    #+#             */
/*   Updated: 2023/10/03 14:58:29 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
/*
   int	close_game(t_game *game)
   {
   if (game->mlx && game->win)
   mlx_destroy_window(game->mlx, game->win);
   exit(EXIT_SUCCESS);
   }

   static int	deal_key(int key_code, t_game *game)
   {
   if (key_code == KEY_ESC || key_code == KEY_Q)
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
   else if (key_code == KEY_LEFT)
   return (0);//move camera left
   else if (key_code == KEY_RIGHT)
   return (0);//move camera right
   }
   return (0);
   }

   static int	cub3d(t_game *game)
   {
   draw_map(game);
   draw_sprites(game);
//TO DO
return (0);
}*/



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
}

int	check_extension(char *filename)
{
	unsigned long	i;

	i = 0;
	if (!ft_strnstr(filename, ".cub", ft_strlen(filename)))
		return (1);
	else
	{
		while (i < ft_strlen(filename) - 4)
			i++;
		if (ft_strncmp(&filename[i], ".cub", 5))
			return (1);
	}
	return (0);
}

void	print_params(t_game *game)
{
	int i = 0;
	printf("NO: %sSO: %sEA: %sWE: %s\nf : %sc : %s", game->sprites.no, game->sprites.so, game->sprites.ea, game->sprites.we, game->sprites.f, game->sprites.c);
	printf("\nMAP (char *):\n%s", game->map_str);
	ft_putendl_fd("\n________________________\nMAP (arr):", 1);
	while(game->map[i])
	{
		ft_putendl_fd(game->map[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2 || argc > 2)
		return(args_error(argc, NULL));
	if (check_extension(argv[1]))
		return(args_error(argc, argv[1]));
	init_flags(&game);
	if (read_file(&game, argv[1], 0, NULL))
		return (clear_args(&game));
	if (check_params(&game))
		return (clear_args(&game));
	print_params(&game); // DEBUG
	//init_game(&game);
	clear_args(&game);
	//mlx_hook(game.win, PRESS_KEY, 0, &deal_key, &game);
	//mlx_hook(game.win, RED_CROSS, 0, &close_game, &game);
	//mlx_loop_hook(game.mlx, &cub3d, &game);
	//mlx_loop(game.mlx);*/
	
	//ft_freesplit(game.map); // a add dans quit
	return (0);
}
