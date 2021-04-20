/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_entry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 22:45:47 by jiglesia          #+#    #+#             */
/*   Updated: 2021/04/20 17:16:47 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*ft_check_elem(char *line)
{
	if (!line)
		return (0);
	if (line[0] == 'R' && line[1] == ' ')
		return ("R");
	else if (line[0] == 'A' && line[1] == ' ')
		return ("A");
	else if (line[0] == 'c' && line[1] == 'y' && line[2] == ' ')
		return ("cy");
	else if (line[0] == 'c' && line[1] == ' ')
		return ("c");
	else if (line[0] == 'l' && line[1] == ' ')
		return ("l");
	else if (line[0] == 's' && line[1] == 'p' && line[2] == ' ')
		return ("sp");
	else if (line[0] == 'p' && line[1] == 'l' && line[2] == ' ')
		return ("pl");
	else if (line[0] == 's' && line[1] == 'q' && line[2] == ' ')
		return ("sq");
	else if (line[0] == 't' && line[1] == 'r' && line[2] == ' ')
		return ("tr");
	else
		return ("\0");
}

int		ft_check_line(char *elem, char *line)
{
	if (elem[0] == '\0')
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
	ft_puterror("Error\nWrong element in line\n", 0);
	ft_puterror(sms, 0);
	ft_putchar_fd('\n', 2);
	if (line)
		free(*line);
	if (bowl)
		free(*bowl);
	return (0);
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
		if (line && ft_strlen(line))
		{
			elem = ft_check_elem(line);
			if (elem[0] && elem[0] == 'R')
				r++;
			if (elem[0] && elem[0] == 'A')
				a++;
			if (a > 1 || r > 1)
				return (ft_wrongline("Error\ntoo many A or R\n", &line, bowl));
			if (!ft_check_line(elem, line))
				return (ft_wrongline(line, &line, bowl));
		}
		free(line);
		line = NULL;
	}
	free(line);
	return (1);
}
