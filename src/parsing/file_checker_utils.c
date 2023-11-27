/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:05:19 by nesdebie          #+#    #+#             */
/*   Updated: 2023/11/27 11:18:54 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	add_ea(t_game *game, char **arr)
{
	int	i;

	i = 0;
	if (game->flags.e_flag > 0)
		return (error_msg(FORMAT_ERROR));
	game->tx.ea = ft_strdup(arr[1]);
	if (!game->tx.ea)
		return (error_msg(MALLOC_ERROR));
	game->flags.e_flag++;
	while (game->tx.ea[i] && game->tx.ea[i] != '\n')
		i++;
	if (game->tx.ea[i])
		game->tx.ea[i] = 0;
	return (0);
}

int	add_we(t_game *game, char **arr)
{
	int	i;

	i = 0;
	if (game->flags.w_flag > 0)
		return (error_msg(FORMAT_ERROR));
	game->tx.we = ft_strdup(arr[1]);
	if (!game->tx.we)
		return (error_msg(MALLOC_ERROR));
	game->flags.w_flag++;
	while (game->tx.we[i] && game->tx.we[i] != '\n')
		i++;
	if (game->tx.we[i])
		game->tx.we[i] = 0;
	return (0);
}

int	add_so(t_game *game, char **arr)
{
	int	i;

	i = 0;
	if (game->flags.s_flag > 0)
		return (error_msg(FORMAT_ERROR));
	game->tx.so = ft_strdup(arr[1]);
	if (!game->tx.so)
		return (error_msg(MALLOC_ERROR));
	game->flags.s_flag++;
	while (game->tx.so[i] && game->tx.so[i] != '\n')
		i++;
	if (game->tx.so[i])
		game->tx.so[i] = 0;
	return (0);
}

int	add_no(t_game *game, char **arr)
{
	int	i;

	i = 0;
	if (game->flags.n_flag > 0)
		return (error_msg(FORMAT_ERROR));
	game->tx.no = ft_strdup(arr[1]);
	if (!game->tx.no)
		return (error_msg(MALLOC_ERROR));
	game->flags.n_flag++;
	while (game->tx.no[i] && game->tx.no[i] != '\n')
		i++;
	if (game->tx.no[i])
		game->tx.no[i] = 0;
	return (0);
}

int	add_fc(t_game *game, char **arr, char flag)
{
	if (flag == 'f')
	{
		if (game->flags.f_flag > 0)
			return (error_msg(FORMAT_ERROR));
		game->tx.f = ft_strdup(arr[1]);
		if (!game->tx.f)
			return (error_msg(MALLOC_ERROR));
		game->flags.f_flag++;
	}
	if (flag == 'c')
	{
		if (game->flags.c_flag > 0)
			return (error_msg(FORMAT_ERROR));
		game->tx.c = ft_strdup(arr[1]);
		if (!game->tx.c)
			return (error_msg(MALLOC_ERROR));
		game->flags.c_flag++;
	}
	return (0);
}
