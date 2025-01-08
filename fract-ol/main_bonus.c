/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:56:52 by jonghan           #+#    #+#             */
/*   Updated: 2024/11/19 00:34:05 by jonghan          ###   ########.fr       */
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
	else if (!ft_strncmp(av[1], "b", 1))
		set_b(d, av);
	d->ymin = -1.5;
	d->ymax = 1.5;
	d->img = mlx_new_image(d->mlx, WIDTH, HEIGHT);
	d->addr = mlx_get_data_addr(d->img, &(d->bit), &(d->size), &(d->endian));
	d->fractal = av[1];
	d->color = 113;
	d->is_gray = 0;
}

int	main(int ac, char **av)
{
	t_display	d;

	if (check_ar(ac, av))
		return (1);
	display_init(&d, av);
	draw_fractal(&d);
	mlx_mouse_hook(d.win, &mouse_event, &d);
	mlx_key_hook(d.win, &keyboard_event, &d);
	mlx_loop(d.mlx);
	return (0);
}
