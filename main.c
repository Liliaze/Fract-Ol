/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 09:24:54 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/04 18:38:12 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	create_paint(t_all * all)
{
	int	x;
	int	y;

	if ((all->apaint->win = mlx_new_window(MLX, 240, 240,
					"Move me and choose color")) == NULL)
		error(all, "mlx_new_windows() paint don't turn\n", 0);
	y = -1;
	while (++y <= 240)
	{
		x = -1;
		while (++x <= 240)
		{
			if (y < 40 && y > 0)
				mlx_pixel_put(MLX, all->apaint->win, x, y, BROWN + x);
			else if (y >= 40 && y < 80)
				mlx_pixel_put(MLX, all->apaint->win, x, y, RED + x);
			else if (y >= 80 && y < 120)
				mlx_pixel_put(MLX, all->apaint->win, x, y, ORANGE + x);
			else if (y >= 120 && y < 160)
				mlx_pixel_put(MLX, all->apaint->win, x, y, YELLOW + x);
			else if (y >= 160 && y < 200)
				mlx_pixel_put(MLX, all->apaint->win, x, y, CYAN - x);
			else if (y >= 200 && y < 240)
				mlx_pixel_put(MLX, all->apaint->win, x, y, BLUEF - x);
		}
	}
}

static int		init_win(t_all	*all)
{
	WINH = 800;
	WINW = 800;
	if ((WIN = mlx_new_window(MLX, WINW, WINH, "Thanks to M. Mandelbrot")) == NULL)
		error(all, "mlx_new_windows() don't turn\n", 0);
	if ((IMG = mlx_new_image(MLX, WINW, WINH)) == NULL)
		error(all, "mlx_new_image fail\n", 0);
	if ((DATA = mlx_get_data_addr(IMG, &BPP, &SIZE_LINE, &ENDIAN)) == NULL)
		error(all, "mlx_get_data_address fail\n", 0);
	BPP = (BPP / 8) / 4;
	SIZE_LINE = SIZE_LINE / 4;
	LAST_PIXEL = (WINH * SIZE_LINE + WINW * BPP) -1;
	return (1);
}

static int		init_struct(t_all *all)
{
	all->awin = (t_win *)ft_memalloc(sizeof(t_win));
	all->apaint = (t_paint *)ft_memalloc(sizeof(t_paint));
	all->apixel = (t_pixel *)ft_memalloc(sizeof(t_pixel));
	all->afrac = (t_frac *)ft_memalloc(sizeof(t_frac));
	all->aimg = (t_image *)ft_memalloc(sizeof(t_image));
	all->ahook = (t_hook *)ft_memalloc(sizeof(t_hook));
	AH->active_color_paint = 1;
	AH->active_color = 0;
	AH->active_motion = 0;
	return (1);
}

int		main(int ac, char **argv)
{
	t_all	*all;

	all = (t_all*)ft_memalloc(sizeof(t_all));
	init_struct(all);
	if (ac == 2 && !(ft_strcmp(argv[1], "menu")))
	{
		srand((unsigned int)time(NULL));
		if ((MLX = mlx_init()) == NULL)
			error(all, "mlx_init() don't turn\n", 0);
		create_paint(all);
		init_win(all);
		launch_menu(all);
		ft_loop(all);
	}
	else
		error(all, "Liste de l'argument disponible : {menu} enjoy ;)\n", 0);
	return (0);
}
