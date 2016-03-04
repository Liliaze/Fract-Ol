/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 11:52:57 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/04 18:25:25 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN		all->awin->win
# define MLX		all->awin->mlx
# define IMG		all->aimg->image
# define DATA		all->aimg->image_data
# define BPP		all->aimg->bpp
# define SIZE_LINE	all->aimg->size_line
# define ENDIAN		all->aimg->endian
# define LAST_PIXEL	all->aimg->last_pixel
# define WINW		all->awin->width
# define WINH		all->awin->height
# define ZOOMX		all->ahook->zoom_x
# define ZOOMY		all->ahook->zoom_y
# define COLOR		all->apixel->color1
# define AF			all->afrac
# define AP			all->apixel
# define AH			all->ahook

# define BLACK		0x00000000
# define BROWN		0x00663300
# define GREY		0x007F7F7F
# define WHITE		0x00FFFFFF
# define RED		0x00FF0000
# define ORANGE		0x00FFBC00
# define YELLOW		0x00FFFF00
# define GREEN		0x0000FF00
# define GREENF		0x0000FF88
# define CYAN		0x0033FFFF
# define BLUE		0x0011AAFF
# define BLUEF		0x001111FF
# define PINK		0x00ED22ED
# define SALMON		0x00FF7F7F
# define PURPLE 	0x00882289

# define ECHAP		53
# define ENTER		36
# define DEL		51
# define UP			126
# define DOWN		125
# define LEFT		123
# define RIGHT		124
# define W			13
# define A			0
# define S			1
# define D			2
# define Q			12
# define E			14
# define LESS		78
# define MORE		69
# define SPACE		49
# define ONE		83
# define TWO		84
# define THREE		85
# define FOUR		86
# define FIVE		87
# define SIX		88
# define SEVEN		89
# define EIGHT		91
# define NINE		92
//# define ONE2		18
//# define TWO2		19
//# define THREE2		20
//# define FOUR2		21

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"
# include <stdio.h> //a sup a la fin
# include <time.h>

typedef struct		s_paint
{
	void			*mlx;
	void			*win;

}					t_paint;

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
}					t_win;

typedef struct		s_image
{
	void			*image;
	char			*image_data;
	int				bpp;
	int				size_line;
	int				endian;
	int				last_pixel;
}					t_image;

typedef struct		s_pixel
{
	int				color1;
	int				pixel;
	int				x;
	int				y;
}					t_pixel;

typedef struct		s_hook
{
	int				init_fractal;
	int				active_motion;
	int				active_color;
	int				active_color_paint;
	int				coef_triangle;
	float			motion_x;
	float			motion_y;
	float			mouse_x;
	float			mouse_y;
	float			move_x;
	float			move_y;
	float			zoom_x;
	float			zoom_y;
}					t_hook;

typedef struct		s_frac
{
	int				iter_max;
	int				iter;
	int				choose_fractal;
	float			x1;
	float			x2;
	float			x3;
	float			y1;
	float			y2;
	float			y3;
	int				padding;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
}					t_frac;

typedef struct		s_all
{
	t_paint			*apaint;
	t_win			*awin;
	t_image			*aimg;
	t_frac			*afrac;
	t_pixel			*apixel;
	t_hook			*ahook;
	int				in_menu;
	int				padding;
}					t_all;

double	p(double nb, int power);
int		ft_loop(t_all *all);
int		error(t_all *all, char *text, int code_error);
//void	create_paint(t_all * all);
int		color_pixel(t_all *all, int data);
int		launch_menu(t_all *all);
int		clear_image(t_all *all);
int		new_image(t_all *all);
int		launch_fractale(t_all *all, int key);
int		refresh(t_all *all);
int		mandelbrot(t_all *all);
int		mandelbrot2(t_all *all);
int		mandelbrot3(t_all *all);
int		julia(t_all *all);
int		julia2(t_all *all);
int		julia3(t_all *all);
int		burnship(t_all *all);
int		triangle(t_all *all);
int		to_zoom(t_all *all, int key);
int		move_fractale(t_all *all, int key);
int		move_fractale2(t_all *all, int key);

#endif
