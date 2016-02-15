/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 09:24:54 by dboudy            #+#    #+#             */
/*   Updated: 2016/02/15 18:21:17 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error(t_all	*all, char *text, int code_error)
{
	if (code_error == 0)
	{
		ft_putstr(text);
		exit(1);
	}
	else
	{
		mlx_clear_window(MLX, WIN);
		mlx_string_put(MLX, WIN, (WINW - ft_strlen(text) * 12) / 2, WINH / 2, PINK, text);
		if (code_error == 1)
			exit(1);
		else
			exit(1);
	//		menu();
	}
}

int		key_press(int keycode, t_all *all)
{
	printf("keycode = %d\n", keycode);
	if (keycode == ECHAP)
		error(all, "Thanks, good bye !", 1);
	if (keycode == DEL)
		mlx_clear_window(MLX, WIN);
	return (1);
}

int		mouse_stop(int button, int x, int y, t_all *all)
{
	printf("buttonrelease = %d, x = %d, y = %d\n", button, x, y);
	if (button == 1)
	{
		all->br = 0;
		all->apoint->x2 = 0;
		all->apoint->y2 = 0;
	}
	return (1);
}

int		mouse(int button, int x, int y, t_all *all)
{
	int	d;
	
	printf("button = %d, x = %d, y = %d\n", button, x, y);
	d = 0;
	if (button == 1)
	{
		all->apoint->x2 = x;
		all->apoint->y2 = y;
		COLOR = ((d - x) * (d - x) + (d - y) * (d - y)) * y / 2;
		all->br = 1;
	}
	else if (button == 6 && all->abres->size_bres - 2 > 0)
		all->abres->size_bres -= 2;
	else if (button == 7 && all->abres->size_bres + 2 < 60)
		all->abres->size_bres += 2;
	return (1);
}

int		mouse_motion(int x, int y, t_all *all)
{
	int i;

	i = all->abres->size_bres;
	if (all->br == 1)
	{
			all->apoint->x1 = all->apoint->x2;
			all->apoint->y1 = all->apoint->y2;
			all->apoint->x2 = x;
			all->apoint->y2 = y;
			bres_del(all);
	}
	return (1);
}

int	ft_loop(t_all	*all)
{
	mlx_hook(WIN, 2, (1L<<0), key_press, all);
	mlx_hook(WIN, 4, (1L<<2), mouse, all);
	mlx_hook(WIN, 5, (1L<<3), mouse_stop, all);
	mlx_hook(WIN, 6, (1L<<8), mouse_motion, all);
	mlx_loop(MLX);
	return (1);
}

int		main(void)
{
	t_all	*all;

	all = (t_all*)ft_memalloc(sizeof(t_all));
	all->apoint = (t_point *)ft_memalloc(sizeof(t_point));
	all->awin = (t_win *)ft_memalloc(sizeof(t_win));
	all->amap = (t_map *)ft_memalloc(sizeof(t_map));
	all->abres = (t_bres *)ft_memalloc(sizeof(t_bres));
	if ((MLX = mlx_init()) == NULL)
		error(all, "mlx_init() don't turn\n", 0);
	WINH = 1080;
	WINW = 1680;
	all->abres->size_bres = 1;
	if ((WIN = mlx_new_window(MLX, WINW, WINH, "Thanks to M. Mandelbrot")) == NULL)
		error(all, "mlx_new_windows() don't turn\n", 0);
	ft_loop(all);
	return (0);
}
