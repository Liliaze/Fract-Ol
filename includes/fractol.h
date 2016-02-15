/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 11:52:57 by dboudy            #+#    #+#             */
/*   Updated: 2016/02/15 18:10:16 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN		all->awin->win
# define MLX		all->awin->mlx
# define WINW		all->awin->width
# define WINH		all->awin->height
# define MAP		all->amap->map
# define NAME		all->amap->name
# define TNAME		all->amap->the_name
# define COLOR		all->apoint->color1
# define ECART		all->apoint->ecart_x
# define COEFZ		all->apoint->coef_z
# define COEFY		all->apoint->coef_y
# define Z1			ft_atoi(all->amap->map[y][x]) * COEFZ
# define Z2X		ft_atoi(all->amap->map[y][x + 1]) * COEFZ
# define Z2Y		ft_atoi(all->amap->map[y + 1][x]) * COEFZ
# define ZMAX		all->amap->z_max
# define ZMIN		all->amap->z_min
# define SW			all->amap->scalew
# define SH			all->amap->scaleh

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
# include <stdio.h>

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	void			*image;
	int				width;
	int				height;
}					t_win;

typedef struct		s_point
{
	int				x1;
	int				y1;
	int				z1;
	int				x2;
	int				y2;
	int				z2;
	int				color1;
	int				color2;
	float			coef_x;
	float			coef_z;
	float			coef_y;
}					t_point;

typedef struct		s_map
{
	int				scaleh;
	int				scalew;
	int				z_max;
	int				z_min;
	int				nb_x;
	int				nb_y;
}					t_map;

typedef struct		s_bres
{
	int				dx;
	int				dy;
	int				incx;
	int				incy;
	int				size_bres;
}					t_bres;

typedef struct		s_all
{
	t_point			*apoint;
	t_map			*amap;
	t_win			*awin;
	t_bres			*abres;
	int				in_menu;
	int				br;
}					t_all;

int		bres(t_all *all);
int		bres_paint(t_all *all);
int		bres_del(t_all *all);
void	draw_cercle(t_all *all);

#endif
