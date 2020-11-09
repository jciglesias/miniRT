/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mallotrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:19:44 by jiglesia          #+#    #+#             */
/*   Updated: 2020/11/09 15:18:33 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	**ft_mallotrix(int **bmp)
{
	int	i;

	i = 0;
	if (!(bmp = (int **)malloc(sizeof(int *) * S.res[1])))
		return (NULL);
	while (i < S.res[1])
	{
		if (!(bmp[i] = (int *)malloc(sizeof(int) * S.res[0])))
			return (NULL);
		ft_bzero(bmp[i++], sizeof(int) * S.res[0]);
	}
	return (bmp);
}
