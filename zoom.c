/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 11:44:25 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/07 12:18:13 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	zoom_fractale_less(t_all *all)
{
	float diffx1;
	float diffx2;
	float diffy1;
	float diffy2;

	diffx1 = (AF->x2 - AF->x1);
	diffx2 = (AF->x2 - AF->x1);
	diffy1 = (AF->y2 - AF->y1);
	diffy2 = (AF->y2 - AF->y1);
	diffx1 = (AH->mouse_x / IMGW) * diffx1;
	diffx2 = ((IMGW - AH->mouse_x) / IMGW) * diffx2;
	diffy1 = (AH->mouse_y / IMGH) * diffy1;
	diffy2 = ((IMGH - AH->mouse_y) / IMGH) * diffy2;
	AF->x1 -= diffx1 / 10;
	AF->x2 += diffx2 / 10;
	AF->y1 -= diffy1 / 10;
	AF->y2 += diffy2 / 10;
	ZOOMX = IMGW / (AF->x2 - AF->x1);
	ZOOMY = IMGH / (AF->y2 - AF->y1);
	return (0);
}

static int	zoom_fractale_more(t_all *all)
{
	float diffx1;
	float diffx2;
	float diffy1;
	float diffy2;

	diffx1 = (AF->x2 - AF->x1);
	diffx2 = (AF->x2 - AF->x1);
	diffy1 = (AF->y2 - AF->y1);
	diffy2 = (AF->y2 - AF->y1);
	diffx1 = (AH->mouse_x / IMGW) * diffx1;
	diffx2 = ((IMGW - AH->mouse_x) / IMGW) * diffx2;
	diffy1 = (AH->mouse_y / IMGH) * diffy1;
	diffy2 = ((IMGH - AH->mouse_y) / IMGH) * diffy2;
	AF->x1 += diffx1 / 10;
	AF->x2 -= diffx2 / 10;
	AF->y1 += diffy1 / 10;
	AF->y2 -= diffy2 / 10;
	ZOOMX = IMGW / (AF->x2 - AF->x1);
	ZOOMY = IMGH / (AF->y2 - AF->y1);
	return (0);
}

static int	zoom_triangle_more(t_all *all)
{
	if (AF->iter_max <= 90000000)
		AF->iter_max += 2500;
	if (AH->coef_triangle <= 200)
		AH->coef_triangle += 10;
	AF->x1 -= AH->coef_triangle;
	AF->y1 += AH->coef_triangle;
	AF->x2 += AH->coef_triangle;
	AF->y2 += AH->coef_triangle;
	AF->y3 -= AH->coef_triangle;
	return (0);
}

static int	zoom_triangle_less(t_all *all)
{
	AF->x1 += AH->coef_triangle;
	AF->y1 -= AH->coef_triangle;
	AF->x2 -= AH->coef_triangle;
	AF->y2 -= AH->coef_triangle;
	AF->y3 += AH->coef_triangle;
	return (0);
}

int			to_zoom(t_all *all, int id)
{
	AH->mouse_x -= 100;
	AH->mouse_y -= 100;
	if (AF->choose_fractal == 4 && (id == MORE || id == 6))
		zoom_triangle_more(all);
	else if (AF->choose_fractal == 4 && (id == LESS || id == 7))
		zoom_triangle_less(all);
	else if (id == MORE || id == 6)
		zoom_fractale_more(all);
	else
		zoom_fractale_less(all);
	refresh(all);
	return (0);
}
