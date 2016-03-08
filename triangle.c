/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 16:00:02 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/07 12:23:33 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	init_first_triangle(t_all *all)
{
	ZOOMX = 1;
	ZOOMY = 1;
	AH->init_fractal = 0;
	AH->coef_triangle = 50;
	AF->iter_max = 10000;
	AF->iter = 0;
	AF->x1 = 15;
	AF->y1 = IMGH - 15;
	AF->x2 = IMGW - 15;
	AF->y2 = IMGH - 15;
	AF->x3 = IMGW / 2;
	AF->y3 = 15;
	AP->x = AF->x1;
	AP->y = AF->y1;
	return (0);
}

static int	init_triangle(t_all *all)
{
	AF->iter = 0;
	AP->x = AF->x1;
	AP->y = AF->y1;
	return (0);
}

int			triangle(t_all *all)
{
	int	nb;

	if (AH->init_fractal)
		init_first_triangle(all);
	init_triangle(all);
	while (++(AF->iter) <= AF->iter_max)
	{
		color_pixel(all, AF->iter);
		if ((nb = abs(rand() % 3)) == 0)
		{
			AP->x = ((AP->x + AF->x1) / 2.0) + AH->motion;
			AP->y = ((AP->y + AF->y1) / 2.0) - AH->motion;
		}
		else if (nb == 1)
		{
			AP->x = ((AP->x + AF->x2) / 2.0) - AH->motion;
			AP->y = ((AP->y + AF->y2) / 2.0) + AH->motion;
		}
		else if (nb == 2)
		{
			AP->x = ((AP->x + AF->x3) / 2.0) + AH->motion;
			AP->y = ((AP->y + AF->y3) / 2.0) - AH->motion;
		}
	}
	return (0);
}
