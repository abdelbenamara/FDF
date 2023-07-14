/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_xclient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 04:20:24 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/14 02:39:29 by abenamar         ###   ########.fr       */
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

static size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

t_xclient	*ft_new_xclient(char ***map)
{
	const size_t	xpad = XSIZE / (ft_tab_size((void **) map[0]) * 2);
	const size_t	ypad = YSIZE / (ft_tab_size((void **) map) * 2);
	t_xclient		*xclient;

	xclient = malloc(sizeof(t_xclient));
	if (!xclient)
		return (NULL);
	xclient->mlx = NULL;
	xclient->win = NULL;
	xclient->ximage = NULL;
	xclient->mlx = mlx_init();
	if (!(xclient->mlx))
		return (ft_free_xclient(xclient), NULL);
	xclient->win = mlx_new_window(xclient->mlx, XSIZE, YSIZE, TITLE);
	if (!(xclient->win))
		return (ft_free_xclient(xclient), NULL);
	xclient->ximage = ft_new_ximage(xclient);
	if (!(xclient->ximage))
		return (ft_free_xclient(xclient), NULL);
	xclient->map = map;
	xclient->ppad = ft_min(xpad, ypad);
	xclient->ox = XSIZE / 2 - (XSIZE / (xpad * 4) * xclient->ppad);
	xclient->oy = YSIZE / 2 - (YSIZE / (ypad * 4) * xclient->ppad);
	return (xclient);
}
