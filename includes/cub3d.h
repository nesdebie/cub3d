/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo < hubrygo@student.s19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:11:57 by nesdebie          #+#    #+#             */
/*   Updated: 2023/10/19 15:03:48 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h> // DEBUG
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
//# include <mlx.h>
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

# define PI 3.1415926535

typedef enum s_error
{
	FILE_ERROR,
	FORMAT_ERROR,
	MALLOC_ERROR,
	NO_PLAYER,
	TWO_PLAYER,
	NOT_WALLED,
	INVALID_CHAR,
	TEXTURE_ACCESS,
	TEXTURE_EXTENSION,
	TEXTURE_OPEN,
	RGB_VALUE,
	RGB_FORMAT,
	MLX_WIN,
	MLX_INIT
}	t_error;

typedef struct s_player
{
	int		up;
	int 	down;
	int 	left;
	int 	right;
	int		turn_left;
	int		turn_right;
	float	px;
	float	py;
	float	dir;
}				t_player;

typedef struct s_spr
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
	int		f_trgb;
	int		c_trgb;
}				t_spr;

typedef struct s_flag
{
	int	l_flag;
	int	p_flag;
	int	n_flag;
	int	s_flag;
	int	w_flag;
	int	e_flag;
	int	c_flag;
	int	f_flag;
	int	cnt;
}				t_flag;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	char		*map_str;
	int			held_key;
	t_spr		sprites;
	t_flag		flags;
	t_player	player;
}				t_game;

/* ERRORS */
int		args_error(int ac, char *filename);
int		error_msg(int error);
int		xpmfile_error(char *filename, int error);
int		mlx_error(int error);

/* READER */
int		read_file(t_game *game, char *filename, int fd, char *tmp);

/* CHECKER */
int		check_params(t_game *game);
int		check_extension(char *filename, char *ext);
int		check_textures(t_game *game);
int		check_nsew(t_game *game);

/* FREE */
void	ft_freesplit(char **arr);
int		clear_args(t_game *game);

/* TEMP */
int		add_ea(t_game *game, char **arr);
int		add_we(t_game *game, char **arr);
int		add_so(t_game *game, char **arr);
int		add_no(t_game *game, char **arr);
int		add_fc(t_game *game, char **arr, char flag);

/* SETTER */
int	set_trgb(int r, int g, int b);

/* UTILS */
int		isinset(char c, char *set);
int		resize_array(char **map);
int		onlyint(char *s);

/*Key event*/
int		key_press(int key_code, t_game *game);
int		key_release(int key_code, t_game *game);
int		close_game(t_game *game);
void	ft_move(t_game *game, float pdx, float pdy);

/*Display*/
void	ft_erase_player(t_game *game, float pdx, float pdy);
void	draw_map(t_game *game);
void	ft_draw_player(t_game *game, float pdx, float pdy);

#endif