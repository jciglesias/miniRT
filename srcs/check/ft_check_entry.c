/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_entry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 22:45:47 by jiglesia          #+#    #+#             */
/*   Updated: 2020/09/12 19:05:42 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*ft_check_elem(char *line)
{
	if (!line)
		return (0);
	if (line[0] == 'R')
		return ("R");
	else if (line[0] == 'A')
		return ("A");
	else if (line[0] == 'c' && line[1] == 'y')
		return ("cy");
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
	else if (line[0] == 't' && line[1] == 'r')
		return ("tr");
	else
		return (NULL);
}

int		ft_check_line(char *elem, char *line)
{
	if (elem == NULL)
		return (0);
	else if (!ft_strncmp(elem, "R", 1))
		return (ft_check_r(line));
	else if (!ft_strncmp(elem, "A", 1))
		return (ft_check_a(line));
	else if (!ft_strncmp(elem, "cy", 2))
		return (ft_check_cy(line));
	else if (!ft_strncmp(elem, "c", 1))
		return (ft_check_c(line));
	else if (!ft_strncmp(elem, "l", 1))
		return (ft_check_l(line));
	else if (!ft_strncmp(elem, "sp", 2))
		return (ft_check_sp(line));
	else if (!ft_strncmp(elem, "pl", 2))
		return (ft_check_pl(line));
	else if (!ft_strncmp(elem, "sq", 2))
		return (ft_check_sq(line));
	else
		return (ft_check_tr(line));
}

int		ft_wrongline(char *sms, char **line, char **bowl)
{
	if (line)
		free(*line);
	if (bowl)
		free(*bowl);
	return (ft_puterror(sms, 0));
}

int		ft_check_entry(int fd, char *line, int r, int a)
{
	char	*elem;
	char	**bowl;
	int		i;

	i = 1;
	elem = NULL;
	while ((bowl = get_next_line(fd, &line)) || i--)
	{
		elem = ft_check_elem(line);
		if (elem[0] && elem[0] == 'R')
			r++;
		if (elem[0] && elem[0] == 'A')
			a++;
		if (a > 1 || r > 1)
			return (ft_wrongline("Error\ntoo many A or R", &line, bowl));
		if (!ft_check_line(elem, line))
			return (ft_wrongline("", &line, bowl));
	}
	free(line);
	return (1);
}
