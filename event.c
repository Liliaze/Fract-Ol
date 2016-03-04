/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 13:45:59 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/04 11:49:24 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	refresh(t_all *all)
{
	clear_image(all);
	mlx_clear_window(MLX, WIN);
	if (AF->choose_fractal == 1)
		mandelbrot(all);
	else if (AF->choose_fractal == 2)
		mandelbrot2(all);
	else if (AF->choose_fractal == 3)
		mandelbrot3(all);
	else if (AF->choose_fractal == 4)
		julia(all);
	else if (AF->choose_fractal == 5)
		julia2(all);
	else if (AF->choose_fractal == 6)
		julia3(all);
	else if (AF->choose_fractal == 7)
	{
		triangle(all);
		//AH->coef_triangle = 1;
	}
	else if (AF->choose_fractal == 9)
		burnship(all);
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	return (0);
}

int	launch_fractale(t_all * all, int key)
{
	AH->init_fractal = 1;
	AF->choose_fractal = key - 82;
	return (0);
}

int	move_fractale(t_all * all, int key)
{
	if (AF->choose_fractal == 7)
		move_fractale2(all, key);
	else
		AH->coef_triangle = 1;
	if (key == UP)
	{
		AF->y1 -= 0.05 * AH->coef_triangle;
		AF->y2 -= 0.05 * AH->coef_triangle;
	}
	else if (key == DOWN)
	{
		AF->y1 += 0.05 * AH->coef_triangle;
		AF->y2 += 0.05 * AH->coef_triangle;
	}
	else if (key == LEFT)
	{
		AF->x1 -= 0.05 * AH->coef_triangle;
		AF->x2 -= 0.05 * AH->coef_triangle;
	}
	else if (key == RIGHT)
	{
		AF->x1 += 0.05 * AH->coef_triangle;
		AF->x2 += 0.05 * AH->coef_triangle;
	}
	return (0);
}

int	move_fractale2(t_all * all, int key)
{
	if (key == UP)
		AF->y3 -= 0.05 * AH->coef_triangle;
	else if (key == DOWN)
		AF->y3 += 0.05 * AH->coef_triangle;
	else if (key == LEFT)
		AF->x3 -= 0.05 * AH->coef_triangle;
	else if (key == RIGHT)
		AF->x3 += 0.05 * AH->coef_triangle;
	return (0);
}
