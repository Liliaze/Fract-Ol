/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_choose_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 11:27:39 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/05 18:30:14 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	choose_color(t_all *all)
{
	if (AH->mouse_x >= 0 && AH->mouse_x < 100)
		COLOR = BLUEF + AH->mouse_x;
	else if (AH->mouse_x >= 100 && AH->mouse_x < 200)
		COLOR = GREY + AH->mouse_x;
	else if (AH->mouse_x >= 200 && AH->mouse_x < 300)
		COLOR = BLUE + AH->mouse_x - 200;
	else if (AH->mouse_x >= 300 && AH->mouse_x < 400)
		COLOR = GREEN + AH->mouse_x - 300;
	else if (AH->mouse_x >= 400 && AH->mouse_x < 500)
		COLOR = YELLOW - AH->mouse_x;
	else if (AH->mouse_x >= 500 && AH->mouse_x < 600)
		COLOR = ORANGE - AH->mouse_x - 500;
	else if (AH->mouse_x >= 600 && AH->mouse_x < 700)
		COLOR = RED + AH->mouse_x - 600;
	else if (AH->mouse_x >= 700 && AH->mouse_x < 800)
		COLOR = PURPLE - AH->mouse_x - 700;
	refresh(all);
}

void	draw_choose_color(t_all *all)
{
	AP->y = 800;
	while (++AP->y < 900)
	{
		AP->x = -1;
		while (++AP->x <= 800)
		{
			if (AP->x >= 0 && AP->x < 100)
				mlx_pixel_put(MLX, WIN, AP->x, AP->y, BLUEF + AP->x);
			else if (AP->x >= 100 && AP->x < 200)
				mlx_pixel_put(MLX, WIN, AP->x, AP->y, GREY + AP->x - 100);
			else if (AP->x >= 200 && AP->x < 300)
				mlx_pixel_put(MLX, WIN, AP->x, AP->y, BLUE + AP->x - 200);
			else if (AP->x >= 300 && AP->x < 400)
				mlx_pixel_put(MLX, WIN, AP->x, AP->y, GREEN + AP->x - 300);
			else if (AP->x >= 400 && AP->x < 500)
				mlx_pixel_put(MLX, WIN, AP->x, AP->y, YELLOW - AP->x - 400);
			else if (AP->x >= 500 && AP->x < 600)
				mlx_pixel_put(MLX, WIN, AP->x, AP->y, ORANGE - AP->x - 500);
			else if (AP->x >= 600 && AP->x < 700)
				mlx_pixel_put(MLX, WIN, AP->x, AP->y, RED + AP->x - 600);
			else if (AP->x >= 700 && AP->x < 800)
				mlx_pixel_put(MLX, WIN, AP->x, AP->y, PURPLE - AP->x - 700);
		}
	}
}
