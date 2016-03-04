/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 15:41:50 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/04 11:18:56 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		init_fractale(t_all *all)
{
	AF->iter_max = 300;
	AH->init_fractal = 0;
	ZOOMX = WINW / 2;
	ZOOMY = WINH / 2.4;
	AF->x1 = -1;
	AF->x2 = 1;
	AF->y1 = -1.2;
	AF->y2 = 1.2;
	return (0);
}

static int		init2(t_all	*all)
{
	AF->c_r = 0.285 + AH->motion_x;
	AF->c_i = 0.01 + AH->motion_x;
	AF->z_r = AP->x / ZOOMX + AF->x1;
	AF->z_i = AP->y / ZOOMY + AF->y1;
	AF->iter = -1;
	return (0);
}

int		julia2(t_all *all)
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
				AF->z_r = (AF->z_r * AF->z_r * AF->z_r) - 3 * AF->z_r * (AF->z_i * AF->z_i) + AF->c_r;
				AF->z_i = ((3 * (tmp * tmp)) * AF->z_i) - (AF->z_i * AF->z_i * AF->z_i) + AF->c_i;
			}
			if (AF->iter != AF->iter_max && (AP->pixel =
						(AP->y * SIZE_LINE + AP->x * BPP)) < LAST_PIXEL && AP->pixel >= 0)
				((int *)DATA)[AP->pixel] = AF->iter * COLOR;
		}
	}
	return (0);
}
