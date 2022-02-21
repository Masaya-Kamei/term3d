/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:12:37 by mkamei            #+#    #+#             */
/*   Updated: 2022/02/21 16:34:56 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"

int	main(int argc, char **argv)
{
	t_p_3d	*p_3ds;
	int		p_num;

	if (argc != 2)
		exit_with_errout("Invalid arguments");
	p_3ds = read_p_3d_from_file(argv[1], &p_num);
	print_p_3d(p_3ds, p_num);
	// loop_draw_object(p_3ds, p_num);
	free(p_3ds);
	return (0);
}
