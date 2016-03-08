/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_frac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 14:13:56 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/07 11:55:04 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_data(t_all *all)
{
	COLOR = BLUE;
	ZOOMX = 1;
	ZOOMY = 1;
	AF->power = 1;
	AH->init_fractal = 1;
	AH->coef_triangle = 1;
	AH->active_motion = 0;
	AH->active_color = 0;
	AH->motion = 0;
	AH->mouse_x = 0;
	AH->mouse_y = 0;
	AH->move_x = 0;
	AH->move_y = 0;
}
