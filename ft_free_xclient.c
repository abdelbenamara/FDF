/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_xclient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 04:19:41 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/06 23:04:29 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_xclient(t_xclient *xclient)
{
	if (xclient->ximage)
		ft_free_ximage(xclient->ximage);
	if (xclient->win)
		mlx_destroy_window(xclient->mlx, xclient->win);
	if (xclient->mlx)
		(mlx_destroy_display(xclient->mlx), free(xclient->mlx));
	free(xclient);
}
