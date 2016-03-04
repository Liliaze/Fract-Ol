/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:05:51 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/04 10:43:09 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	p(double nb, int power)
{
	double tmp;

	tmp = nb;
	while (--power > 0)
		nb *= tmp;
	return (nb);
}

int	color_pixel(t_all *all, int data)
{
	int pixel;
   
	pixel = AP->y * SIZE_LINE + AP->x * BPP;
   	if (pixel < LAST_PIXEL && pixel > 0)
		((int *)DATA)[pixel] = COLOR * data;
	return (0);
}

int	clear_image(t_all *all)
{
	int	i;

	i = -1;
	while (++i <= LAST_PIXEL)
		((int *)DATA)[i] = COLOR;
	return (0);
}

int	error(t_all	*all, char *text, int code_error)
{
	if (code_error == 0)
	{
		ft_putstr(text);
		exit(1);
	}
	else
	{
		mlx_clear_window(MLX, WIN);
		mlx_string_put(MLX, WIN, (WINW - ft_strlen(text) * 12) / 2, WINH / 2, PINK, text);
	}
	return (0);
}
