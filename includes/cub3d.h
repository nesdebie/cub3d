/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <nesdebie@marvin.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:11:57 by nesdebie          #+#    #+#             */
/*   Updated: 2023/10/03 00:48:11 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <../mlx/mlx.h>
# include "../libft/libft.h"

# define NO_MOVE	0
# define DOWN		1
# define LEFT		2
# define UP			3
# define RIGHT		4

# define KEY_ESC	53
# define KEY_Q      12

# define KEY_W	13
# define KEY_A	0
# define KEY_S	1
# define KEY_D	2

# define KEY_LEFT	123
# define KEY_RIGHT	124

# define RED_CROSS 17
# define PRESS_KEY 2
# define RELEASE_KEY 3

# define FILE_ERROR 0
# define FORMAT 1
# define MALLOC 2

typedef	struct	s_spr
{
	void	*n;
	void	*s;
	void	*w;
	void	*e;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
}				t_spr;

typedef struct	s_flag
{
	int	l_flag;
	int	p_flag;
	int	n_flag;
	int s_flag;
	int	w_flag;
	int e_flag;
	int	c_flag;
	int	f_flag;
	int cnt;
}				t_flag;


typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	char	*map_str;
	t_spr	sprites;
	t_flag	flags;
}				t_game;

/* ERRORS */
int	args_error(int ac, char *filename);
int reader_error(int error);

/* READER */
int	read_file(t_game *game, char *filename);

/* FREE */
void	ft_freesplit(char **arr);
void	clear_read(t_game *game);
void    clear_temp_str(t_game *game);

/* TEMP */
int	add_ea(t_game *game, char **arr);
int	add_we(t_game *game, char **arr);
int	add_so(t_game *game, char **arr);
int	add_no(t_game *game, char **arr);
int	add_fc(t_game *game, char **arr, char flag);

#endif