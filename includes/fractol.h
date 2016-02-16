/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 11:52:57 by dboudy            #+#    #+#             */
/*   Updated: 2016/02/16 16:56:24 by dboudy           ###   ########.fr       */
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
# define WINW		all->awin->width
# define WINH		all->awin->height
# define NAME		all->afrac->name
# define COLOR		all->apoint->color1
# define R			all->apoint->r
# define G			all->apoint->g
# define B			all->apoint->b

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
# define NINE		92
# define ONE2		18
# define NINE2		28

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"
# include <stdio.h> //a sup a la fin

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
}					t_image;

typedef struct		s_point
{
	int				x1;
	int				y1;
	int				z1;
	int				x2;
	int				y2;
	int				z2;
	int				color1;
	int				r;
	int				g;
	int				b;
}					t_point;

typedef struct		s_bres
{
	int				dx;
	int				dy;
	int				incx;
	int				incy;
}					t_bres;

typedef struct		s_frac
{
	char			*name;
}					t_frac;

typedef struct		s_all
{
	t_point			*apoint;
	t_win			*awin;
	t_image			*aimg;
	t_bres			*abres;
	t_frac			*afrac;
	int				br;
}					t_all;

int		bres(t_all *all);
void	ft_loop(t_all *all);
void	error(t_all *all, char *text, int code_error);
void	find_pixel(t_all *all);
int		clear_image(t_all *all);
int		new_image(t_all *all);

#endif
