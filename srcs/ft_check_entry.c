/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_entry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 22:45:47 by jiglesia          #+#    #+#             */
/*   Updated: 2020/08/30 01:29:44 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_check_r(char *line)
{
	int i;

	i = 1;
	i += ft_skip(" ", &line[i]);
	if (*line[i] <= 48 || *line[i] >= 57)
		return (0);
	while (*line[i] >= 48 && *line[i] <= 57)
		i++;
	while (*line[i] && *line[i] == ' ')
		i++;
	if (*line[i] <= 48 || *line[i] >= 57)
		return (0);
	while (*line[i] >= 48 && *line[i] <= 57)
		i++;

}

int	ft_check_entry(int fd, char **line, int a)
{
	while (get_next_line(fd, line))
	{
		if (*line[0] == 'R')
			a = ft_check_r(*line);
		else if (*line[0] == 'A')
			a = ft_check_a(*line);
		else if (*line[0] == 'c')
			a = ft_check_c(line);
		else if (*line[0] == 'l')
			a = ft_check_l(line);
		else if (*line[0] == 's' && *line[1] == 'p')
			a = ft_check_sp(line);
		else if (*line[0] == 'p' && *line[1] == 'l')
			a = ft_check_pl(line);
		else if (*line[0] == 's' && *line[1] == 'q')
			a = ft_check_sq(line);
		else if (*line[0] == 'c' && *line[1] == 'y')
			a = ft_check_cy(line);
		else if (*line[0] == 't' && *line[1] == 'r')
			a = ft_check_tr(line);
		if (!a && *line[0] != '\0')
			return (0);
	}
	return (1);
}
