/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 00:03:27 by nesdebie          #+#    #+#             */
/*   Updated: 2023/11/27 11:18:54 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_failed_tab(void **tab, int last)
{
	while (last >= 0)
		free(tab[last--]);
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

void	free_tab(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

void	ft_freesplit(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != 0)
		free(arr[i++]);
	free(arr[i]);
	free(arr);
	arr = NULL;
}

static void	clear_textures(t_game *game)
{
	if (game->tx.n)
		free(game->tx.n);
	if (game->tx.s)
		free(game->tx.s);
	if (game->tx.e)
		free(game->tx.e);
	if (game->tx.w)
		free(game->tx.w);
	if (game->tx.d)
		free(game->tx.d);
}

int	clear_args(t_game *game)
{
	if (game->flags.n_flag > 0)
		free(game->tx.no);
	if (game->flags.s_flag > 0)
		free(game->tx.so);
	if (game->flags.e_flag > 0)
		free(game->tx.ea);
	if (game->flags.w_flag > 0)
		free(game->tx.we);
	if (game->flags.f_flag > 0)
		free(game->tx.f);
	if (game->flags.c_flag > 0)
		free(game->tx.c);
	if (game->map_str)
		free(game->map_str);
	if (game->map)
		ft_freesplit(game->map);
	clear_textures(game);
	return (1);
}
