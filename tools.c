/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:05:51 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/07 12:23:29 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		color_pixel(t_all *all, int data)
{
	int pixel;

	if (AP->y < 600 && AP->x < 600 && AP->y > 0 && AP->x > 0)
	{
		pixel = AP->y * SIZE_LINE + AP->x * BPP;
		if (pixel < LAST_PIXEL && pixel > 0)
			((int *)DATA)[pixel] = COLOR * data;
	}
	return (0);
}

int		clear_image(t_all *all)
{
	int	i;

	i = -1;
	while (++i <= LAST_PIXEL)
		((int *)DATA)[i] = COLOR;
	return (0);
}

void	error(char *text, int code_error)
{
	if (code_error == 0)
	{
		ft_trace_str("31", text);
		ft_putstr("\n");
		exit(1);
	}
	else if (code_error == 3)
	{
		ft_trace_str("32", "Les arguments disponibles sont :\n");
		ft_trace_str("33", "{Mandelbrot || Julia || Burnship || Siepinski}\n");
		ft_trace_str("34", "Enjoy ;)\n");
		exit(1);
	}
}
