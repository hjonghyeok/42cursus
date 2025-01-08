/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:50:49 by jonghan           #+#    #+#             */
/*   Updated: 2024/11/19 15:23:48 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	zoom_display(int flag, t_display *d, double x, double y)
{
	if (flag == MOUSE_WHELL_DOWN || flag == KEY_MINUS)
	{
		d->xmin = x + (d->xmin - x) / ZOOM;
		d->xmax = x + (d->xmax - x) / ZOOM;
		d->ymin = y + (d->ymin - y) / ZOOM;
		d->ymax = y + (d->ymax - y) / ZOOM;
	}
	else
	{
		d->xmin = x + (d->xmin - x) * ZOOM;
		d->xmax = x + (d->xmax - x) * ZOOM;
		d->ymin = y + (d->ymin - y) * ZOOM;
		d->ymax = y + (d->ymax - y) * ZOOM;
	}
}

void	move_display(int flag, t_display *d, double x, double y)
{
	if (flag == KEY_DOWN)
	{
		d->ymin = y + (d->ymin - y) + fabs(d->ymax - d->ymin) / 10;
		d->ymax = y + (d->ymax - y) + fabs(d->ymax - d->ymin) / 10;
	}
	else if (flag == KEY_UP)
	{
		d->ymin = y + (d->ymin - y) - fabs(d->ymax - d->ymin) / 10;
		d->ymax = y + (d->ymax - y) - fabs(d->ymax - d->ymin) / 10;
	}
	else if (flag == KEY_LEFT)
	{
		d->xmin = x + (d->xmin - x) - fabs(d->xmax - d->xmin) / 10;
		d->xmax = x + (d->xmax - x) - fabs(d->xmax - d->xmin) / 10;
	}
	else
	{
		d->xmin = x + (d->xmin - x) + fabs(d->xmax - d->xmin) / 10;
		d->xmax = x + (d->xmax - x) + fabs(d->xmax - d->xmin) / 10;
	}
}

void	keyboard_cmd(int key, t_display *d)
{
	if (key == KEY_MINUS || key == KEY_PLUS)
		zoom_display(key, d, (d->xmin + d->xmax) / 2, (d->ymin + d->ymax) / 2);
	if (key == KEY_DOWN || key == KEY_LEFT || \
		key == KEY_RIGHT || key == KEY_UP)
		move_display(key, d, (d->xmin + d->xmax) / 2, (d->ymin + d->ymax) / 2);
	if (key == KEY_G)
		d->is_gray = 1;
	else if (key == KEY_R)
		d->is_gray = 0;
	if (key == KEY_BONUS_1)
	{
		d->bonus_v.option = 1;
		d->xmax = 1.5;
		d->xmin = -1.5;
		d->ymax = 1.5;
		d->ymin = -1.5;
	}
	else if (key == KEY_BONUS_2)
	{
		d->bonus_v.option = 0;
		d->xmax = 1.5;
		d->xmin = -1.5;
		d->ymax = 1.5;
		d->ymin = -1.5;
	}
}

int	mouse_event(int button, int x, int y, t_display *d)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = d->xmin + (d->xmax - d->xmin) * x / WIDTH;
	mouse_y = d->ymin + (d->ymax - d->ymin) * y / HEIGHT;
	if (button == MOUSE_WHELL_UP || button == MOUSE_WHELL_DOWN)
		zoom_display(button, d, mouse_x, mouse_y);
	if (button == 3)
		d->color = (int)(long long)((mouse_x * mouse_y) * 999999999999999);
	draw_fractal(d);
	return (0);
}

int	keyboard_event(int key, t_display *d)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(d->mlx, d->win);
		if (d->mlx)
		{
			mlx_loop_end(d->mlx);
			mlx_destroy_image(d->mlx, d->img);
			mlx_destroy_display(d->mlx);
			free(d->mlx);
		}
		ft_printf("exit\n");
		exit(0);
	}
	keyboard_cmd(key, d);
	draw_fractal(d);
	return (0);
}
