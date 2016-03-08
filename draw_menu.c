/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 16:59:19 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/05 20:02:47 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_arc(t_all *all)
{
	int	y;
	int	x;
	int	d;
	int	e;
	int	gap;

	d = WINW * 0.18;
	e = (WINW - 2 * d) / 2;
	y = d * 0.95;
	while (--y > 0)
	{
		x = d * 2;
		while (--x > 0)
		{
			gap = (d - x) * (d - x) + (d - y) * (d - y);
			if (gap < d * d * 0.5 && gap > d * d * 0.4)
				mlx_pixel_put(MLX, WIN, x + e, 50 + y + e * 0.3, BLUEF);
			else if (gap < d * d * 0.6 && gap > d * d * 0.4)
				mlx_pixel_put(MLX, WIN, x + e, 50 + y + e * 0.3, GREENF);
			else if (gap < d * d * 0.7 && gap > d * d * 0.4)
				mlx_pixel_put(MLX, WIN, x + e, 50 + y + e * 0.3, ORANGE);
			else if (gap < d * d * 0.8 && gap > d * d * 0.4)
				mlx_pixel_put(MLX, WIN, x + e, 50 + y + e * 0.3, RED);
		}
	}
}

static void	draw_background(t_all *all)
{
	int		y;
	int		x;
	int		d;

	d = WINW / 8;
	y = -1;
	while (++y < WINH)
	{
		x = -1;
		while (++x < WINW)
		{
			if (((x < WINW / 12 || x > WINW - WINW / 12) ||
					(y < WINH / 12 || y > WINH - WINH / 12)) && y < WINH / 2)
				mlx_pixel_put(MLX, WIN, x, y, ((d - x) * (d - x) + (d - y)
							* (d - y)) * y / 2);
			else if (((x < WINW / 12 || x > WINW - WINW / 12) ||
					(y < WINH / 12 || y > WINH - WINH / 12)) && y > WINH / 2)
				mlx_pixel_put(MLX, WIN, x, y, ((d - x) * (d - x) + (d - y)
							* (d - y)) / y);
		}
	}
}

static int	draw_str_menu(t_all *all)
{
	mlx_string_put(MLX, WIN, (WINW - 100) / 2,
			(WINH / 2) - 120, PINK, "WELCOME :D");
	mlx_string_put(MLX, WIN, (WINW - 240) / 2,
			WINH / 2 - 90, PINK, "IN THE WORLD OF FRACTALS");
	mlx_string_put(MLX, WIN, (WINW - 290) / 2, WINH / 2 - 30, RED,
			"====== ENTER TO START ======");
	mlx_string_put(MLX, WIN, (WINW - ft_strlen(AF->name) * 10) / 2,
			WINH / 2, YELLOW, AF->name);
	mlx_string_put(MLX, WIN, (WINW - 140) / 2, WINH / 2 + 60, GREEN,
			"ARROWS to move");
	mlx_string_put(MLX, WIN, (WINW - 380) / 2, WINH / 2 + 90, GREEN,
			"'-' or '+' of keypad or MOUSE to zoom");
	mlx_string_put(MLX, WIN, (WINW - 380) / 2, WINH / 2 + 120, GREEN,
			"'<' or '>' to change nb of iteration");
	mlx_string_put(MLX, WIN, (WINW - 230) / 2, WINH / 2 + 150, GREEN,
			"SPACE to active motion");
	mlx_string_put(MLX, WIN, (WINW - 290) / 2, WINH / 2 + 180, GREEN,
			"C to active my special mode");
	mlx_string_put(MLX, WIN, (WINW - 310) / 2, WINH / 2 + 210, GREEN,
			"'1', '2', '3' to change power");
	return (0);
}

int			launch_menu(t_all *all)
{
	all->in_menu = 1;
	draw_background(all);
	draw_arc(all);
	draw_str_menu(all);
	return (0);
}
