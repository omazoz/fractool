/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omazoz <omazoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:59:56 by omazoz            #+#    #+#             */
/*   Updated: 2022/03/03 20:12:26 by omazoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include "libft.h"
# include "ft_mlx_keys.h"
# define WIDTH 1000
# define HEIGHT 1000
# define TITLE "fract-ol"
# define MAX_ITER 100
# define FRACTAL_COUNT 3

typedef struct s_env		t_env;
typedef struct s_fract_calc	t_calc;

typedef int					(*t_draw)(t_env *env, t_calc *calc);

typedef struct s_fract_set
{
	char	*name;
	t_draw	function;
}					t_fract_set;

typedef struct s_mande_l
{
	double	x;
	double	y;
	double	b;
	double	a;
	int		k;
	int		i;
	int		j;
	float	ca;
	float	cb;
}					t_mande_l;

typedef struct s_rect
{
	int	min_x;
	int	max_x;
	int	min_y;
	int	max_y;
}					t_rect;

struct			s_fract_calc
{
	double	min_i;
	double	max_i;
	double	min_r;
	double	max_r;
	t_draw	draw;
	t_rect	area;
};

typedef struct s_image
{
	void	*image;
	int		*pixels;
	int		bpp;
	int		line_size;
	int		endian;
}					t_image;

struct			s_env
{
	void	*mlx;
	void	*win;
	t_image	image;
	t_calc	calc;
	float	ca;
	float	cb;
	int		color;
};

extern const int			g_colors[3][9];

int		ft_strequ(char *str1, char *str2);
void	ft_putstr_fd(char *str, int fd);
/*
**	INIT FUNCTIONS
*/

int		init_mlx(t_env *env);
int		init_mlx_events(t_env *env);

/*
**	EVENT FUNCTIONS
*/

int		mouse_events(int button, int x, int y, void *param);
int		keyboard_events(int keycode, void *param);

/*
**	DRAWING FUNCTIONS
*/
int		draw_julia(t_env *env, t_calc *calc);
int		draw_mandelbrot(t_env *env, t_calc *calc);
int		draw_burningship(t_env *env, t_calc *calc);
int		ft_image_put_pixel(t_image *image, int x, int y, int color);

#endif
