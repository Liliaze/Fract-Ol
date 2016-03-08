/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 13:57:50 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/07 12:30:36 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	key_press(int key, t_all *all)
{
	if (key == ECHAP)
		error("Thanks, good bye !", 0);
	else if (!all->in_menu && key == SPACE && AH->active_motion == 0)
		AH->active_motion = 1;
	else if (!all->in_menu && key == SPACE)
		AH->active_motion = 0;
	else if (key == 8 && AH->active_color == 0)
		AH->active_color = 1;
	else if (!all->in_menu && key == 8)
		AH->active_color = 0;
	else if (key == ENTER)
		launch_fractale_or_menu(all);
	else if (!all->in_menu && (key == 47 || key == 43 || (key >= ONE2 &&
				key <= THREE2) || (key >= ONE && key <= THREE)))
		change_nb_iter_or_power(all, key);
	else if (!all->in_menu && AF->choose_fractal != 4 && (key == LEFT ||
				key == RIGHT || key == UP || key == DOWN))
		move_fractale(all, key);
	else if (!all->in_menu && (key == LEFT || key == RIGHT ||
				key == UP || key == DOWN))
		move_fractale2(all, key);
	else if (!all->in_menu && (key == MORE || key == LESS))
		to_zoom(all, key);
	return (0);
}

static int	mouse(int button, int x, int y, t_all *all)
{
	if (!all->in_menu && button == 1 && x > 0 && x < 800 && y > 0 && y < 800)
	{
		COLOR = (x * x + y * y) / y * x;
		refresh(all);
	}
	else if (!all->in_menu && button == 1 && x > 0 && x < 800
			&& y > 800 && y < 900)
	{
		choose_color(all);
		AH->button1 = 1;
	}
	else if (!all->in_menu && (button == 6 || button == 7))
		to_zoom(all, button);
	return (0);
}

static int	mouse_motion(int x, int y, t_all *all)
{
	AH->mouse_x = x;
	AH->mouse_y = y;
	if (!all->in_menu && AH->active_motion)
	{
		AH->motion = (x + y - 200) / (ZOOMX + ZOOMY);
		refresh(all);
	}
	if (!all->in_menu && (AH->active_color || AH->button1)
			&& x > 0 && x < 800 && y > 800 && y < 900)
		choose_color(all);
	else if (!all->in_menu && AH->active_color)
	{
		COLOR = (x * x + y * y) * 50;
		refresh(all);
	}
	return (0);
}

static int	mouse_stop(int button, int x, int y, t_all *all)
{
	if (!all->in_menu && button == 1)
	{
		AH->button1 = 0;
		AH->mouse_x = x;
		AH->mouse_y = y;
	}
	return (1);
}

int			ft_loop(t_all *all)
{
	mlx_hook(WIN, 2, (1L << 0), key_press, all);
	mlx_hook(WIN, 4, (1L << 2), mouse, all);
	mlx_hook(WIN, 5, (1L << 3), mouse_stop, all);
	mlx_hook(WIN, 6, (1L << 8), mouse_motion, all);
	mlx_loop(MLX);
	return (0);
}
