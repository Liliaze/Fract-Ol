/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 13:57:50 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/04 18:38:17 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	change_nb_iter(t_all *all, int key)
{
	if (key == 24 && AF->iter_max < 50000)
		AF->iter_max *= 1.5;
	else
		AF->iter_max -= 100.0;
	return (0);
}

static int	key_press(int key, t_all *all)
{
	if (key == ECHAP)
		error(all, "Thanks, good bye !", 0);
	else if (key == 3 && AH->active_color == 1)
		AH->active_color = 0;
	else if (key == 3)
		AH->active_color = 1;
	else if (key == SPACE && AH->active_motion == 1)
		AH->active_motion = 0;
	else if (key == SPACE)
		AH->active_motion = 1;
	else if (key == ENTER)
		launch_menu(all);
	else if (all->in_menu && (key >= ONE && key <= NINE))
		launch_fractale(all, key);
	else if (key == 27 || key == 24)
		change_nb_iter(all, key);
	else if (key == LEFT || key == RIGHT || key == UP || key == DOWN)
		move_fractale(all, key);
	else if (key == MORE || key == LESS)
		to_zoom(all, key);
	if (key != ENTER)
		refresh(all);
	return (0);
}

static int	mouse(int button, int x, int y, t_all *all)
{
	if (button == 6 || button == 7)
		to_zoom(all, button);
	x = y;
	refresh(all);
	return (0);
}

static int	paint_motion(int x, int y, t_all *all)
{
	if (AH->active_color_paint && x > 0 && y > 0)
	{
		if (y < 40)
			COLOR = BROWN + x;
		else if (y >= 40 && y < 80)
			COLOR = RED + x;
		else if (y >= 80 && y < 120)
			COLOR = ORANGE + x;
		else if (y >= 120 && y < 160)
			COLOR = YELLOW + x;
		else if (y >= 160 && y < 200)
			COLOR = CYAN - x;
		else if (y >= 200 && y < 240)
			COLOR = BLUEF - x;
	}
	refresh(all);
	return (0);
}

static int	mouse_paint(int button, int x, int y, t_all *all)
{
	if (button == 1 && AH->active_color_paint == 0)
	{
		AH->active_color_paint = 1;
		if (y < 40)
			COLOR = BROWN + x;
		else if (y >= 40 && y < 80)
			COLOR = RED + x;
		else if (y >= 80 && y < 120)
			COLOR = ORANGE + x;
		else if (y >= 120 && y < 160)
			COLOR = YELLOW + x;
		else if (y >= 160 && y < 200)
			COLOR = CYAN - x;
		else if (y >= 200 && y < 240)
			COLOR = BLUEF - x;
	}
	else
		AH->active_color_paint = 0;
	refresh(all);
	return (0);
}

static int	mouse_motion(int x, int y, t_all *all)
{
	AH->mouse_x = x;
	AH->mouse_y = y;
	if (AH->active_motion && x != 0 && y != 0)
	{
		AH->motion_x = (x + y) / ((ZOOMX + ZOOMY) * 2);
		refresh(all);
	}
	else if (AH->active_color && x != 0 && y != 0)
	{
		COLOR = (x * x + y * y) * 50;
		refresh(all);
	}
	return (0);
}

int		ft_loop(t_all	*all)
{
	mlx_hook(WIN, 2, (1L<<0), key_press, all);
	mlx_hook(WIN, 4, (1L<<2), mouse, all);
	mlx_hook(all->apaint->win, 4, (1L<<2), mouse_paint, all);
	mlx_hook(all->apaint->win, 6, (1L<<8), paint_motion, all);
	mlx_hook(WIN, 6, (1L<<8), mouse_motion, all);
	mlx_loop(MLX);
	return (0);
}
