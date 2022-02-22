/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:39:41 by mkamei            #+#    #+#             */
/*   Updated: 2022/02/21 17:41:05 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"

static void	rotate_3d_x(double *y, double *z, const double theta)
{
	const double	oldy = *y;
	const double	oldz = *z;

	*y = oldy * cos(theta) - oldz * sin(theta);
	*z = oldy * sin(theta) + oldz * cos(theta);
}

static void	rotate_3d_y(double *x, double *z, const double phi)
{
	const double	oldx = *x;
	const double	oldz = *z;

	*x = oldx * cos(phi) + oldz * sin(phi);
	*z = -oldx * sin(phi) + oldz * cos(phi);
}

static void	rotate_3d_z(double *x, double *y, const double psi)
{
	const double	oldx = *x;
	const double	oldy = *y;

	*x = oldx * cos(psi) - oldy * sin(psi);
	*y = oldx * sin(psi) + oldy * cos(psi);
}

void	rotate_3d_object(
	t_p_3d *p_3ds, const int p_num, const t_axis axis, const double angle)
{
	int		i;

	i = 0;
	while (i < p_num)
	{
		if (axis == X)
			rotate_3d_x(&p_3ds[i].y, &p_3ds[i].z, angle);
		else if (axis == Y)
			rotate_3d_y(&p_3ds[i].x, &p_3ds[i].z, angle);
		else if (axis == Z)
			rotate_3d_z(&p_3ds[i].x, &p_3ds[i].y, angle);
		i++;
	}
}
