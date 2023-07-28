/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_xclient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 04:20:24 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/29 01:22:31 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static size_t	ft_map_width(int ***map)
{
	size_t	i;
	size_t	w1;
	size_t	w2;

	if (!(map[0]))
		return (0);
	i = 0;
	w1 = 0;
	while (map[i])
	{
		w2 = ft_tab_size((void **) map[i]);
		if (w2 > w1)
			w1 = w2;
		++i;
	}
	i = 0;
	while (map[i])
	{
		w2 = ft_tab_size((void **) map[i]);
		if (w1 - w2 > 1)
			return (0);
		++i;
	}
	return (w1);
}

static t_xparams	ft_init_xparams(int ***map)
{
	t_xparams	xparams;
	double		diagonal;
	int			tmp;

	xparams.map = map;
	xparams.width = ft_map_width(map);
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
	if (!(xclient->xparams.width))
		return (ft_free_xclient(xclient), NULL);
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
