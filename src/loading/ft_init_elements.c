/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 19:41:22 by jiglesia          #+#    #+#             */
/*   Updated: 2020/09/12 20:52:20 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cam		*ft_init_cam(void)
{
	t_cam *cam;

	if (!(cam = (t_cam *)malloc(sizeof(t_cam))))
		return (NULL);
	ft_init_double(3, cam->xyz);
	ft_init_double(3, cam->vec);
	cam->fov = 0;
	cam->next = NULL;
	return (cam);
}

t_light		*ft_init_l(void)
{
	t_light *light;

	if (!(light = (t_light *)malloc(sizeof(t_light))))
		return (NULL);
	ft_init_double(3, light->xyz);
	light->bri = 0.;
	ft_init_int(3, light->rgb);
	light->next = NULL;
	return (light);
}

t_sphere	*ft_init_sp(void)
{
	t_sphere *sphere;

	if (!(sphere = (t_sphere *)malloc(sizeof(t_sphere))))
		return (NULL);
	ft_init_double(3, sphere->xyz);
	sphere->d = 0.;
	ft_init_int(3, sphere->rgb);
	sphere->next = NULL;
	return (sphere);
}

t_plane		*ft_init_pl(void)
{
	t_plane *plane;

	if (!(plane = (t_plane *)malloc(sizeof(t_plane))))
		return (NULL);
	ft_init_double(3, plane->xyz);
	ft_init_double(3, plane->vec);
	ft_init_int(3, plane->rgb);
	plane->next = NULL;
	return (plane);
}
