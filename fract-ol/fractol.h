/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:00:19 by jonghan           #+#    #+#             */
/*   Updated: 2024/11/19 22:07:39 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./ft_printf/ft_printf.h"
# include "./minilibx-linux/mlx.h"
# include <math.h>

// display
# define WIDTH 640
# define HEIGHT 640
# define ZOOM 0.75
# define MAX_ITER 100

// cmd
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_PLUS 65451
# define KEY_MINUS 65453
# define KEY_BONUS_1 49
# define KEY_BONUS_2 50
# define MOUSE_WHELL_UP 4
# define MOUSE_WHELL_DOWN 5
# define KEY_R 114
# define KEY_G 103

typedef struct s_julia
{
	double	x;
	double	y;
}			t_julia;

typedef struct s_bonus
{
	int		zn;
	int		cn;
	int		option;
}			t_bonus;

typedef struct s_display
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bit;
	int		size;
	int		endian;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	char	*fractal;
	int		julia;
	t_julia	julia_v;
	int		color;
	int		is_gray;
	int		bonus;
	t_bonus	bonus_v;
}			t_display;

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

// color
int			rgb_to_int(int r, int g, int b);
int			get_color(int iter, int seed);

// math
t_complex	complex_square(t_complex c);
double		complex_abs(t_complex c);
t_complex	complex_pow(t_complex c, int n);

// draw
void		draw_fractal(t_display *d);

// event
int			mouse_event(int button, int x, int y, t_display *d);
int			keyboard_event(int key, t_display *d);

// error
int			ar_error(void);
int			no_match(void);
int			float_error(void);
int			int_error(void);
int			help(void);
int			mandelbrot_error(void);

// utils
int			check_ar(int ac, char **av);
double		ft_atod(char *str);

// set
void		set_m(t_display *d);
void		set_j(t_display *d, char **av);
void		set_b(t_display *d, char **av);

// iter_count
int			iter_count_m(t_complex c);
int			iter_count_j(t_complex c, t_display d);
int			iter_count_b(t_complex c, t_display d);
int			iter_count_b2(t_complex c);

#endif