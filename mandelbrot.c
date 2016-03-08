/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 15:42:25 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/07 11:52:59 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	init_fractale(t_all *all)
{
	AF->iter_max = 350;
	ZOOMX = IMGW / 2.7;
	ZOOMY = IMGH / 2.4;
	AF->x1 = -2.1;
	AF->x2 = 0.6;
	AF->y1 = -1.2;
	AF->y2 = 1.2;
	return (0);
}

static int	init2(t_all *all)
{
	AF->cr = (AP->x / ZOOMX + AF->x1);
	AF->ci = (AP->y / ZOOMY + AF->y1);
	AF->zr = 0 + AH->motion;
	AF->zi = 0 + AH->motion;
	AF->iter = -1;
	return (0);
}

int			mandelbrot(t_all *all)
{
	if (AH->init_fractal)
		init_fractale(all);
	AH->init_fractal = 0;
	AP->x = -1;
	while (++(AP->x) < IMGW)
	{
		AP->y = -1;
		while (++(AP->y) < IMGH)
		{
			init2(all);
			while (sqrt(AF->zr * AF->zr + AF->zi * AF->zi) < 4
					&& ++(AF->iter) < AF->iter_max)
			{
				AF->t = AF->zr;
				AF->zr = (AF->zr * AF->zr - AF->zi * AF->zi + AF->cr);
				AF->zi = (2 * AF->zi * AF->t + AF->ci);
			}
			if (AF->iter != AF->iter_max)
				color_pixel(all, AF->iter);
		}
	}
	return (0);
}

int			mandelbrot2(t_all *all)
{
	if (AH->init_fractal)
		init_fractale(all);
	AP->x = -1;
	while (++(AP->x) < IMGW)
	{
		AP->y = -1;
		while (++(AP->y) < IMGH)
		{
			init2(all);
			while ((AF->zr * AF->zr + AF->zi * AF->zi) < 4
					&& ++(AF->iter) < AF->iter_max)
			{
				AF->t = AF->zr;
				AF->zr = (AF->zr * AF->zr * AF->zr)
					- 3 * AF->zr * (AF->zi * AF->zi) + AF->cr;
				AF->zi = ((3 * (AF->t * AF->t)) * AF->zi)
					- (AF->zi * AF->zi * AF->zi) + AF->ci;
			}
			if (AF->iter != AF->iter_max)
				color_pixel(all, AF->iter);
		}
	}
	return (0);
}

int			mandelbrot3(t_all *all)
{
	if (AH->init_fractal)
		init_fractale(all);
	AP->x = -1;
	while (++(AP->x) < IMGW)
	{
		AP->y = -1;
		while (++(AP->y) < IMGH)
		{
			init2(all);
			while ((AF->zr * AF->zr + AF->zi * AF->zi) < 4
					&& ++(AF->iter) < AF->iter_max)
			{
				AF->t = AF->zr;
				AF->zr = (AF->zr * AF->zr * AF->zr * AF->zr)
					- 6 * (AF->zr * AF->zr) * (AF->zi * AF->zi)
					+ (AF->zi * AF->zi * AF->zi * AF->zi) + AF->cr;
				AF->zi = 4 * (AF->t * AF->t * AF->t) * AF->zi
					- 4 * AF->t * (AF->zi * AF->zi * AF->zi) + AF->ci;
			}
			if (AF->iter != AF->iter_max)
				color_pixel(all, AF->iter);
		}
	}
	return (0);
}
