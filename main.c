/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 09:24:54 by dboudy            #+#    #+#             */
/*   Updated: 2016/02/16 17:03:09 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


/*void	find_pixel(t_all	*all)
{
	int		i;

	i = all->apoint->y1 * SIZE_LINE + all->apoint->x1 * BPP;
	((int *)DATA)[i] = COLOR;
}*/
int		clear_image(t_all *all)
{
	int	i;
	int last_pixel;

	i = 0;
	last_pixel = WINH * SIZE_LINE + WINW * BPP;
	while (i <= last_pixel)
	{
		((int *)DATA)[i] = BLACK;
		i++;
	}
	return (1);
}

int		new_image(t_all	*all)
{
	if ((WIN = mlx_new_window(MLX, WINW, WINH, "Thanks to M. Mandelbrot")) == NULL)
		error(all, "mlx_new_windows() don't turn\n", 0);
	if ((IMG = mlx_new_image(MLX, WINW, WINH)) == NULL)
		error(all, "mlx_new_image fail\n", 0);
	if ((DATA = mlx_get_data_addr(IMG, &BPP, &SIZE_LINE, &ENDIAN)) == NULL)
		error(all, "mlx_get_data_address fail\n", 0);
	BPP = (BPP / 8) / 4;
	SIZE_LINE = SIZE_LINE / 4;
	return (1);
}

int		main(void)
{
	t_all	*all;

	all = (t_all*)ft_memalloc(sizeof(t_all));
	all->apoint = (t_point *)ft_memalloc(sizeof(t_point));
	all->awin = (t_win *)ft_memalloc(sizeof(t_win));
	all->abres = (t_bres *)ft_memalloc(sizeof(t_bres));
	all->afrac = (t_frac *)ft_memalloc(sizeof(t_frac));
	all->aimg = (t_image *)ft_memalloc(sizeof(t_image));
	if ((MLX = mlx_init()) == NULL)
		error(all, "mlx_init() don't turn\n", 0);
	WINH = 600;
	WINW = 800;
	COLOR = YELLOW;
	new_image(all);
	ft_loop(all);
	return (0);
}
