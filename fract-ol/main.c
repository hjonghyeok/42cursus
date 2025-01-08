/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:08:14 by jonghan           #+#    #+#             */
/*   Updated: 2024/11/19 00:34:39 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display_init(t_display *d, char **av)
{
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, WIDTH, HEIGHT, "display");
	if (!ft_strncmp(av[1], "m", 1))
		set_m(d);
	else if (!ft_strncmp(av[1], "j", 1))
		set_j(d, av);
	d->ymin = -1.5;
	d->ymax = 1.5;
	d->img = mlx_new_image(d->mlx, WIDTH, HEIGHT);
	d->addr = mlx_get_data_addr(d->img, &(d->bit), &(d->size), &(d->endian));
	d->fractal = av[1];
	d->color = 113;
	d->is_gray = 0;
	draw_fractal(d);
}

int	main(int ac, char **av)
{
	t_display	d;

	if (check_ar(ac, av))
		return (1);
	display_init(&d, av);
	mlx_mouse_hook(d.win, &mouse_event, &d);
	mlx_key_hook(d.win, &keyboard_event, &d);
	mlx_loop(d.mlx);
	return (0);
}
