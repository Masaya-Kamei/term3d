/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:32:37 by mkamei            #+#    #+#             */
/*   Updated: 2022/02/22 11:48:38 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"

static t_p_3d	get_object_center(t_p_3d *p_3ds, const int p_num)
{
	int		i;
	t_p_3d	sum;
	t_p_3d	obj_center;

	i = 0;
	sum.x = 0;
	sum.y = 0;
	sum.z = 0;
	while (i < p_num)
	{
		sum.x += p_3ds[i].x;
		sum.y += p_3ds[i].y;
		sum.z += p_3ds[i].z;
		i++;
	}
	obj_center.x = sum.x / p_num;
	obj_center.y = sum.y / p_num;
	obj_center.z = sum.z / p_num;
	return (obj_center);
}

static void	move_object_to_origin(t_p_3d *p_3ds, const int p_num)
{
	int				i;
	const t_p_3d	obj_center = get_object_center(p_3ds, p_num);

	i = 0;
	while (i < p_num)
	{
		p_3ds[i].x -= obj_center.x;
		p_3ds[i].y -= obj_center.y;
		p_3ds[i].z -= obj_center.z;
		i++;
	}
}

static double	get_max_distance_of_p_3d(t_p_3d *p_3ds, const int p_num)
{
	int		i;
	double	max_dist;
	double	d;

	i = 0;
	max_dist = 0;
	while (i < p_num)
	{
		d = sqrt(pow(p_3ds[i].x, 2) + pow(p_3ds[i].y, 2) + pow(p_3ds[i].z, 2));
		if (max_dist < d)
			max_dist = d;
		i++;
	}
	return (max_dist);
}

static void	scale_object(t_p_3d *p_3ds, const int p_num)
{
	int				i;
	const double	max_dist = get_max_distance_of_p_3d(p_3ds, p_num);
	const double	new_max_dist = fmin(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2);

	i = 0;
	while (i < p_num)
	{
		p_3ds[i].x = (p_3ds[i].x / max_dist) * new_max_dist;
		p_3ds[i].y = (p_3ds[i].y / max_dist) * new_max_dist;
		p_3ds[i].z = (p_3ds[i].z / max_dist) * new_max_dist;
		p_3ds[i].x *= Z_RANGE;
		p_3ds[i].y *= Z_RANGE;
		p_3ds[i].z *= Z_RANGE;
		p_3ds[i].x *= ZOOM_IN_ADDITION;
		p_3ds[i].y *= ZOOM_IN_ADDITION;
		p_3ds[i].z *= ZOOM_IN_ADDITION;
		i++;
	}
}

void	init_object(t_p_3d *p_3ds, const int p_num)
{
	move_object_to_origin(p_3ds, p_num);
	scale_object(p_3ds, p_num);
	rotate_3d_object(p_3ds, p_num, X, INIT_ROTATE_X);
	rotate_3d_object(p_3ds, p_num, Y, INIT_ROTATE_Y);
	rotate_3d_object(p_3ds, p_num, Z, INIT_ROTATE_Z);
}
