/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_xclient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 04:20:24 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/26 19:45:09 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_xparams	ft_init_xparams(int ***map)
{
	t_xparams	xparams;
	double		diagonal;
	int			tmp;

	xparams.map = map;
	xparams.width = ft_tab_size((void **) map[0]);
	xparams.height = ft_tab_size((void **) map);
	diagonal = sqrt(pow(xparams.width, 2) + pow(xparams.height, 2));
	xparams.basis = WIDTH / diagonal;
	tmp = HEIGHT / diagonal;
	if (tmp < xparams.basis)
		xparams.basis = tmp;
	ft_reset_xparams(&xparams);
	return (xparams);
}

t_xclient	*ft_new_xclient(int ***map)
{
	t_xclient	*xclient;

	xclient = malloc(sizeof(t_xclient));
	if (!xclient)
		return (NULL);
	xclient->mlx = NULL;
	xclient->win = NULL;
	xclient->ximage.img = NULL;
	xclient->xparams = ft_init_xparams(map);
	xclient->mlx = mlx_init();
	if (!(xclient->mlx))
		return (ft_free_xclient(xclient), NULL);
	xclient->win = mlx_new_window(xclient->mlx, WIDTH, HEIGHT, TITLE);
	if (!(xclient->win))
		return (ft_free_xclient(xclient), NULL);
	xclient->ximage = ft_init_ximage(xclient);
	if (!(xclient->ximage.img))
		return (ft_free_xclient(xclient), NULL);
	return (xclient);
}
