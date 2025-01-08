/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:03:05 by jonghan           #+#    #+#             */
/*   Updated: 2024/11/19 02:05:34 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	rgb_to_int(int r, int g, int b)
{
	int	color;

	color = r << 16 | g << 8 | b;
	return (color);
}

int	get_color(int iter, int seed)
{
	int		r;
	int		g;
	int		b;
	double	t;

	if (iter == MAX_ITER)
		return (rgb_to_int(0, 0, 0));
	t = (double)iter / MAX_ITER;
	r = (seed % 10) * t * 255;
	g = (seed % 100 / 10) * t * 255;
	b = (seed % 1000 / 100) * t * 255;
	return (rgb_to_int((int)r, (int)g, (int)b));
}
