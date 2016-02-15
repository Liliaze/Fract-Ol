/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cercle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 18:08:21 by dboudy            #+#    #+#             */
/*   Updated: 2016/02/15 18:39:34 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_cercle(t_all *all)
{
	int	y;
	int	x;
	int	d;

	d = all->abres->size_bres;
	y = d;
	while (--y > 0)
	{
		x = d;
		while (--x > 0)
		{
				mlx_pixel_put(MLX, WIN, all->apoint->x1 + x / 2, all->apoint->y1 + y / 2, COLOR);
		}
	}
}
