/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 11:44:25 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/04 14:28:22 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	zoom_fractale_less(t_all *all)
{
	float diffx1;
	float diffx2;
	float diffy1;
	float diffy2;

	if (AF->iter_max > 250)
		AF->iter_max *= 0.9;
	diffx1 = (AF->x2 - AF->x1);
	diffx2 = (AF->x2 - AF->x1);
	diffy1 = (AF->y2 - AF->y1);
	diffy2 = (AF->y2 - AF->y1);
	diffx1 = (AH->mouse_x / WINW) * diffx1;
	diffx2 = ((WINW - AH->mouse_x) / WINW) * diffx2;
	diffy1 = (AH->mouse_y / WINH) * diffy1;
	diffy2 = ((WINH - AH->mouse_y) / WINH) * diffy2;
	AF->x1 -= diffx1 / 10;
	AF->x2 += diffx2 / 10;
	AF->y1 -= diffy1 / 10;
	AF->y2 += diffy2 / 10;
	ZOOMX = WINW / (AF->x2 - AF->x1);
	ZOOMY = WINH / (AF->y2 - AF->y1);
	return (0);
}

static int	zoom_fractale_more(t_all *all)
{
	float diffx1;
	float diffx2;
	float diffy1;
	float diffy2;

	if (AF->iter_max < 800)
		AF->iter_max *= 1.05;
	diffx1 = (AF->x2 - AF->x1);
	diffx2 = (AF->x2 - AF->x1);
	diffy1 = (AF->y2 - AF->y1);
	diffy2 = (AF->y2 - AF->y1);
	diffx1 = (AH->mouse_x / WINW) * diffx1;
	diffx2 = ((WINW - AH->mouse_x) / WINW) * diffx2;
	diffy1 = (AH->mouse_y / WINH) * diffy1;
	diffy2 = ((WINH - AH->mouse_y) / WINH) * diffy2;
	AF->x1 += diffx1 / 10;
	AF->x2 -= diffx2 / 10;
	AF->y1 += diffy1 / 10;
	AF->y2 -= diffy2 / 10;
	ZOOMX = WINW / (AF->x2 - AF->x1);
	ZOOMY = WINH / (AF->y2 - AF->y1);
	return (0);
}


static int	zoom_triangle_more(t_all *all)
{
	if (AF->iter_max <= 5000000)
		AF->iter_max *= 1.2;
	if (AH->coef_triangle < 100)
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
	if (AF->choose_fractal == 7  && (id == MORE || id == 6))
		zoom_triangle_more(all);
	else if (AF->choose_fractal == 7 && (id == LESS || id == 7))
		zoom_triangle_less(all);
	else if (id == MORE || id == 6)
		zoom_fractale_more(all);
	else
		zoom_fractale_less(all);
	return (0);
}
