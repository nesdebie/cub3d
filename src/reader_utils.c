/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:29:04 by nesdebie          #+#    #+#             */
/*   Updated: 2023/10/03 13:34:44 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int add_ea(t_game *game, char **arr)
{
	if (game->flags.e_flag > 0)
		return (reader_error(FORMAT_ERROR));
	game->sprites.ea = ft_strdup(arr[1]);
	if (!game->sprites.ea)
		return (reader_error(MALLOC_ERROR));
	game->flags.e_flag++;
	return (0);
}

int add_we(t_game *game, char **arr)
{
	if (game->flags.w_flag > 0)
		return (reader_error(FORMAT_ERROR));
	game->sprites.we = ft_strdup(arr[1]);
	if (!game->sprites.we)
		return (reader_error(MALLOC_ERROR));
	game->flags.w_flag++;
	return (0);
}

int add_so(t_game *game, char **arr)
{
	if (game->flags.s_flag > 0)
		return (reader_error(FORMAT_ERROR));
	game->sprites.so = ft_strdup(arr[1]);
	if (!game->sprites.so)
		return (reader_error(MALLOC_ERROR));
	game->flags.s_flag++;
	return (0);
}

int add_no(t_game *game, char **arr)
{
	if (game->flags.n_flag > 0)
		return (reader_error(FORMAT_ERROR));
	game->sprites.no = ft_strdup(arr[1]);
	if (!game->sprites.no)
		return (reader_error(MALLOC_ERROR));
	game->flags.n_flag++;
	return (0);
}

int add_fc(t_game *game, char **arr, char flag)
{
	if (flag == 'f')
	{
		if (game->flags.f_flag > 0)
			return (reader_error(FORMAT_ERROR));
		game->sprites.f = ft_strdup(arr[1]);
		if (!game->sprites.f)
			return (reader_error(MALLOC_ERROR));
		game->flags.f_flag++;
	}
	if (flag == 'c')
	{
		if (game->flags.c_flag > 0)
			return (reader_error(FORMAT_ERROR));
		game->sprites.c = ft_strdup(arr[1]);
		if (!game->sprites.c)
			return (reader_error(MALLOC_ERROR));
		game->flags.c_flag++;
	}
	return (0);
}
