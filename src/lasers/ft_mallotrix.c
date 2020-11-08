/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mallotrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:19:44 by jiglesia          #+#    #+#             */
/*   Updated: 2020/11/08 20:28:36 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_mallotrix(int **bmp)
{
	int	i;

	i = 0;
	if (!(bmp = (int **)malloc(sizeof(int *) * S.res[1])))
		return ;
	while (i < S.res[0])
	{
		if (!(bmp[i] = (int *)malloc(sizeof(int) * S.res[0])))
			return ;
		ft_bzero(bmp[i++], sizeof(int) * S.res[1]);
	}
}
