/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:03:44 by jonghan           #+#    #+#             */
/*   Updated: 2024/11/19 22:07:46 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	get_iter(t_display *d, t_complex *c)
{
	if (d->julia)
		return (iter_count_j(*c, *d));
	if (d->bonus)
	{
		if (d->bonus_v.option)
			return (iter_count_b(*c, *d));
		else
			return (iter_count_b2(*c));
	}
	return (iter_count_m(*c));
}

void	draw_color(t_display *d, t_complex *c, int x, int y)
{
	int	iter;
	int	p_idx;

	iter = get_iter(d, c);
	p_idx = (y * d->size) + (x * (d->bit / 8));
	if (d->is_gray)
	{
		iter = (int)((double)iter / MAX_ITER * 255);
		d->addr[p_idx + 0] = iter;
		d->addr[p_idx + 1] = iter;
		d->addr[p_idx + 2] = iter;
	}
	else
	{
		d->addr[p_idx + 0] = get_color(iter, d->color) & 255;
		d->addr[p_idx + 1] = (get_color(iter, d->color) >> 8) & 255;
		d->addr[p_idx + 2] = (get_color(iter, d->color) >> 16) & 255;
	}
}

void	draw_fractal(t_display *d)
{
	t_complex	c;
	int			y;
	int			x;

	y = -1;
	while (++y < HEIGHT)
	{
		c.y = d->ymin + (d->ymax - d->ymin) * y / HEIGHT;
		x = -1;
		while (++x < WIDTH)
		{
			c.x = d->xmin + (d->xmax - d->xmin) * x / WIDTH;
			draw_color(d, &c, x, y);
		}
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}
