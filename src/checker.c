/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:07:18 by nesdebie          #+#    #+#             */
/*   Updated: 2023/10/06 13:42:56 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int check_chars(char *str)
{
	int i;
	int nb_pl;

	i = 0;
	nb_pl = 0;
	while (str[i])
	{
		if (isinset(str[i], " \n01NSEW"))
			return (checker_error(INVALID_CHAR));
		if (!isinset(str[i], "NSEW"))
			nb_pl++;
		if (nb_pl > 1)
			return (checker_error(TWO_PLAYER));
		i++;
	}
	if (!nb_pl)
		return (checker_error(NO_PLAYER));
	return (0);
}

static int ft_check_arounds(char **map, int y, int x)
{
	if (!y || !x || !map[y + 1] || !map[y][x + 1])
		return (1);
	if (isinset(map[y - 1][x - 1], "01SNEW"))
		return (1);
	if (isinset(map[y - 1][x], "01SNEW"))
		return (1);
	if (isinset(map[y - 1][x + 1], "01SNEW"))
		return (1);
	if (isinset(map[y][x - 1], "01SNEW"))
		return (1);
	if (isinset(map[y][x + 1], "01SNEW"))
		return (1);
	if (isinset(map[y + 1][x - 1], "01SNEW"))
		return (1);
	if (isinset(map[y + 1][x], "01SNEW"))
		return (1);
	if (isinset(map[y + 1][x + 1], "01SNEW"))
		return (1);
	return (0);
}

static int check_walls(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!isinset(map[i][j], "0SNEW"))
			{
				if (!i || !j || !map[i + 1] || !map[i][j + 1])
					return (1);
				else if (ft_check_arounds(map, i, j))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int onlyint(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int set_trgb(int r, int g, int b)
{
    return (255 << 24 | r << 16 | g << 8 | b);
}

int check_fc(t_game *game, char c)
{
	int     i;
	char    **arr;
	int     tmp;

	i = 0;
	if (c == 'c')
		arr = ft_split(game->sprites.c, ',');
	else if (c == 'f')
		arr = ft_split(game->sprites.f, ',');
	if (!arr)
		return (reader_error(MALLOC_ERROR));
	while (arr[i])
	{
		if (onlyint(arr[i]))
		{
			ft_freesplit(arr);
			return (1);
		}
		tmp = ft_atoi(arr[i]);
		if (tmp < 0 || tmp > 255)
		{
			ft_freesplit(arr);
			return (1);
		}
        i++;
	}
    if (i != 3)
    {
        ft_freesplit(arr);
        return (reader_error(FORMAT_ERROR));
    }
    if (c == 'c')
		game->sprites.c_trgb = set_trgb(ft_atoi(arr[0]), ft_atoi(arr[1]), ft_atoi(arr[2]));
	else if (c == 'f')
		game->sprites.f_trgb = set_trgb(ft_atoi(arr[0]), ft_atoi(arr[1]), ft_atoi(arr[2]));
    ft_freesplit(arr);
	return (0);
}

int check_textures(t_game *game)
{
	if (check_fc (game, 'f'))
		return(1);
	if (check_fc (game, 'c'))
		return(1);
	return (0);
}

int check_params(t_game *game)
{
	if (check_chars(game->map_str))
		return (1);
	if (check_textures(game))
		return (1);
	if (game->map_str[ft_strlen(game->map_str) - 1] != '\n')
		game->map_str = ft_strjoingnl(game->map_str, "\n");
	game->map = ft_split(game->map_str, '\n');
	if (!game->map)
		return (reader_error(MALLOC_ERROR));
	if (resize_array(game->map))
		return (reader_error(MALLOC_ERROR));
	if (check_walls(game->map))
		return (checker_error(NOT_WALLED));
	return (0);
}
