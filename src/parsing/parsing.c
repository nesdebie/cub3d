/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <nesdebie@marvin.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 23:25:58 by nesdebie          #+#    #+#             */
/*   Updated: 2023/11/09 14:32:55 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	onlyint(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	isinset(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (0);
		i++;
	}
	return (1);
}

int parsing(t_game *game, char *map, int argc)
{
    if (check_extension(map, ".cub"))
		return (args_error(argc, map));
	if (read_file(game, map, 0, NULL))
		return (clear_args(game));
	if (check_params(game))
		return (clear_args(game));
    return (0);
}