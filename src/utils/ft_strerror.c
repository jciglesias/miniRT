/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strerror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 23:01:55 by jiglesia          #+#    #+#             */
/*   Updated: 2020/09/12 18:34:46 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_strerror(char *str, int a, char **line)
{
	int	i;

	i = ft_strlen(str);
	i = write(2, str, i);
	i = 0;
	while (line[i])
	{
		free(line[i]);
		line[i++] = NULL;
	}
	free(line);
	return (a);
}
