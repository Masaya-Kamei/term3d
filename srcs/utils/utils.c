/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:44:51 by mkamei            #+#    #+#             */
/*   Updated: 2022/02/25 11:48:42 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"

double	get_min_distance_from_canvas_center_to_frame(void)
{
	const double	min_dist_width = CANVAS_WIDTH / (2 * TERMINAL_CHAR_Y_PER_X);
	const double	min_dist_height = CANVAS_HEIGHT / 2;

	return (fmin(min_dist_width, min_dist_height));
}
