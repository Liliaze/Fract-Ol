/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 15:41:50 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/07 11:53:18 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	init_fractale(t_all *all)
{
	AF->iter_max = 300;
	ZOOMX = IMGW / 2;
	ZOOMY = IMGH / 2.4;
	AF->x1 = -1;
	AF->x2 = 1;
	AF->y1 = -1.2;
	AF->y2 = 1.2;
	return (0);
}

static int	init2(t_all *all)
{
	AF->cr = 0.285 + AH->motion;
	AF->ci = 0.01 + AH->motion;
	AF->zr = AP->x / ZOOMX + AF->x1;
	AF->zi = AP->y / ZOOMY + AF->y1;
	AF->iter = -1;
	return (0);
}

int			julia(t_all *all)
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

int			julia2(t_all *all)
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

int			julia3(t_all *all)
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
			while (++(AF->iter) < AF->iter_max &&
					(AF->zr * AF->zr + AF->zi * AF->zi) < 4)
			{
				AF->t = AF->zr;
				AF->zr = (AF->zr * AF->zr * AF->zr * AF->zr)
					- 6 * (AF->zr * AF->zr) * (AF->zi * AF->zi)
					+ (AF->zi * AF->zi * AF->zi * AF->zi) + AF->cr;
				AF->zi = ((4 * (AF->t * AF->t * AF->t)) * AF->zi)
					- 4 * AF->t * (AF->zi * AF->zi * AF->zi) + AF->ci;
			}
			if (AF->iter != AF->iter_max)
				color_pixel(all, AF->iter);
		}
	}
	return (0);
}
