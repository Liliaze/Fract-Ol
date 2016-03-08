/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 13:45:59 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/07 12:22:18 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	change_nb_iter_or_power(t_all *all, int key)
{
	if (key == 47 && AF->choose_fractal == 4 && AF->iter_max < 9000000)
		AF->iter_max *= 1.5;
	else if (key == 47 && AF->iter_max < 30000)
		AF->iter_max *= 1.5;
	else if (key == 43 && AF->iter_max > 350)
		AF->iter_max *= 0.5;
	else if (key >= ONE && key <= THREE)
		AF->power = key - 82;
	else if (key >= ONE2 && key <= THREE2)
		AF->power = key - 17;
	refresh(all);
	return (0);
}

int	refresh(t_all *all)
{
	clear_image(all);
	if (AF->choose_fractal == 1 && AF->power == 1)
		mandelbrot(all);
	else if (AF->choose_fractal == 1 && AF->power == 2)
		mandelbrot2(all);
	else if (AF->choose_fractal == 1 && AF->power == 3)
		mandelbrot3(all);
	else if (AF->choose_fractal == 2 && AF->power == 1)
		julia(all);
	else if (AF->choose_fractal == 2 && AF->power == 2)
		julia2(all);
	else if (AF->choose_fractal == 2 && AF->power == 3)
		julia3(all);
	else if (AF->choose_fractal == 3)
		burnship(all);
	else if (AF->choose_fractal == 4)
		triangle(all);
	mlx_put_image_to_window(MLX, WIN, IMG, 100, 100);
	return (0);
}

int	launch_fractale_or_menu(t_all *all)
{
	init_data(all);
	mlx_clear_window(MLX, WIN);
	if (all->in_menu == 0)
		launch_menu(all);
	else
	{
		all->in_menu = 0;
		if (!(ft_strcmp(AF->name, "Mandelbrot")))
			AF->choose_fractal = 1;
		else if (!(ft_strcmp(AF->name, "Julia")))
			AF->choose_fractal = 2;
		else if (!(ft_strcmp(AF->name, "Burnship")))
			AF->choose_fractal = 3;
		else if (!(ft_strcmp(AF->name, "Siepinski")))
			AF->choose_fractal = 4;
		mlx_string_put(MLX, WIN, (WINW - ft_strlen(AF->name) * 10) / 2,
				45, CYAN, AF->name);
		draw_choose_color(all);
		refresh(all);
	}
	return (0);
}

int	move_fractale(t_all *all, int key)
{
	AH->coef_triangle = 1;
	if (key == UP)
	{
		AF->y1 *= 0.95 * AH->coef_triangle;
		AF->y2 *= 0.95 * AH->coef_triangle;
	}
	else if (key == DOWN)
	{
		AF->y1 *= 1.05 * AH->coef_triangle;
		AF->y2 *= 1.05 * AH->coef_triangle;
	}
	else if (key == LEFT)
	{
		AF->x1 *= 0.95 * AH->coef_triangle;
		AF->x2 *= 0.95 * AH->coef_triangle;
	}
	else if (key == RIGHT)
	{
		AF->x1 *= 1.05 * AH->coef_triangle;
		AF->x2 *= 1.05 * AH->coef_triangle;
	}
	refresh(all);
	return (0);
}

int	move_fractale2(t_all *all, int key)
{
	if (key == UP && (AF->y1 -= 0.05 * AH->coef_triangle))
	{
		AF->y2 -= 0.05 * AH->coef_triangle;
		AF->y3 -= 0.05 * AH->coef_triangle;
	}
	else if (key == DOWN)
	{
		AF->y1 += 0.05 * AH->coef_triangle;
		AF->y2 += 0.05 * AH->coef_triangle;
		AF->y3 += 0.05 * AH->coef_triangle;
	}
	else if (key == LEFT)
	{
		AF->x1 -= 0.05 * AH->coef_triangle;
		AF->x2 -= 0.05 * AH->coef_triangle;
		AF->x3 -= 0.05 * AH->coef_triangle;
	}
	else if (key == RIGHT)
	{
		AF->x1 += 0.05 * AH->coef_triangle;
		AF->x2 += 0.05 * AH->coef_triangle;
		AF->x3 += 0.05 * AH->coef_triangle;
	}
	refresh(all);
	return (0);
}
