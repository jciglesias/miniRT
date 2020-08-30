/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_entry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 22:45:47 by jiglesia          #+#    #+#             */
/*   Updated: 2020/08/30 18:44:48 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*ft_check_elem(char *line)
{
	if (line[0] == 'R')
		return ("R");
	else if (line[0] == 'A')
		return ("A");
	else if (line[0] == 'c')
		return ("c");
	else if (line[0] == 'l')
		return ("l");
	else if (line[0] == 's' && line[1] == 'p')
		return ("sp");
	else if (line[0] == 'p' && line[1] == 'l')
		return ("pl");
	else if (line[0] == 's' && line[1] == 'q')
		return ("sq");
	else if (line[0] == 'c' && line[1] == 'y')
		return ("cy");
	else if (line[0] == 't' && line[1] == 'r')
		return ("tr");
	else
		return (NULL);
}

int		ft_check_line(char *elem, char *line)
{
	if (elem == NULL)
		return (0);
	else if (elem == "R")
		return (ft_check_r(line));
	else if (elem == "A")
		return (ft_check_a(line));
	else if (elem == "c")
		return (ft_check_c(line));
	else if (elem == "l")
		return (ft_check_l(line));
	else if (elem == "sp")
		return (ft_check_sp(line));
	else if (elem == "pl")
		return (ft_check_pl(line));
	else if (elem == "sq")
		return (ft_check_sq(line));
	else if (elem == "cy")
		return (ft_check_cy(line));
	else
		return (ft_check_tr(line));
}

int		ft_check_entry(int fd, char **line, int v)
{
	char	*elem;
	int		r;
	int		a;

	r = 0;
	a = 0;
	while (get_next_line(fd, line))
	{
		elem = ft_check_elem(*line);
		if (elem == "R")
			r++;
		if (elem == "A")
			a++;
		if (a > 1 || r > 1)
			return (0);
		if (!ft_check_line(elem, *line))
			return (0);
	}
	return (1);
}
