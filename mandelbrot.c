/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 15:42:25 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/04 16:36:28 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		init_fractale(t_all *all)
{
	AF->iter_max = 350;
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

int		mandelbrot(t_all *all)
{
	double	tmp;

	if (AH->init_fractal)
		init_fractale(all);
	AH->init_fractal = 0;
	AP->x = -1;
	while (++(AP->x) < WINW)
	{
		AP->y = -1;
		while (++(AP->y) < WINH)
		{
			init2(all);
			while (sqrt(AF->z_r * AF->z_r + AF->z_i * AF->z_i) < 4
					&& ++(AF->iter) < AF->iter_max)
			{
				tmp = AF->z_r;
				AF->z_r = (AF->z_r * AF->z_r - AF->z_i * AF->z_i + AF->c_r);
				AF->z_i = (2 * AF->z_i * tmp + AF->c_i);
			}
			if (AF->iter != AF->iter_max && (AP->pixel =
						(AP->y * SIZE_LINE + AP->x * BPP)) < LAST_PIXEL && AP->pixel >= 0)
				((int *)DATA)[AP->pixel] = AF->iter * COLOR;
		}
	}
	return (0);
}
