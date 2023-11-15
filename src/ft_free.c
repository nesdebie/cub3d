/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo < hubrygo@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 00:03:27 by nesdebie          #+#    #+#             */
/*   Updated: 2023/11/15 11:39:58 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_failed_tab(void **tab, int last)
{
	while (last >= 0)
		free(tab[last--]);
		last--;
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

int	clear_args(t_game *game)
{
	if (game->flags.n_flag > 0)
		free(game->sprites.no);
	if (game->flags.s_flag > 0)
		free(game->sprites.so);
	if (game->flags.e_flag > 0)
		free(game->sprites.ea);
	if (game->flags.w_flag > 0)
		free(game->sprites.we);
	if (game->flags.f_flag > 0)
		free(game->sprites.f);
	if (game->flags.c_flag > 0)
		free(game->sprites.c);
	if (game->map_str)
		free(game->map_str);
	if (game->map)
		ft_freesplit(game->map);
	if (game->sprites.n)
		free(game->sprites.n);
	if (game->sprites.s)
		free(game->sprites.s);
	if (game->sprites.e)
		free(game->sprites.e);
	if (game->sprites.w)
		free(game->sprites.w);
	if (game->sprites.d)
		free(game->sprites.d);
	return (1);
}
