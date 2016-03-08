/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 09:24:54 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/05 19:15:54 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	match_argv(char *name)
{
	if (ft_strcmp(name, "Mandelbrot") == 0 || ft_strcmp(name, "Julia") == 0
			|| ft_strcmp(name, "Burnship") == 0 || ft_strcmp(name,
				"Siepinski") == 0)
		return (1);
	else
		return (0);
}

static int	init_windows(t_all *all)
{
	WINH = 900;
	WINW = 800;
	IMGW = 600;
	IMGH = 600;
	if ((MLX = mlx_init()) == NULL)
		error("mlx_init() don't turn\n", 0);
	if ((WIN = mlx_new_window(MLX, WINW, WINH,
					"Thanks to M. Mandelbrot")) == NULL)
		error("mlx_new_windows() don't turn\n", 0);
	if ((IMG = mlx_new_image(MLX, IMGW, IMGH)) == NULL)
		error("mlx_new_image fail\n", 0);
	if (!(DATA = mlx_get_data_addr(IMG, &BPP, &SIZE_LINE, &ENDIAN)))
		error("mlx_get_data_address fail\n", 0);
	BPP = (BPP / 8) / 4;
	SIZE_LINE = SIZE_LINE / 4;
	LAST_PIXEL = (IMGH * SIZE_LINE + IMGW * BPP);
	return (1);
}

static int	init_struct(t_all *all)
{
	all->awin = (t_win *)ft_memalloc(sizeof(t_win));
	all->apixel = (t_pixel *)ft_memalloc(sizeof(t_pixel));
	all->afrac = (t_frac *)ft_memalloc(sizeof(t_frac));
	all->aimg = (t_image *)ft_memalloc(sizeof(t_image));
	all->ahook = (t_hook *)ft_memalloc(sizeof(t_hook));
	return (1);
}

int			main(int ac, char **argv)
{
	t_all	*all;
	int		i;
	int		pid;
	int		match;

	i = ac;
	all = (t_all*)ft_memalloc(sizeof(t_all));
	srand(time(NULL));
	while (i-- > 1 && (match = match_argv(argv[1])))
	{
		if (!(pid = fork()))
		{
			init_struct(all);
			AF->name = (char *)ft_memalloc(sizeof(char) *
					ft_strlen(argv[i]));
			ft_strcpy(AF->name, argv[i]);
			init_windows(all);
			init_data(all);
			launch_menu(all);
			ft_loop(all);
		}
	}
	if (ac < 2 || !match)
		error("blabla", 3);
	return (0);
}
