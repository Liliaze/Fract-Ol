/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 16:59:19 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/04 18:38:14 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_arc(t_all *all)
{
	int		y;
	int		x;
	float	d;
	float	e;
	float	gap;

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
				mlx_pixel_put(MLX, WIN, x + e, y + e * 0.3, BLUEF);
			else if (gap < d * d * 0.6 && gap > d * d * 0.4)
				mlx_pixel_put(MLX, WIN, x + e, y + e * 0.3, GREENF);
			else if (gap < d * d * 0.7 && gap > d * d * 0.4)
				mlx_pixel_put(MLX, WIN, x + e, y + e * 0.3, ORANGE);
			else if (gap < d * d * 0.8 && gap > d * d * 0.4)
				mlx_pixel_put(MLX, WIN, x + e, y + e * 0.3, RED);
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
	char	*enter;

	enter = "Please the NUMBER of your fractal.";
	mlx_string_put(MLX, WIN, (WINW - ft_strlen("WELCOME :D") * 10) / 2,
			(WINH / 2) - 90, PINK, "WELCOME :D");
	mlx_string_put(MLX, WIN, (WINW - ft_strlen(enter) * 10) / 2, WINH / 2,
			RED, enter);
	mlx_string_put(MLX, WIN, (WINW - 140) / 2,
				WINH / 2 + 30, GREEN, "1 - Mandelbrot");
	mlx_string_put(MLX, WIN, (WINW - 150) / 2,
				WINH / 2 + 60, GREEN, "2 - Mandelbrot2");
	mlx_string_put(MLX, WIN, (WINW - 150) / 2,
				WINH / 2 + 90, GREEN, "3 - Mandelbrot3");
	mlx_string_put(MLX, WIN, (WINW - 90) / 2,
				WINH / 2 + 120, GREEN, "4 - Julia");
	mlx_string_put(MLX, WIN, (WINW - 100) / 2,
				WINH / 2 + 150, GREEN, "5 - Julia2");
	mlx_string_put(MLX, WIN, (WINW - 100) / 2,
				WINH / 2 + 180, GREEN, "6 - Julia3");
	mlx_string_put(MLX, WIN, (WINW - 250) / 2,
				WINH / 2 + 210, GREEN, "7 - Triangle de Siepinski");
	mlx_string_put(MLX, WIN, (WINW - 120) / 2,
				WINH / 2 + 240, GREEN, "8 - Burnship");
	mlx_string_put(MLX, WIN, (WINW - 150) / 2,
				WINH / 2 + 270, GREEN, "9 - in progress");
	return (0);
}

int			launch_menu(t_all *all)
{
	all->in_menu = 1;
	mlx_clear_window(MLX, WIN);
	COLOR = BLUE;
	ZOOMX = 1;
	ZOOMY = 1;
	AH->motion_x = 0;
	AH->motion_y = 0;
	AH->mouse_x = 0;
	AH->mouse_y = 0;
	AH->move_x = 0;
	AH->move_y = 0;
	AH->zoom_x = 0;
	AH->zoom_y = 0;
	draw_background(all);
	draw_arc(all);
	draw_str_menu(all);
	return (0);
}
