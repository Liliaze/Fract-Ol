/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:05:51 by dboudy            #+#    #+#             */
/*   Updated: 2016/02/16 14:06:01 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error(t_all	*all, char *text, int code_error)
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
		if (code_error == 1)
			exit(1);
		else
			exit(1);
	//		menu();
	}
}
