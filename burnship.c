/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burnship.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 15:37:34 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/07 11:53:30 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init1(t_all *all)
{
	AH->init_fractal = 0;
	AF->iter_max = 350;
	ZOOMX = IMGW / 2.7;
	ZOOMY = IMGH / 2.4;
	AF->x1 = -2.1;
	AF->x2 = 0.6;
	AF->y1 = -1.2;
	AF->y2 = 1.2;
}

static void	init2(t_all *all)
{
	AF->cr = (AP->x / ZOOMX + AF->x1);
	AF->ci = (AP->y / ZOOMY + AF->y1);
	AF->zr = 0 + AH->motion;
	AF->zi = 0 + AH->motion;
	AF->iter = -1;
}

int			burnship(t_all *all)
{
	if (AH->init_fractal)
		init1(all);
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
				AF->zr = fabs(AF->zr * AF->zr - AF->zi * AF->zi
						+ AF->cr);
				AF->zi = fabs(2 * AF->zi * AF->t + AF->ci);
			}
			if (AF->iter != AF->iter_max && (AP->pixel = (AP->y * SIZE_LINE
							+ AP->x * BPP)) < LAST_PIXEL && AP->pixel >= 0)
				((int *)DATA)[AP->pixel] = COLOR * AF->iter;
		}
	}
	return (0);
}
