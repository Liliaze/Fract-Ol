/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 15:42:25 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/04 10:35:21 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		init_fractale(t_all *all)
{
	AF->iter_max = 350;
	AH->init_fractal = 0;
	ZOOMX = WINW / 2.7;
	ZOOMY = WINH / 2.4;
	AF->x1 = -2.1;
	AF->x2 = 0.6;
	AF->y1 = -1.2;
	AF->y2 = 1.2;
	return (0);
}

static int		init2(t_all	*all)
{
	AF->c_r = (AP->x / ZOOMX + AF->x1);
	AF->c_i = (AP->y / ZOOMY + AF->y1);
	AF->z_r = 0 + AH->motion_x;
	AF->z_i = 0 + AH->motion_x;
	AF->iter = -1;
	return (0);
}

int		mandelbrot3(t_all *all)
{
	double	tmp;

	if (AH->init_fractal)
		init_fractale(all);
	AP->x = -1;
	while (++(AP->x) < WINW)
	{
		AP->y = -1;
		while (++(AP->y) < WINH)
		{
			init2(all);
			while ((AF->z_r * AF->z_r + AF->z_i * AF->z_i) < 4
					&& ++(AF->iter) < AF->iter_max)
			{
				tmp = AF->z_r;
				AF->z_r = p(AF->z_r, 4) - 6 * p(AF->z_r, 2) * p(AF->z_i, 2) + p(AF->z_i, 4) + AF->c_r;
				AF->z_i = ((4 * p(tmp, 3)) * AF->z_i) - 4 * tmp * p(AF->z_i, 3) + AF->c_i;
			}
			if (AF->iter != AF->iter_max)
				color_pixel(all, AF->iter);
		}
	}
	return (0);
}
