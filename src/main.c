/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <nesdebie@marvin.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:11:22 by nesdebie          #+#    #+#             */
/*   Updated: 2023/10/03 00:10:56 by nesdebie         ###   ########.fr       */
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



int	init_flags(t_game *game)
{
	game = malloc(sizeof(t_game *));
	if (!game)
		return (1);
	game->flags.c_flag = 0;
	game->flags.e_flag = 0;
	game->flags.f_flag = 0;
	game->flags.l_flag = 0;
	game->flags.n_flag = 0;
	game->flags.p_flag = 0;
	game->flags.s_flag = 0;
	game->flags.w_flag = 0;
	game->flags.cnt = 0;
	return (0);
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

int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	if (argc < 2 || argc > 2)
		return(args_error(argc, NULL));
	if (check_extension(argv[1]))
		return(args_error(argc, argv[1]));
	if (init_flags(game))
		return (1);
	if (read_file(game, argv[1]))
	{
		clear_read(game);
		return (1);
	} 
	//init_game(&game);
	clear_temp_str(game); // apres init game
	//mlx_hook(game.win, PRESS_KEY, 0, &deal_key, &game);
	//mlx_hook(game.win, RED_CROSS, 0, &close_game, &game);
	//mlx_loop_hook(game.mlx, &cub3d, &game);
	//mlx_loop(game.mlx);*/
	ft_freesplit(game->map); // a add dans quit
	free(game); // a add dans quit
	return (0);
}
