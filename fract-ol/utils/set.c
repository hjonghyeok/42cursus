/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghan <jonghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:49:11 by jonghan           #+#    #+#             */
/*   Updated: 2024/11/19 01:46:46 by jonghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	set_m(t_display *d)
{
	d->xmin = -2.2;
	d->xmax = 0.8;
	d->julia = 0;
	d->bonus = 0;
}

void	set_j(t_display *d, char **av)
{
	d->xmin = -1.5;
	d->xmax = 1.5;
	d->julia_v.x = ft_atod(av[2]);
	d->julia_v.y = ft_atod(av[3]);
	d->julia = 1;
	d->bonus = 0;
}

void	set_b(t_display *d, char **av)
{
	d->xmin = -1.5;
	d->xmax = 1.5;
	d->bonus_v.zn = ft_atoi(av[2]);
	d->bonus_v.cn = ft_atoi(av[3]);
	d->julia = 0;
	d->bonus = 1;
	d->bonus_v.option = 1;
}
