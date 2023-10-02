/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:29:04 by nesdebie          #+#    #+#             */
/*   Updated: 2023/10/02 15:09:52 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int add_ea(t_game *game, char **arr)
{
	if (game->flags.e_flag)
		return (1);
	game->sprites.ea = ft_strdup(arr[1]);
	if (!game->sprites.ea)
		return (1);
	game->flags.e_flag++;
	return (0);
}

int add_we(t_game *game, char **arr)
{
	if (game->flags.w_flag)
		return (1);
	game->sprites.we = ft_strdup(arr[1]);
	if (!game->sprites.we)
		return (1);
	game->flags.w_flag++;
	return (0);
}

int add_so(t_game *game, char **arr)
{
	if (game->flags.s_flag)
		return (1);
	game->sprites.so = ft_strdup(arr[1]);
	if (!game->sprites.so)
		return (1);
	game->flags.s_flag++;
	return (0);
}

int add_no(t_game *game, char **arr)
{
	if (game->flags.n_flag)
		return (1);
	game->sprites.no = ft_strdup(arr[1]);
	if (!game->sprites.no)
		return (1);
	game->flags.n_flag++;
	return (0);
}

int add_fc(t_game *game, char **arr, char flag)
{
	if (flag == 'f')
	{
		if (game->flags.f_flag)
			return (1);
		game->sprites.f = ft_strdup(arr[1]);
		if (!game->sprites.f)
			return (1);
		game->flags.f_flag++;
	}
	if (flag == 'c')
	{
		if (game->flags.c_flag)
			return (1);
		game->sprites.c = ft_strdup(arr[1]);
		if (!game->sprites.c)
			return (1);
		game->flags.c_flag++;
	}
	return (0);
}
