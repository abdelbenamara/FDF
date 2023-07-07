/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_xclient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 04:20:24 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/07 02:11:29 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_xclient	*ft_new_xclient(char ***map)
{
	t_xclient	*xclient;

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
	xclient->ox = 0;
	xclient->oy = 0;
	return (xclient);
}
