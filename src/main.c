/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:11:22 by nesdebie          #+#    #+#             */
/*   Updated: 2023/10/02 13:00:52 by nesdebie         ###   ########.fr       */
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

int check_line(char *line, int flag)
{
	if (flag == ERROR_FLAG)
		return (1);
	ft_putstr_fd(line, 1); // DEBUG
	return (0);
}

int isinset(char c, char *set)
{
	int i;

	i = 0;
	while(set[i])
	{
		if (c == set[i])
			return (0);
		i++;
	}
	return (1);
}

int	set_line_flag2(char *line, t_game *game)
{
	(void)line;
	(void)game;
	//int	ret;
	//int i;

	//i = 0;
	/*
	while (line[i] && !isinset(line[i], " NSWE01\n"))
	{
		if (line[i] == '\n')
			return (MAP_FLAG);
		if (!isinset(line[i], "NSWE"))
			game->flags.p_flag++;
		if (game->flags.p_flag > 1)
			return (ERROR_FLAG);
		i++;
	}*/
	return (0);
}

int	set_line_flag(char *line, t_game *game)
{
	if (!line)
		return (ERROR_FLAG);
	if (line[0] == '\n' && game->flags.l_flag == MAP_FLAG)
		return(ERROR_FLAG);
	return (set_line_flag2(line, game));
}

int read_file(t_game *game, char *filename)
{
	int fd;
	char *tmp;

	game->flags.l_flag = 0;
	game->flags.p_flag = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 1)
		return (1);
	tmp = get_next_line(fd);
	while (tmp)
	{
		game->flags.l_flag = set_line_flag(tmp, game);
		if (check_line(tmp, game->flags.l_flag))
		{
			free(tmp);
			return (1);
		}
		free (tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	free (tmp);
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
	t_game	game;

	(void) game;
	if (argc < 2 || argc > 2)
		return(args_error(argc, NULL));
	if (check_extension(argv[1]))
		return(args_error(argc, argv[1]));
	if (read_file(&game, argv[1]))
		return (1);
	/*
	//init_game(&game);
	mlx_hook(game.win, PRESS_KEY, 0, &deal_key, &game);
	mlx_hook(game.win, RED_CROSS, 0, &close_game, &game);
	mlx_loop_hook(game.mlx, &cub3d, &game);
	mlx_loop(game.mlx);*/
	return (0);
}