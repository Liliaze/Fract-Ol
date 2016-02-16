/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 13:57:50 by dboudy            #+#    #+#             */
/*   Updated: 2016/02/16 17:03:06 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	key_press(int keycode, t_all *all)
{
	printf("keycode = %d\n", keycode);
	if (keycode == ECHAP)
		error(all, "Thanks, good bye !", 1);
	if (keycode == DEL)
		clear_image(all);
	//mlx_clear_window(MLX, WIN);
	return (1);
}

static int	mouse_stop(int button, int x, int y, t_all *all)
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

static int	mouse(int button, int x, int y, t_all *all)
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
	return (1);
}

static int	mouse_motion(int x, int y, t_all *all)
{
	if (all->br == 1)
	{
		all->apoint->x1 = all->apoint->x2;
		all->apoint->y1 = all->apoint->y2;
		all->apoint->x2 = x;
		all->apoint->y2 = y;
		bres(all);
	}
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	return (1);
}

void		ft_loop(t_all	*all)
{
	mlx_string_put(MLX, WIN, (WINW - ft_strlen("WELCOME :D") * 10) / 2, 
			(WINH / 2) - 90, PINK, "WELCOME :D");
	mlx_hook(WIN, 2, (1L<<0), key_press, all);
	mlx_hook(WIN, 4, (1L<<2), mouse, all);
	mlx_hook(WIN, 5, (1L<<3), mouse_stop, all);
	mlx_hook(WIN, 6, (1L<<8), mouse_motion, all);
	mlx_loop(MLX);
}
