/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:17:48 by dboudy            #+#    #+#             */
/*   Updated: 2016/01/08 13:11:32 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_trace_str(unsigned int i, char *str)
{
	ft_color("36");
	ft_putstr("trace str n°");
	ft_putnbr(i);
	ft_putstr(" = [");
	ft_putstr(str);
	ft_putstr("].\n");
	ft_color("37");
}
