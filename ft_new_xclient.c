/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_xclient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 04:20:24 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/18 20:15:24 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static size_t	ft_tab_size(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		++i;
	return (i);
}

static t_xparams	ft_init_xparams(char ***map)
{
	t_xparams	xparams;

	xparams.map = map;
	xparams.width = ft_tab_size((void **) map[0]);
	xparams.height = ft_tab_size((void **) map);
	xparams.wpad = WIDTH / (xparams.width * 2);
	xparams.hpad = HEIGHT / (xparams.height * 2);
	xparams.padding = xparams.wpad;
	if (xparams.wpad > xparams.hpad)
		xparams.padding = xparams.hpad;
	xparams.zoom = xparams.padding;
	xparams.origin.x = WIDTH / 2;
	xparams.origin.y = HEIGHT / 2;
	return (xparams);
}

t_xclient	*ft_new_xclient(char ***map)
{
	t_xclient	*xclient;

	xclient = malloc(sizeof(t_xclient));
	if (!xclient)
		return (NULL);
	xclient->mlx = NULL;
	xclient->win = NULL;
	xclient->ximage.img = NULL;
	xclient->mlx = mlx_init();
	if (!(xclient->mlx))
		return (ft_free_xclient(xclient), NULL);
	xclient->win = mlx_new_window(xclient->mlx, WIDTH, HEIGHT, TITLE);
	if (!(xclient->win))
		return (ft_free_xclient(xclient), NULL);
	xclient->xparams = ft_init_xparams(map);
	xclient->ximage = ft_init_ximage(xclient);
	if (!(xclient->ximage.img))
		return (ft_free_xclient(xclient), NULL);
	return (xclient);
}
