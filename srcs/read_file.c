/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:54:47 by mkamei            #+#    #+#             */
/*   Updated: 2022/02/22 16:06:13 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"

static t_list	*create_lines_list_from_file(const char *file_path)
{
	int		fd;
	char	*line;
	int		gnl_status;
	t_list	dummy_head;
	t_list	*lines_list;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		exit_with_perrout("open");
	lines_list = &dummy_head;
	while (1)
	{
		gnl_status = get_next_line(fd, &line);
		if (gnl_status == -1)
			exit_with_perrout("gnl");
		lines_list->next = ft_lstnew(line);
		if (lines_list->next == NULL)
			exit_with_perrout("malloc");
		lines_list = lines_list->next;
		if (gnl_status == 0)
			break ;
	}
	if (close(fd) == -1)
		exit_with_perrout("close");
	return (dummy_head.next);
}

static int	get_p_num_from_lines(t_list *lines_list)
{
	int		p_num;
	t_list	*last;

	p_num = ft_lstsize(lines_list);
	last = ft_lstlast(lines_list);
	if (((char *)last->content)[0] == '\0' && last->next == NULL)
		p_num--;
	return (p_num);
}

static t_p_3d	parse_line_to_p_3d(const char *line)
{
	t_p_3d	p_3d;

	if (sscanf(line, "%lf,%lf,%lf", &p_3d.x, &p_3d.y, &p_3d.z) != 3)
		exit_with_errout("Invalid file");
	if (isinf(p_3d.x) || isinf(p_3d.y) || isinf(p_3d.z))
		exit_with_errout("Invalid file");
	if (ft_strchr(ft_strchr(line, ',') + 1, ',') != ft_strrchr(line, ','))
		exit_with_errout("Invalid file");
	return (p_3d);
}

static t_p_3d	*convert_lines_to_p_3d(t_list *lines_list, const int p_num)
{
	int		i;
	t_p_3d	*p_3ds;

	p_3ds = (t_p_3d *)malloc(sizeof(t_p_3d) * p_num);
	if (p_3ds == NULL)
		exit_with_perrout("malloc");
	i = 0;
	while (i < p_num)
	{
		p_3ds[i] = parse_line_to_p_3d(lines_list->content);
		lines_list = lines_list->next;
		i++;
	}
	return (p_3ds);
}

t_p_3d	*read_p_3d_from_file(const char *file_path, int *p_num)
{
	t_list	*lines_list;
	t_p_3d	*p_3ds;

	lines_list = create_lines_list_from_file(file_path);
	*p_num = get_p_num_from_lines(lines_list);
	p_3ds = convert_lines_to_p_3d(lines_list, *p_num);
	ft_lstclear(&lines_list, free);
	return (p_3ds);
}
