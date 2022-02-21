/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:11:59 by mkamei            #+#    #+#             */
/*   Updated: 2022/02/21 16:19:19 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM3D_H
# define TERM3D_H

# include "libft.h"
# include <stdbool.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

# define GNL_BUFFER_SIZE 1000
# define PI 3.141592653589793
# define CANVAS_WIDTH 80
# define CANVAS_HEIGHT 40
// # define X_PER_Y 2.5

typedef struct s_p_3d
{
	double		x;
	double		y;
	double		z;
}				t_p_3d;

t_p_3d	*read_p_3d_from_file(const char *file_path, int *p_num);

// utils
int		get_next_line(int fd, char **line);
void	exit_with_errout(const char *errmsg);
void	exit_with_perrout(const char *str);
void	print_p_3d(t_p_3d *p_3ds, const int p_num);

#endif
